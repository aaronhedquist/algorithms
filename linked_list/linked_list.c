#import <stdio.h>
#import <stdlib.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

int pushToStart (node_t ** head, int newValue);
int pushToEnd (node_t * head, int newValue);
void push (node_t * head, int newValue);
void printList (node_t * head);
int popFirst (node_t ** head);
int popLast (node_t * head);
int insertAtIndex (node_t ** head, int insertionIndex, int newValue);

int main () {

	node_t * head = NULL;
	head = (node_t *)malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	}

	head->val = 23;
	head->next = NULL;

	for (int i = 0; i < 5; i++) {
        int value = i * 10;
		pushToEnd(head, value);
	}
    
    for (int i = 0; i < 5; i++) {
        int value = i * 100;
        pushToStart(&head, value);
    }
	
//	printList(head);
    
//    for (int i = 0; i < 5; i++) {
//        int poppedValue = popFirst(&head);
//        printf("popFirst %d\n", poppedValue);
//    }
//    
//    for (int i = 0; i < 5; i++) {
//        int poppedValue = popLast(head);
//        printf("popLast %d\n", poppedValue);
//    }
    
    printList(head);
    printf("\n");
    
    insertAtIndex(&head, 4, 678);
    
    printList(head);

	return 0;
}

int pushToStart (node_t ** head, int newValue) {
    
    if (head == NULL) {
        return -1;
    }
    
    // create new node
    node_t * newNode = (node_t *)malloc(sizeof(node_t));
    
    if (newNode == NULL) {
        return -1;
    }
    
    // assign new value to new node
    newNode->val = newValue;
    
    // change new node-> next to point to old head
    newNode->next = *head;
    
    // change pointer to head to new node
    *head = newNode;
    
    return 0;
    
}

int pushToEnd (node_t * head, int newValue) {

	node_t * newNode = NULL;
	newNode = (node_t *)malloc(sizeof(node_t));
	if (newNode == NULL) {
		return -1;
	}

	node_t * current = head;

    // Loop until we find the end
	while (current->next != NULL) {
		current = current->next;
//        printf("current->val %d\n", current->val);
	}

    // Assign new value to the new node
	newNode->val = newValue;
    
    // Set the end of the current linked list to point to the next value, extending its length now by one
	current->next = newNode;
    
    return 0;

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

int popFirst (node_t ** head) {

    int retVal = -1;
    node_t * next_node = NULL;
    
    retVal = (*head)->val;
    
    // check if there is a next
    if ((*head)->next != NULL) {
        
        // if so, assign pointer to head to new variable
        next_node = (*head)->next;
        
    }
    
    free(*head);
    
    if (next_node != NULL) {
        *head = next_node;
    }

	return retVal;

}

int popLast (node_t * head) {
    
    node_t * current = head;
    
    // Loop until we find the second to the end
    while (current->next->next != NULL) {
        current = current->next;
        //        printf("current->val %d\n", current->val);
    }
    
    // Assign the end value to an intermediate variable
    int retVal = current->next->val;
    
    node_t *last = current->next;
    
    // Clear memory of the last
    free(last);
    
    // Remove link to last node on second-to-last node
    current->next = NULL;
    
    return retVal;
    
}

int insertAtIndex (node_t ** head, int insertionIndex, int newValue) {
    
    // Create new node to store new value
    node_t * newNode = malloc(sizeof(node_t));
    
    if (newNode == NULL) {
        return -1;
    }
    
    newNode->val = newValue;
    
    // Find where to insert it
    
    node_t * node_before = NULL;
    node_t * node_after = *head;
    node_t * current = *head;
    
    if (insertionIndex == 0) {
        
        return pushToStart(head, newValue);
        
    } else {
        
        // Loop through until we can update current to equal the value we want to insert at
        for (int i = 0; i < insertionIndex; i++) {
            
            // set node_before to current before incrementing; node_before = i
            node_before = current;
            
            // update current to the next node in the chain
            
            if (current->next != NULL) {
                current = current->next;
                
                // node_after = i+1
                node_after = current;
            }
            
        }
        
        // update the new nodes-next to equal the node we found at i+1
        newNode->next = node_after;
        
        // update the node that comes before the index next value to the new node
        node_before->next = newNode;
        
        return 1;
        
    }
    
}
