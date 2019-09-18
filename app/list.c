#include "list.h"

struct link *top, *tail;

void append(int n) {
	int i;
	struct link *p1, *p2, *temp;
	p1 = p2 = (struct link*)malloc(LEN);
	for (i = 1; i <= n-1; i++) {
		temp = (struct link*)malloc(LEN);
		temp->next = p1;
		p1 = temp;
	}
	p2->next = p1;
	top = tail = p2;
}
void insert(u8 *BUF,uint32_t StdId) {
	int i;
	if (tail->next == top) {
		top = top->next;
	}
	else{
		tail->StdId=StdId;
		for(i=0;i<8;i++){
			tail->data[i] = BUF[i];
		}
	}
//	printf("²åÈë²ÎÊý:\n");
//	scanf("%d", &data);	
	tail = tail->next;
}
void print(struct link *top){
	while (1) {
		if (top == tail) {
			printf("There is no data in the list\r\n");
			break;
		}
		printf("->%d", top->data[0]);
		top = top->next;
	}
	printf("\r\n");
}
void delet(void){
	if (top == tail) {
		printf("There is no data in the List.\r\n");
	}
	else {
		top = top->next;
	}
}
void List_Init(int n){
	append(n);
//	for(i=1;i<=n;i++){
//		insert();
//	}
	print(top);
	printf("List Initialization Successful!\r\n");
}
