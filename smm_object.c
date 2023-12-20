//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODETYPE    7
#define MAX_GRADE       9
#define Max_NODE		100 

static char smmNodeName[SMMNODE_TYPE_MAX][MAX_CHARNAME]={
	"lecture",
	"restaurant",
	"laboratory",
	"home",
	"gotolab",
	"foodchance",
	"festival",
};

char* smmObj_getTypeName(int type)
{
		return (char*)smmNodeName[type];
}




//1.구조체 형식 정의 
typedef struct smmObject{
	char name[MAX_CHARNAME];
	smmObjType_e objType; 
	int type;
	int credit;
	int energy;
	smmObjGrade_e grade;
}smmObject_t;




//3.관련 함수 변경 
//object generation
void* smmObj_genObject(char*name, smmObjType_e objType, int type, 
int credit, int energy, smmObjGrade_e grade) //노드를 만드는 함수
{
	smmObject_t*ptr;
	ptr=(smmObject_t*)malloc(sizeof(smmObject_t));
	
	strcpy(ptr->name, name);
	ptr->objType=objType;
	ptr->type=type;
	ptr->credit=credit;
	ptr->energy=energy;
	ptr->grade=grade;
	
	return ptr;
}
	

//node 관련 
char* smmObj_getNodeName(void* obj)
{	
	smmObject_t*ptr=(smmObject_t*)obj;
	return ptr->name;
}

int smmObj_getNodeType(void* obj)
{
	smmObject_t*ptr=(smmObject_t*)obj;
	return ptr->type;
}

int smmObj_getNodeCredit(void* obj)
{
	smmObject_t*ptr=(smmObject_t*)obj;
	return ptr->credit;
}

int smmObj_getNodeEnergy(void* obj)
{
	smmObject_t*ptr=(smmObject_t*)obj;
	return ptr->energy;
}







