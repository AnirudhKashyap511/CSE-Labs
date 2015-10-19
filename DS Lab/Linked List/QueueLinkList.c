//
//  QueueLinkedList.c
//  Linked List Queue
//
//  Created by Avikant Saini on 9/28/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define UNDERFLOW_INT -32767

typedef enum { NO, YES } BOOL;

typedef struct Node {
	int data;
	struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->next = NULL;
	temp->data = UNDERFLOW_INT;
	return temp;
}

void insert (NODE_p_t queue, int item) {
	NODE_p_t temp = createNode();
	NODE_p_t p;
	
	temp->data = item;
	
	if (queue->next == NULL)
		queue->next = temp;
	
	else {
		p = queue->next;
		
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
		
	}
}

int delete (NODE_p_t queue) {
	NODE_p_t temp = createNode();
	
	if (queue->next == NULL) {
		printf("\n\tEMPTY QUEUE!\n\n");
		return UNDERFLOW_INT;
	}
	
	else {
		temp = queue->next;
		int item = temp->data;
		queue->next = temp->next;
		free(temp);
		return item;
	}
}

void display (NODE_p_t queue) {
	NODE_p_t temp = queue->next;
	
	if (queue->next != NULL)  {
		printf("\n\tCURRENT QUEUE: ");
		while (temp->next != NULL) {
			printf(" %d ->", temp->data);
			temp = temp->next;
		}
		printf(" %d", temp->data);
		temp = temp->next;
	}
	
	printf("\n-------------------------------------------------------------------------\n");
}


int main (int argc, const char * argv []) {
	
	NODE_p_t queue = createNode();
	
	char choice;
	
	do {
		printf("\n\t1. Insert\n\t2. Delete\n\t3. Display\n\tCHOICE: ");
		scanf(" %c", &choice);
		
		if (choice == '1') {
			int item;
			printf("\n\tEnter item to be inserted: ");
			scanf("%d", &item);
			insert(queue, item);
		}
		else if (choice == '2') {
			int item = delete(queue);
			if (item != UNDERFLOW_INT)
				printf("\n\tDeleted item: %d\n\n", item);
		}
		display(queue);
		
	} while (choice == '1' || choice == '2' || choice == '3');
	
	printf("\n\n");
	
	return 0;
}
