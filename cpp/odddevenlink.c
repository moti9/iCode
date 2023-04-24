/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

// defining a function, that returns 1, if the list is EVEN
int isLengthEven(struct node * listHead) {
	// we need to traverse the List, until we reach the end
	// checking both conditions, NULL and the last Node
	while(listHead !=NULL && listHead -> next != NULL) {
		//advance 2 nodes at a time
		listHead = listHead -> next -> next;
	}

	// if we are at a NULL, means EVEN, return 1
	if(listHead == NULL)
		return 1;
	else
		return 0;
}

struct node * addElement(struct node *head, int number) {
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = number;
	temp -> next = NULL;
	struct node * temp2 = head;
	while(temp2 -> next != NULL)
		temp2 = temp2 -> next;
	temp2 -> next = temp;
	return head;
}

int main(void) {
	//creating a list
	struct node * listHead = (struct node*)malloc(sizeof(struct node));
	listHead->data = 4;
	listHead->next = NULL;
	listHead = addElement(listHead, 8);
	listHead = addElement(listHead, 15);
	listHead = addElement(listHead, 16);
	listHead = addElement(listHead, 23);
	listHead = addElement(listHead, 42);

	if(isLengthEven(listHead))
		printf("EVEN\n");
	else
		printf("ODD\n");

	return 0;
}