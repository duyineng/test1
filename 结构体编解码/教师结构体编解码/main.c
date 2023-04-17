#include"der_teacher.h"
#include"itcast_asn1_der.h"
#include"itcastderlog.h"
#include<stdlib.h>
#include<stdio.h>

int main0()
{
	//char a=10;
	//long long b = 170;
	//itasn1_integer *pa,*pb;
	//int paa=0;
	//der_itasn1_writeinteger(a, &pa);
	//der_itasn1_writeinteger(b, &pb);
	//printf("pdata=%d,sizeof(pdata)=%d,datalen=%d,datatype=%d\n", pa->pdata,sizeof(pa->pdata),pa->datalen,pa->datatype);
	//printf("pdata=%d,sizeof(pdata)=%d,datalen=%d,datatype=%d\n", pb->pdata, sizeof(pb->pdata), pb->datalen, pb->datatype);
	//der_itasn1_readinteger(pb, &paa);
	//printf("paa=%d", paa);

	
	char *p = malloc(64);
	strcpy(p,"abc");
	printf("sizeof  p =%d\n", sizeof(p));


	return 0;
}

int main()
{
	
	int ret = 0;
	Teacher t1;
	
	unsigned char* myOut = NULL;
	int myOutlen = 0;

	strcpy(t1.name, "dyn-name");
	t1.age = 10;
	t1.p = malloc(64);
	strcpy(t1.p, "dyn-info");
	t1.plen = strlen(t1.p);	//此时plen=9，\0也有赋值过去，也算上了大小

	TeacherEncode(&t1, &myOut, &myOutlen);


	Teacher* pt2 = NULL;
	TeacherDecode(myOut, myOutlen, &pt2);

	if ( (strcmp(t1.name, pt2->name) == 0) && (memcmp(t1.p, pt2->p, pt2->plen) == 0)
		&&(t1.age==pt2->age))
	{
		printf("编码等于解码\n");
	}
	else
	{
		printf("编码不等解码\n");
	}

	freeTeacher(&pt2);

	printf("hello...\n");
	system("pause");

	return 0;
}