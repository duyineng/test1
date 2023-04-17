#pragma once
typedef struct _Teacher
{
	char name[64];
	int age;
	char *p;	//可以是教师的说明信息，指向一片内存空间，也可以为空
	int plen;		//p指向的内存空间的长度
}Teacher;
int TeacherEncode(Teacher *pTeacher, unsigned char **out, int *outlen);
int TeacherDecode(unsigned char *indata, int inLen, Teacher **pStruct);
void freeTeacher(Teacher** pTeacher);