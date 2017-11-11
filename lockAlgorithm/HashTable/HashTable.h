
#define UINT32 		unsigned int
#define CHAR 		char

#define HS_INEDX_HEAD	(0)	
#define HS_OK			(0)
#define HS_ERR			(-1)

typedef struct HashTable
{
	struct HashTable *next;
	char *key;
	UINT32 value;
}HTItem;

void HashTable_init(HTItem **htitem,UINT32 length);
UINT32 HTIndex(char *key,HTItem **table);
UINT32 HTAdd(char *key,UINT32 value,HTItem **table);
UINT32 HTGet(char *key,HTItem **table);
UINT32 HTDel(char *key,HTItem **table);
void HTDis(HTItem **table);
