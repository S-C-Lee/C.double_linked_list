#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;
Node* head;
Node* tail;
void insert(int item)
{
	Node* node = malloc(sizeof(Node));
	node->data = item;
	Node* cur = head->next;
	while (cur != tail)
		cur = cur->next;
	Node* before = cur->prev;
	before->next = node;
	node->prev = before;
	cur->prev = node;
	node->next = cur;

}
int removeat()
{
	Node* erase = head->next;
	head->next = erase->next;
	int out = erase->data;
	Node* next = erase->next;
	next->prev = head;
	free(erase);
	return out;
}
void show()
{
	Node* show = head->next;
	while (show != tail)
	{
		printf("%d ", show->data);
		show = show->next;
	}
}
void freeat()
{
	Node* cur = head->next;
	while (cur != NULL)
	{
		free(cur);
		cur = cur->next;
		
	}
	
		
}
int main(void)
{
	head = malloc(sizeof(Node));
	tail = malloc(sizeof(Node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	removeat();
	show();
	freeat();



}