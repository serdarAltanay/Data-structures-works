struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};



void insertFB(struct nodeFB **startFB,int newid,int newage){

  //creating new node
  struct nodeFB *newnode = malloc(sizeof(struct nodeFB));
  newnode->id = newid;
  newnode->age = newage;
  newnode->next = NULL;
  
  if (*startFB == NULL || (*startFB)->id > newid) {
        newnode->next = *startFB;
        *startFB = newnode;
    } else {
        struct nodeFB *temp = *startFB;
        
        //finding location of new node
        while (temp->next != NULL && temp->next->id < newid) {
            temp = temp->next;
        }
        
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insertGS(struct nodeGS **startGS,int newid){

  //creating new node
  struct nodeGS *newnode = malloc(sizeof(struct nodeGS));
  newnode->id = newid;
  newnode->next = NULL;
  
  if (*startGS == NULL || (*startGS)->id < newid) {
        newnode->next = *startGS;
        *startGS = newnode;
    } else {
        struct nodeGS *temp = *startGS;
        
        //finding location of new node
        while (temp->next != NULL && temp->next->id > newid) {
            temp = temp->next;
        }
        
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void createFinalList(struct newNodeFB **startNewFB, struct nodeFB *startFB, struct nodeGS *startGS) { 
    //I use previous gs pointer to give old gs nodes next to new fb node 
    struct newNodeGS *prevGS = NULL; 

    while (startFB != NULL && startGS != NULL) {  // Loop until one list ends
        struct newNodeFB *newFbNode = malloc(sizeof(struct newNodeFB));
        struct newNodeGS *newGsNode = malloc(sizeof(struct newNodeGS));

        newFbNode->id = startFB->id;
        newFbNode->age = startFB->age;
        newFbNode->next = newGsNode;

        newGsNode->id = startGS->id;
        newGsNode->next = NULL;

        if (*startNewFB == NULL) {
            *startNewFB = newFbNode; 
        } else {
            prevGS->next = newFbNode;
        }
 
        prevGS = newGsNode;  

        startFB = startFB->next;
        startGS = startGS->next;
    }
}

void printAll(struct newNodeFB *startNewFb){
    struct newNodeFB *printFbNode = malloc(sizeof(struct newNodeFB));
    struct newNodeGS *printGsNode = malloc(sizeof(struct newNodeGS));
    
    //initialization
    printFbNode = startNewFb;
    printGsNode = startNewFb->next;
    
    int current = 1;
    
  while(printGsNode != NULL){
    if(current == 1){
      printf("%d %d\n",printFbNode->id,printFbNode->age);
      printFbNode = (printFbNode->next)->next;
      current = 0;
    }else{
      printf("%d\n",printGsNode->id);
      if((printGsNode->next) == NULL){
        printGsNode = NULL;
      }else{
        printGsNode = (printGsNode->next)->next;
      }
      current = 1;
    }
  }
}

void printFB(struct nodeFB *startFB){
  struct nodeFB *head = startFB;
  while(head != NULL){
    printf("%d %d\n",head->id,head->age);
    head = head->next;
  }
  printf("\n");
}

void printGS(struct nodeGS *startGS){
  struct nodeGS *head = startGS;
  while(head != NULL){
    printf("%d\n",head->id);
    head = head->next;
  }
  printf("\n");
}
// You must write all the function definitions to be used in this lab into this file. 
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



