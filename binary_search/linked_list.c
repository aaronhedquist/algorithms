#import <stdio.h>
#import <stdlib.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

void push (node_t * head, int newValue);
void printList (node_t * head);
int pop (node_t * head);

int main () {

	node_t * head = NULL;
	head = (node_t *)malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	}

	head->val = 10;
	head->next = NULL;

	for (int i = 0; i < 1; i++) {
		push(head, i * 10);
	}
	
	printList(head);

	return 0;
}

void push (node_t * head, int newValue) {

	node_t * newNode = NULL;
	newNode = (node_t *)malloc(sizeof(node_t));
	if (newNode == NULL) {
		return;
	}

	node_t * current = head;

	while (current->next != NULL) {
		current = current->next;
	}

	newNode->val = newValue;
	head->next = newNode;

}

void printList (node_t * head) {

	node_t * current = head;
	int i = 0;
	
	while (current != NULL) {
		printf("linked list value at index %d is %d\n", i, current->val);
		current = current->next;
		i++;
	}

}

int popFirst (node_t * head) {

	// check if there is a next
	if (head->next != NULL) {

		// if so, assign pointer to head to new variable
		node_t * old_head = head;

		// reassign head to next
		head = head->next;

		// return old head
		return old_head->val;

	}

	// there is no next, return head

	int head_value = head->val;
	head = NULL;

	return head_value;

}