#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    char phone[15];
    struct Node* left;
    struct Node* right;
} Node;


int comparestrings(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}


Node* createNode(const char* name, const char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertinorder(Node* root, const char* name, const char* phone) {
    if (root == NULL) {
        return createNode(name, phone);
    }
    if (comparestrings(name, root->name) < 0) {
        root->left = insertinorder(root->left, name, phone);
    } else if (comparestrings(name, root->name) > 0) {
        root->right = insertinorder(root->right, name, phone);
    }
    return root;
}

int searchAndPrint(Node* root, const char* prefix) {
    if (root == NULL) {
        return 0;
    }

    int found = 0;

    // firstly checks left subtree because it is alphabetically upper 
    found |= searchAndPrint(root->left, prefix);


    if (strncmp(root->name, prefix, strlen(prefix)) == 0) {
        //prints name
        printf("%s\n", root->name);
        found = 1;
    }
    
    //checks right subtree after left one
    found |= searchAndPrint(root->right, prefix);

    return found;
}


int main() {
    Node* root = NULL;
    char name[50], phone[15];


    // input loop for names and phone numbers
    while (1) {
        if (scanf("%s", name) != 1) {
            return 1;
        }
        if (strcmp(name, "-1") == 0) {
            break;
        }
        if (scanf("%s", phone) != 1) {
            return 1;
        }

        root = insertinorder(root, name, phone);
    }


    // input and print loop for prefixes
    char prefix[50];
    while (1) {
     
        if (scanf("%s", prefix) != 1) {
            return 1;
        }
        if (strcmp(prefix, "-1") == 0) {
            break;
        }

        int found = searchAndPrint(root, prefix);
        if (!found) {
            printf("nobody\n");
        }
    }

    return 0;
}

