//对Teacher结构体进行封装，封装成TLV格式的数据，就可以跨平台传输了
//对端拿到数据后，再进行解码，就可以拿到原来的Teacher结构体

#include"itcast_asn1_der.h"
#include"der_teacher.h"
#include<stdlib.h>

//对教师结构体进行编码
int TeacherEncode(Teacher *pTeacher, unsigned char **out, int *outlen)
{
	int ret = 0;
	ITCAST_ANYBUF *pTmp = NULL,*pHeadBuf = NULL;
	ITCAST_ANYBUF *pTmpBuf = NULL;	//char*转换成ITCAST_ANYBUF，放在这里
	ITCAST_ANYBUF *pOutData = NULL;
	unsigned char *tmpout = NULL;
	int tmpoutlen = 0;

	/*
	  将char*类型的name转化成ITCAST_ANYBUF类型，这步并没有进行TLV格式转换，也就是没有编码
	  看源码可以发现，实际上就是将pTeacher->name指向的内存空间，拷贝给了pTmpBuf->pData指向的
	  内存空间，strlen(pTeacher->name)赋值给了pTmpBuf->dataLen
	*/
	ret = DER_ITCAST_String_To_AnyBuf(&pTmpBuf, pTeacher->name, strlen(pTeacher->name));
	if (ret != 0)
	{
		printf("DER_ITCAST_String_To_AnyBuf error：%d\n", ret);	//也可以将错误写进日志
		return ret;
	}

	//对name进行编码
	ret = DER_ItAsn1_WritePrintableString(pTmpBuf, &pHeadBuf);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pTmpBuf);
		printf("DER_ItAsn1_WritePrintableString error：%d\n", ret);
		return ret;
	}

	DER_ITCAST_FreeQueue(pTmpBuf);	//释放pHeadBuf指向的内存空间，pHeadBuf的值并不改变

	pTmp = pHeadBuf;

	//对age进行编码
	ret = DER_ItAsn1_WriteInteger(pTeacher->age, &pTmp->next);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pHeadBuf);
		printf("DER_ItAsn1_WriteInteger error：%d\n", ret);
		return ret;
	}

	pTmp = pTmp->next;

	//对p进行编码
	ret = EncodeChar(pTeacher->p, pTeacher->plen, &pTmp->next);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pHeadBuf);
		printf("EncodeChar error：%d\n", ret);
		return ret;
	}
	pTmp = pTmp->next;

	//对plen进行编码
	ret = DER_ItAsn1_WriteInteger(pTeacher->plen, &pTmp->next);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pHeadBuf);
		printf("DER_ItAsn1_WriteInteger plen error：%d\n", ret);
		return ret;
	}

	//编码大结构体
	DER_ItAsn1_WriteSequence(pHeadBuf, &pOutData);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(pHeadBuf);
		printf("DER_ItAsn1_WriteSequence error：%d\n", ret);
		return ret;
	}

	//编码后以字符串的形式传出
	*out = (unsigned char*)malloc(pOutData->pData);	
	if (*out == NULL)
	{
		ret = ITDER_MemoryErr;
		DER_ITCAST_FreeQueue(pOutData);
		printf("malloc(pOutData->pData) error：%d\n", ret);
		return ITDER_MemoryErr;
	}
	memcpy(*out, pOutData->pData, pOutData->dataLen);

	*outlen = pOutData->dataLen;

	DER_ITCAST_FreeQueue(pOutData);

	return ret;
}

int TeacherDecode(unsigned char *indata, int inLen, Teacher **pStruct)
{
	int ret = 0;
	ITCAST_ANYBUF *pTmp = NULL, *pHead = NULL;
	ITCAST_ANYBUF *pOutData = NULL;
	ITCAST_ANYBUF *tmpAnyBuf = NULL;
	Teacher *pStrTeacher = NULL;

	//转码DER报文，将unsigned char *转换成ITCAST_ANYBUF
	ret = DER_ITCAST_String_To_AnyBuf(&tmpAnyBuf, indata, inLen);
	if (ret != 0)
	{
		printf("Decode DER_ITCAST_String_To_AnyBuf：%d\n", ret);
		return ret;
	}

	//解码大结构体
	ret = DER_ItAsn1_ReadSequence(tmpAnyBuf, &pHead);
	if (ret != 0)
	{
		DER_ITCAST_FreeQueue(tmpAnyBuf);
		printf("Decode DER_ItAsn1_ReadSequence：%d\n", ret);
		return ret;
	}
	DER_ITCAST_FreeQueue(tmpAnyBuf);

	//给Teacher结构体malloc空间
	pStrTeacher = (Teacher*)malloc(sizeof(Teacher));
	if (pStrTeacher == NULL)
	{
		DER_ITCAST_FreeQueue(pHead);
		ret == -1;
		printf("Teacher malloc error:%d\n", ret);
		return ret;
	}
	memset(pStrTeacher, 0, sizeof(Teacher));

	pTmp = pHead;

	//解码name
	ret = DER_ItAsn1_ReadPrintableString(pTmp, &pOutData);
	if (ret != 0)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		printf("Decode DER_ItAsn1_ReadPrintableString name：%d\n", ret);
		return ret;
	}

	memcpy(pStrTeacher->name, pOutData->pData, pOutData->dataLen);
	//也可以strcpy(pStructTeacher->name,pOutData->pData);

	pTmp = pTmp->next;

	//解码age
	DER_ItAsn1_ReadInteger(pTmp, &pStrTeacher->age);
	if (ret != 0)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		printf("Decode DER_ItAsn1_ReadInteger age：%d\n", ret);
		return ret;
	}

	pTmp = pTmp->next;

	//解码p
	ret = DER_ItAsn1_ReadPrintableString(pTmp, &pOutData);
	if (ret != 0)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		printf("Decode DER_ItAsn1_ReadPrintableString p：%d\n", ret);
		return ret;
	}

	//给Teacher结构体中的p指针开辟空间
	//pStrTeacher->p = malloc(pOutData->dataLen + 1);
	//if (pStrTeacher->p == NULL)
	//{
	//	freeTeacher(&pStrTeacher);
	//	DER_ITCAST_FreeQueue(pHead);
	//	ret == -1;
	//	printf("Teacher->p malloc error:%d\n", ret);
	//	return ret;
	//}

	pStrTeacher->p = malloc(pOutData->dataLen);
	if (pStrTeacher->p == NULL)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		ret == -1;
		printf("Teacher->p malloc error:%d\n", ret);
		return ret;
	}

	memcpy(pStrTeacher->p, pOutData->pData, pOutData->dataLen);

	pTmp = pTmp->next;

	//解码plen
	DER_ItAsn1_ReadInteger(pTmp, &pStrTeacher->plen);
	if (ret != 0)
	{
		freeTeacher(&pStrTeacher);
		DER_ITCAST_FreeQueue(pHead);
		printf("Decode DER_ItAsn1_ReadInteger plen：%d\n", ret);
		return ret;
	}
	*pStruct = pStrTeacher;
	return 0;
}

void freeTeacher(Teacher** pTeacher)	//也可以void freeTeacher(Teacher* pTeacher)
{
	if (pTeacher == NULL)
		return;

	if (pTeacher != NULL)
	{
		if ((*pTeacher)->p != NULL)
		{
			free((*pTeacher)->p);
			(*pTeacher)->p == NULL;
		}

		free(*pTeacher);
		*pTeacher = NULL;
	}
}