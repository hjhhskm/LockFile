#include "HashTable.h"
#include <stdio.h>

int main()
{
	HTItem *table[101];
	UINT32 length = 101;
	HashTable_init(table,length);
	HTAdd("litao",98,table);
	HTAdd("wangbiaoyu",77,table);
	HTAdd("lijipeng",85,table);
	HTAdd("hanjiahui",83,table);
	printf("litao's scroce is %d ",HTGet("litao",table));
	HTDis(table);
	printf("delete wangbiaoyu %d",HTDel("wangbiaoyu",table));
	printf("delete wangbiaoyu %d",HTDel("wangbiaoyu",table));
	HTDis(table);
	return 0;
}