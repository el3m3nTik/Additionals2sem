#include <iostream>

struct list
{
	int field; 
	struct list* next;
	struct list* prev;
};

struct list* INIT()  
{
	struct list* list;
	list = (struct list*)malloc(sizeof(struct list));
	list->next = list;
	list->prev = list;
	return(list);
}

struct list* ADD(list* list, int number)
{
	struct list* p;
	p = (struct list*)malloc(sizeof(struct list));
	p->field = number;
	p->prev = list;
	p->next = list->next;
	list->next = p;
	p->next->prev = p;

	return(list);
}

struct list* DELETE(list* list)
{
	struct list* p = list->next;
	while (p != list)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		struct list* tmp = p;
		p = p->next;
		free(tmp);
	}

	return(list);
}

void PRINT(list* list)
{
	struct list* p;
	p = list->next;
	do {
		printf("%d ", p->field); 
		p = p->next; 
	} while (p != list); 
}

void PRINTR(list* list)
{
	struct list* p;
	p = list->prev;
	do {
		printf("%d ", p->field);
		p = p->prev;
	} while (p != list); 
}

int main()
{
	list* list = INIT();
	ADD(list, 15);
	ADD(list, 1);
	ADD(list, 3);
	PRINT(list);
	PRINTR(list);
	DELETE(list);
	free(list);

	return 0;
}