#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
} NODE;

NODE *start = NULL;
NODE *create_ll(NODE *);
NODE *display(NODE *);
NODE *insert_beg(NODE *);
NODE *insert_end(NODE *);
NODE *insert_before(NODE *);
NODE *insert_after(NODE *);
NODE *delete_beg(NODE *);
NODE *delete_end(NODE *);
NODE *delete_node(NODE *);
NODE *delete_after(NODE *);
NODE *delete_list(NODE *);
NODE *sort_list(NODE *);

int main() {
    int option;
    do {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1: start = create_ll(start); 
                    printf("\n LINKED LIST CREATED");
                    break;
            case 2: start = display(start); 
                    break;
            case 3: start = insert_beg(start); 
                    break;
            case 4: start = insert_end(start); 
                    break;
            case 5: start = insert_before(start); 
                    break;
            case 6: start = insert_after(start); 
                    break;
            case 7: start = delete_beg(start); 
                    break;
            case 8: start = delete_end(start); 
                    break;
            case 9: start = delete_node(start); 
                    break;
            case 10: start = delete_after(start); 
                     break;
            case 11: start = delete_list(start); 
                     printf("\n LINKED LIST DELETED");
                     break;
            case 12: start = sort_list(start); 
                     break;
        }
    } while(option != 13);
    //13 is exit option
    return 0;
}

// Create a linked list
NODE *create_ll(NODE *start) {
    NODE *newNode, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);
    
    while(num != -1) {
    
        newNode = (NODE*)malloc(sizeof(NODE));
        newNode->data = num;

        if (start == NULL) {
            newNode->next = NULL;
            start = newNode;
        } else {
            ptr = start;
            while(ptr->next != NULL) {
                //finding end of the list
                ptr = ptr->next;
            }
            //adding new node to end of the list
            ptr->next = newNode;
            newNode->next = NULL;
        }

        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
    return start;
}

// Display the linked list
NODE *display(NODE *start) {
    NODE *ptr = start;
    if (ptr == NULL) {
        printf("\nThe list is empty.\n");
        return start;
    }
    while(ptr != NULL) {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

// Insert at the beginning
NODE *insert_beg(NODE *start) {
    NODE *new_node;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (NODE *)malloc(sizeof(NODE));

    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

// Insert at the end
NODE *insert_end(NODE *start) {
    NODE *ptr, *new_node;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (NODE *)malloc(sizeof(NODE));

    new_node->data = num;
    new_node->next = NULL;

    ptr = start;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return start;
}

// Insert before a given node
NODE *insert_before(NODE *start) {
    NODE *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value before which the data has to be inserted: ");
    scanf("%d", &val);

    new_node = (NODE *)malloc(sizeof(NODE));
    new_node->data = num;

    ptr = start;
    preptr = NULL;

    while(ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    if (ptr == NULL) {
        printf("Node with value %d not found.\n", val);
        return start;
    }

    if (preptr == NULL) {  // If inserting at the beginning
        new_node->next = start;
        start = new_node;
    } else {
        preptr->next = new_node;
        new_node->next = ptr;
    }

    return start;
}

// Insert after a given node
NODE *insert_after(NODE *start) {
    NODE *new_node, *ptr;
    int num, val;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value after which the data has to be inserted: ");
    scanf("%d", &val);

    new_node = (NODE *)malloc(sizeof(NODE));
    new_node->data = num;

    ptr = start;
    while(ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with value %d not found.\n", val);
        return start;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;

    return start;
}

// Delete from the beginning
NODE *delete_beg(NODE *start) {
    NODE *ptr;
    if (start == NULL) {
        printf("List is empty, nothing to delete.\n");
        return start;
    }
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

// Delete from the end
NODE *delete_end(NODE *start) {
    NODE *ptr, *preptr;
    if (start == NULL) {
        printf("List is empty, nothing to delete.\n");
        return start;
    }
    ptr = start;
    while(ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

// Delete a specific node
NODE *delete_node(NODE *start) {
    NODE *ptr, *preptr;
    int val;
    printf("\nEnter the value of the node which has to be deleted: ");
    scanf("%d", &val);
    
    ptr = start;
    if(ptr != NULL && ptr->data == val) {
        start = delete_beg(start);
        return start;
    }
    
    while(ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    if(ptr == NULL) {
        printf("Node with value %d not found.\n", val);
        return start;
    }
    
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

// Delete a node after a given node
NODE *delete_after(NODE *start) {
    NODE *ptr, *preptr;
    int val;
    printf("\nEnter the value after which the node has to be deleted: ");
    scanf("%d", &val);
    
    ptr = start;
    while(ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    
    if(ptr == NULL || ptr->next == NULL) {
        printf("Node after %d not found or no node to delete.\n", val);
        return start;
    }
    
    preptr = ptr->next;
    ptr->next = preptr->next;
    free(preptr);
    
    return start;
}

// Delete the entire list
NODE *delete_list(NODE *start) {
    NODE *ptr;
    while(start != NULL) {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    return start;
}

// Sort the list
NODE *sort_list(NODE *start) {
    NODE *ptr1, *ptr2;
    int temp;
    
    for(ptr1 = start; ptr1 != NULL; ptr1 = ptr1->next) {
        for(ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if(ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
    return start;
}

