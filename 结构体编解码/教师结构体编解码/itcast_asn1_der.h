#ifndef _ITCAST_MESSAGE_DER_
#define _ITCAST_MESSAGE_DER_

#ifdef __cplusplus
extern "C" {
#endif

#define ITCASTDER_NoErr 0 

//以下宏定义，为的是方便修改和移植
typedef int					ITCAST_INT ;
typedef unsigned char       ITCAST_UINT8;
typedef unsigned short      ITCAST_UINT16;
typedef unsigned long		ITCAST_UINT32;
typedef signed long         ITCAST_SINT32;

#define  TRUE  1
#define  FALSE 0


#define    ITDER_NoErr                    0	
#define    ITDER_MemoryErr                200
#define	   ITDER_LengthErr                201
#define	   ITDER_LengthNotEqualErr        202
#define	   ITDER_DataRangeErr             203
#define	   ITDER_InvalidTagErr            204



/* 
   The ID's for universal tag numbers 0-31.  Tag number 0 is reserved for
   encoding the end-of-contents value when an indefinite-length encoding
   is used 
   这个枚举是函数内部使用的，一般我们调用的人，不会用到
   */
enum {
        
	    ITCAST_DER_ID_RESERVED,
		ITCAST_DER_ID_BOOLEAN, 
		ITCAST_DER_ID_INTEGER,
		ITCAST_DER_ID_BITSTRING,
		ITCAST_DER_ID_OCTETSTRING,
		ITCAST_DER_ID_NULL,
		ITCAST_DER_ID_OBJECT_IDENTIFIER,
		ITCAST_DER_ID_OBJECT_DESCRIPTOR,
		ITCAST_DER_ID_EXTERNAL,
		ITCAST_DER_ID_REAL,
		ITCAST_DER_ID_ENUMERATED, 
		ITCAST_DER_ID_EMBEDDED_PDV, 
		ITCAST_DER_ID_STRING_UTF8, 
		ITCAST_DER_ID_13,
		ITCAST_DER_ID_14, 
		ITCAST_DER_ID_15, 
		ITCAST_DER_ID_SEQUENCE, 
		ITCAST_DER_ID_SET,
		ITCAST_DER_ID_STRING_NUMERIC, 
		ITCAST_DER_ID_STRING_PRINTABLE, 
		ITCAST_DER_ID_STRING_T61,
		ITCAST_DER_ID_STRING_VIDEOTEX, 
		ITCAST_DER_ID_STRING_IA5, 
		ITCAST_DER_ID_TIME_UTC,
		ITCAST_DER_ID_TIME_GENERALIZED, 
		ITCAST_DER_ID_STRING_GRAPHIC, 
		ITCAST_DER_ID_STRING_ISO646,
		ITCAST_DER_ID_STRING_GENERAL, 
		ITCAST_DER_ID_STRING_UNIVERSAL, 
		ITCAST_DER_ID_29,
		ITCAST_DER_ID_STRING_BMP
		
		};


/* Whether the encoding is constructed or primitive */

#define ITCAST_DER_CONSTRUCTED			    0x20
#define ITCAST_DER_PRIMITIVE			    0x00

/* The encodings for the universal types */
#define ITCAST_DER_UNIVERSAL			    0x00
#define ITCAST_DER_APPLICATION		   	    0x40
#define ITCAST_DER_CONTEXT_SPECIFIC	        0x80
#define ITCAST_DER_PRIVATE				    0xC0

#define ITCAST_DER_RESERVED		      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_RESERVED )
#define ITCAST_DER_BOOLEAN			  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_BOOLEAN )
#define ITCAST_DER_INTEGER			  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_INTEGER )
#define ITCAST_DER_BITSTRING		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_BITSTRING )
#define ITCAST_DER_OCTETSTRING		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_OCTETSTRING )
#define ITCAST_DER_NULL			      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_NULL )
#define ITCAST_DER_OBJECT_IDENTIFIER  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_OBJECT_IDENTIFIER )
#define ITCAST_DER_OBJECT_DESCRIPTOR  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_OBJECT_DESCRIPTOR )
#define ITCAST_DER_EXTERNAL		      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_EXTERNAL )
#define ITCAST_DER_REAL			      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_REAL )
#define ITCAST_DER_ENUMERATED		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_ENUMERATED )
#define ITCAST_DER_EMBEDDED_PDV	      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_EMBEDDED_PDV )
#define ITCAST_DER_STRING_UTF8		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_UTF8 )
#define ITCAST_DER_13				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_13 )
#define ITCAST_DER_14				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_14 )
#define ITCAST_DER_15				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_15 )
#define ITCAST_DER_SEQUENCE		      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_CONSTRUCTED | ITCAST_DER_ID_SEQUENCE )
#define ITCAST_DER_SET				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_CONSTRUCTED | ITCAST_DER_ID_SET )
#define ITCAST_DER_STRING_NUMERIC	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_NUMERIC )
#define ITCAST_DER_STRING_PRINTABLE   ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_PRINTABLE )
#define ITCAST_DER_STRING_T61		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_T61 )
#define ITCAST_DER_STRING_VIDEOTEX	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_VIDEOTEX )
#define ITCAST_DER_STRING_IA5		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_IA5 )
#define ITCAST_DER_TIME_UTC		      ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_TIME_UTC )
#define ITCAST_DER_TIME_GENERALIZED   ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_TIME_GENERALIZED )
#define ITCAST_DER_STRING_GRAPHIC	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_GRAPHIC )
#define ITCAST_DER_STRING_ISO646	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_ISO646 )
#define ITCAST_DER_STRING_GENERAL	  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_GENERAL )
#define ITCAST_DER_STRING_UNIVERSAL   ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_UNIVERSAL )
#define ITCAST_DER_29				  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_BER29 )
#define ITCAST_DER_STRING_BMP		  ( ITCAST_DER_UNIVERSAL | ITCAST_DER_PRIMITIVE | ITCAST_DER_ID_STRING_BMP )


/* Masks to extract information from a tag number */

#define ITCAST_DER_CLASS_MASK			0xC0
#define ITCAST_DER_CONSTRUCTED_MASK	    0x20
#define ITCAST_DER_SHORT_ID_MASK		0x1F
#define ITCAST_DER_FIRST_NOT_ID_MASK    0x7F     //xia
#define ITCAST_DER_FIRST_YES_ID_MASK    0x80     //xia
#define ITCAST_DER_ALL_YES_ID_MASK      0xFF     //xia
/* The maximum size for the short tag number encoding, and the magic value
   which indicates that a long encoding of the number is being used */

#define ITASN1_MAX_SHORT_BER_ID	    30
#define ITASN1_LONG_BER_ID		    0x1F

   
#define		DER_ITCAST_Free(memblock) {if(memblock) {free(memblock); memblock=NULL;}}	//宏函数

#define DER_ITASN1_LOW_IDENTIFIER(cTag)     (cTag & ITCAST_DER_SHORT_ID_MASK)

//这一行为宏，下面几行全都是这个宏的定义，其实就是比较大的宏函数了
#define  DER_CREATE_LOW_ITCAST_ANYBUF(point) \
	     point = (ITCAST_ANYBUF *)malloc(sizeof(ITCAST_ANYBUF)); \
         if (point==NULL) return 7002; \
		 memset(point,0,sizeof(ITCAST_ANYBUF)); \
         point->dataLen = 0; \
         point->dataType = 0; \
	     point->memoryType = DER_ITASN1_MEMORY_MALLOC; \
	     point->pData = NULL; \
	     point->unusedBits = 0; \
	     point->next = NULL; \
         point->prev = NULL

#define DER_ITASN1_LOW_CREATEUINT8(point,size) \
	    point = malloc(size); \
		if (point==NULL) return 7002; \
        //memset(point,0,size)

#define DER_ITASN1_LOW_CREATEUINT32(point) \
	    point = malloc(sizeof(ITCAST_UINT32)); \
		if (point==NULL) return 7002; \
        memset(point,0,sizeof(ITCAST_UINT32))

#define DER_ITASN1_LOW_CHECKERR(iResult,iErrNumber) \
	    if (iResult == iErrNumber) \
            return iErrNumber
#define DER_DACERT_LOW_FREE_ANYBUF(point) \
	    DER_ITCAST_Free(point->pData); \
        DER_ITCAST_Free(point)
#define DER_ITASN1_MEMORY_STATIC     1
#define DER_ITASN1_MEMORY_MALLOC     2

typedef struct ITCAST_ANYBUF_{
	
    unsigned char 	  *pData;	//指向一整个TLV，或者指向TLV中的V，都有可能，视情况而定
    ITCAST_UINT32     dataLen;	//TLV中的L，数据的长度，也就是V的大小
    
    ITCAST_UINT32     unusedBits;  /* for bit string ，这个没用*/  
    ITCAST_UINT32     memoryType;	//这个没用
    ITCAST_UINT32     dataType;		//TLV中的T，数据的类型
    struct ITCAST_ANYBUF_ *next;    //指向下一个结点
    struct ITCAST_ANYBUF_ *prev;	//指向上一个结点
    
}ITCAST_ANYBUF;
 
typedef ITCAST_UINT8     ITASN1_BOOLEAN;
typedef ITCAST_ANYBUF    ITASN1_INTEGER;
typedef ITCAST_ANYBUF    ITASN1_OCTETSTRING;
typedef ITCAST_ANYBUF    ITASN1_BITSTRING;
typedef ITCAST_ANYBUF    ITASN1_PRINTABLESTRING;
/*begin of bmpstring*/
typedef ITCAST_ANYBUF	 ITASN1_BMPSTRING;
/*end of bmpstring*/
typedef ITCAST_ANYBUF    ITASN1_ENUMERATED;
typedef ITCAST_ANYBUF    ITASN1_IA5STRING;
typedef ITCAST_ANYBUF    ITASN1_SEQUENCE;
typedef ITCAST_ANYBUF    ITASN1_SET; 
//typedef time_t       ITASN1_GENERALIZEDTIME;
//typedef time_t       ITASN1_UTCTIME;

/*
  对整型进行编码，传入一个整型变量，传入一个ITASN1_INTEGER类型的指针变量的地址，
  在函数体内会malloc一片内存空间，并让这个指针变量指向这片内存空间，最终以传出参数的形式返回
  编码后ITASN1_INTEGER类型的指针变量，所指向的成员变量p->Data就是被编码的数据，直接读是读不懂的，
  
  ANYBUF类型的中的pData指向的是一个TLV格式的数据，还是int数据本身，还有待研究

  参数integer:传入的整型变量
  参数ppDerInteger:传出参数，传出一个指向的ITASN1_INTEGER类型的指针变量
*/
ITCAST_INT
DER_ItAsn1_WriteInteger(ITCAST_UINT32 integer, ITASN1_INTEGER **ppDerInteger);

/*
  对编码后的整型进行解码
  参数pDerInteger:传入参数，表示待解码的数据
  参数pInteger:传出参数，为解码之后传出的数据，需在函数外面先定义整型变量，
  再把整型变量的地址传进去，最后传出的值就是解码后的原始数据
*/
ITCAST_INT
DER_ItAsn1_ReadInteger(ITASN1_INTEGER *pDerInteger, ITCAST_UINT32 *pInteger);

/*
  把unsigned char *类型转化成ITCAST_ANYBUF类型，就是把字符串转换成ITCAST_ANYBUF
  参数pOriginBuf:传出参数，先传入一个ITCAST_ANYBUF类型的指针的地址，得到指针的地址，就能控制指针的指向，
  函数内部会分配空间，该内存空间为ITCAST_ANYBUF类型数据的变量，并让这个指针指向这片内存空间，最后再传出这个指针的地址，得到指针的地址后，就能通过地址找到指针，
  找到指针，也就找到了指针指向的内存空间
  参数strOrigin：传入参数，待转化的字符串
  参数strOriginLen：strOrigin字符串的长度，传入字符串并且传入长度，这样函数就知道字符串的大小
*/
ITCAST_INT
DER_ITCAST_String_To_AnyBuf(ITCAST_ANYBUF **pOriginBuf, unsigned char * strOrigin, int strOriginLen);

/*
  对字符串进行编码，传入一个ITASN1_PRINTABLESTRING类型数据的指针，这个数据由String_To_AnyBuf函数传出得来
  传出一个指向ITASN1_PRINTABLESTRING类型数据的指针
  参数pPrintString:传入参数，传入一个ITASN1_PRINTABLESTRING类型数据的指针，指针指向要编码的数据 
  参数ppDerPrintString：传出参数，先在函数外面定义一个ITASN1_PRINTABLESTRING类型指针，传入这个指针的地址，
  函数内部会malloc空间，并让这个指针指向这个地址，
  传出一个指向ITASN1_PRINTABLESTRING类型的指针，指针指向的就是编码后的数据，
*/
ITCAST_INT
DER_ItAsn1_WritePrintableString(ITASN1_PRINTABLESTRING *pPrintString, ITASN1_PRINTABLESTRING **ppDerPrintString);

/*
  对字符串进行解码
  参数pDerPrintString：传入参数，ITASN1_PRINTABLESTRING类型的数据，为解码前的数据，
  此数据中的pData成员指针所指向的内存空间是看不懂的，因为还没有解码
  参数ppPrintString：传出参数，为解码之后的数据，它的pData成员指针指向的内存空间是能读懂的
*/
ITCAST_INT
DER_ItAsn1_ReadPrintableString(ITASN1_PRINTABLESTRING *pDerPrintString, ITASN1_PRINTABLESTRING **ppPrintString);	

/*
  直接对字符串进行编码，就是将字符串直接转化成TLV了格式，不需要先调用DER_ITCAST_String_To_AnyBuf函数进行字符串转化
  参数pData：传入的字符串
  参数dataLen：pData的长度
  参数outBuf：传出参数，ITCAST_ANYBUF类型的数据，就是TLV格式的数据
*/
int EncodeChar(char *pData, int dataLen, ITCAST_ANYBUF **outBuf);

/*
  序列化链表，结构体成员都编码完成之后，对一整个结构体进行编码
  参数pSequence：传入参数，为链表的头结点
  参数ppDerSequence：序列化后的数据，为ITCAST_ANYBUF，是TLV格式
*/
ITCAST_INT
DER_ItAsn1_WriteSequence(ITASN1_SEQUENCE *pSequence, ITCAST_ANYBUF **ppDerSequence);

//将序列化后的数据进行反序列化
ITCAST_INT
DER_ItAsn1_ReadSequence(ITCAST_ANYBUF *pDerSequence, ITASN1_SEQUENCE **ppSequence);

//释放空间，如果是链表，则会逐个释放结点
ITCAST_INT
DER_ITCAST_FreeQueue(ITCAST_ANYBUF *pAnyBuf);


ITCAST_INT
DER_ItAsn1_WriteBitString(ITASN1_BITSTRING *pBitString, ITASN1_BITSTRING **ppDerBitString);

ITCAST_INT
DER_ItAsn1_ReadBitString(ITASN1_BITSTRING *pDerBitString, ITASN1_BITSTRING **ppBitString);

ITCAST_INT
DER_ItAsn1_WriteNull(ITCAST_ANYBUF ** ppDerNull);

ITCAST_INT
DER_ItAsn1_ReadNull(ITCAST_ANYBUF * ppDerNull, ITCAST_UINT8 * pInt);


int WriteNullSequence(ITCAST_ANYBUF **pOutData);

int EncodeUnsignedChar(unsigned char *pData, int dataLen, ITCAST_ANYBUF **outBuf);

int DecodeChar(ITCAST_ANYBUF *inBuf, char **Data, int *pDataLen);

#ifdef __cplusplus
}
#endif

#endif
