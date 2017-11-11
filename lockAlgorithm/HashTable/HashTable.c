#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include<unistd.h>
#include "HashTable.h"

UINT32 BKDR_HASH(char *key)
{
	UINT32 seed = 1313;
	UINT32 hash = 0;
	while(*key != '\n' && *key != 0)
	{
		hash = hash * seed + (*key++);
	}
	//printf("\r\n create ok ,hash is %d\r\n",hash);
	return (hash & 0x7FFFFFFF);
}

void HashTable_init(HTItem **table,UINT32 length)
{
	UINT32 iter = HS_OK;
	for(;iter < length;iter++)
	{
		table[iter] = (HTItem *)malloc(sizeof(HTItem));
		memset(table[iter],HS_OK,sizeof(table[iter]));
	}
	table[HS_INEDX_HEAD]->value = length;
}

UINT32 HTIndex(char *key,HTItem **table)
{

	UINT32 temp = BKDR_HASH(key);
	UINT32 length = table[HS_INEDX_HEAD]->value -1;
	
	return (temp % length) +1; 
}

UINT32 HTAdd(char *key,UINT32 value,HTItem **table)
{
	UINT32 index = HTIndex(key,table);
	HTItem *point = table[index];
	
	while(point->next!=0)
	{
		if(strcmp(key,point->next->key) == HS_OK)
		{
			point->next->value = value;
			printf("\r\n add %d ok \r\n",value);
			return HS_OK;
		}else{
			point = point->next;
		}

	}
	point->next = (HTItem *)malloc(sizeof(HTItem));
	memset(point->next,HS_OK,sizeof(point->next));
	point->next->key = key;
	point->next->value = value;
	return HS_OK;
}

UINT32 HTGet(char *key,HTItem **table)
{
	UINT32 index = HTIndex(key,table);
	HTItem *point = table[index];
	while(point->next)
	{
		if(strcmp(key,point->next->key) == HS_OK)
		{
			printf("\r\n add %d ok \r\n",point->next->value);
			return point->next->value;
		}else{
			point = point->next;
		}
	}
	return HS_ERR;
}

UINT32 HTDel(char *key,HTItem **table)
{
	UINT32 index = HTIndex(key,table);
	HTItem *prePoint = table[index];
	HTItem *point = prePoint->next;
	while(point)
	{
		if(strcmp(key,point->key) == HS_OK)
		{
			prePoint->next = point->next;
			free(point);
			return HS_OK;
		}else{
			prePoint = point;
			point = point->next;
		}
	}
	return HS_ERR;
}

void HTDis(HTItem **table)
{
	UINT32 length = table[HS_INEDX_HEAD]->value;
	UINT32 iter = HS_OK;
	for(; iter < length; iter++)
	{
		HTItem *point = table[iter];
		if(!(point->next))
		{
			continue;
		}
		printf("\r\nline %d : ",iter);
		while(point->next)
		{
			printf("\r\n|----key--%s--value--%d--\n",point->next->key,point->next->value);
			point = point->next;
		}
	}
}

