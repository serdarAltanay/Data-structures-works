#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    if (value == -1) {
        return NULL; 
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the height
int calculateHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to calculate the balance factor
int calculateBalanceFactor(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return leftHeight - rightHeight;
}

// Function to construct the binary tree from the input array
Node* constructTree(int* values, int index, int size) {
    if (index >= size || values[index] == -1) {
        return NULL;
    }
    Node* root = createNode(values[index]);
    root->left = constructTree(values, 2 * index, size);
    root->right = constructTree(values, 2 * index + 1, size);
    return root;
}

// Print function(it uses queue method to print)
void printTree(Node* root, int* values, int size) {
    if (root == NULL) {
        return;
    }

    struct QueueItem {
        Node* node;
        int index;
    };

    struct QueueItem queue[size];
    int front = 0, rear = 0;

    // Enqueue
    queue[rear++] = (struct QueueItem){root, 1};
    
    
    int flag =1;
    
    while (front < rear) {
        int currentLevelSize = rear - front;

        for (int i = 0; i < currentLevelSize; ++i) {
            struct QueueItem currentItem = queue[front++];
            Node* current = currentItem.node;
            int index = currentItem.index;

            int parentIndex = index / 2;
            char* position = index == 1 ? "" : (index % 2 == 0 ? "L" : "R");

            if (index == 1) {
                printf("%d (%d B)", current->value, calculateBalanceFactor(current));
                flag++;
            } else {
                if(flag == 1){
                  printf("%d (%d %s) (%d B)", current->value,
                       values[parentIndex],
                       position,
                       calculateBalanceFactor(current));
                  flag++;
                }else{
                    printf(" %d (%d %s) (%d B)", current->value,
                       values[parentIndex],
                       position,
                       calculateBalanceFactor(current));
                    flag++;
                }
                
            }

            if (current->left) queue[rear++] = (struct QueueItem){current->left, 2 * index};
            if (current->right) queue[rear++] = (struct QueueItem){current->right, 2 * index + 1};
        }
        printf("\n");
        flag = 1;
    }
}

int main() {
    int values[100];
    int index = 1; 

    while (1) {
        int input;
        scanf("%d", &input);
        if (input == -2) {
            break;
        }
        values[index] = input;
        index++;
    }
    int size = index;

    // Construct the tree
    Node* root = constructTree(values, 1, size);

    printTree(root, values, size);

    return 0;
}

