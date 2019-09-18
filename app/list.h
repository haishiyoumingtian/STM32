#ifndef __LIST_H
#define __LIST_H

#include "main.h"

typedef struct link {
	u8 data[8];
	uint32_t StdId;
	struct link *next;
}link;

extern struct link *top, *tail;

#define LEN sizeof(struct link)

void print(struct link *top);
void insert(u8 *BUF,uint32_t StdId);
void append(int n);
void List_Init(int n);
void delet(void);

 
#endif 
