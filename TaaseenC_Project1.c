#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pcbNode
{
    //int parent;
    int process;
    struct pcbNode *child;
};
typedef struct pcbNode PCB;

int k = 0;
int p = 0;

int currProcess;
int maxProcess;
PCB *mainProcess;

void enterParam(){
    
    printf("\n Enter maximum number of processes:");
    scanf("%d", &maxProcess);
    mainProcess = (PCB*) malloc(sizeof(PCB)*maxProcess); //struct pcbNode //(PCB*) - type casting. //
    mainProcess[0].process=0;
    mainProcess[0].child=NULL;
    for(int i = 1; i<maxProcess; i++){
        mainProcess[i].process=-1;
        mainProcess[i].child=NULL;
    }
    currProcess = 1;
}

/*    while (mainProcess[i].child != NULL)
    {
        printf("\nPCB[%d] is the parent of: ", mainProcess[i].process);
            while (ptr[k].child != NULL)
        {
            printf("\n PCB[%d]", ptr[k].child->process);//was .child->process
            k=ptr[k].child->process;
        }
        i++;
    }
*/

void displayPCB(){ 

    PCB *ptr;

    for (int i = 0; i < maxProcess; i++)
    {
        if (mainProcess[i].process != -1)
        {
            printf("\n PCB[%d] is the parent of: ", i);
        }
        PCB *ptr = &mainProcess[i];
        while (ptr->child != NULL)
        {
            printf("PCB[%d] ", ptr->child->process);
            ptr=ptr->child;
        }
    }
    //i++;
}

void createChild(){
    if(currProcess==maxProcess){
        printf("Max processes reached");
        return;
    }
    

    int i;
    printf("\n\nEnter parent process index: ");
    scanf("%d", &i);
    PCB* n = &mainProcess[i];
    
    if(n->process = -1){
        n->process = i;
    }

    while (n->child != NULL)
    {
        n = n->child;
    }
    
/* allocate memory for new child process, initilize fields */
    PCB* newChild = (PCB*) malloc(sizeof(PCB));
    newChild->process = currProcess;//was currProcess
    newChild->child = NULL;
    n->child = newChild;
    currProcess++;
    //printf("\nNew Child Process: [%d]", newChild->process);
    //printf("\nN Child Process: %d", n->child->process);

    displayPCB();
}
//1 5 2 0 2 0 2 2


void destroyChildren(){
currProcess--;
}

int main(){
    bool menu = true;
    int inp;

    while(menu == true){
        printf("\n Process Creation and Destruction");
        printf("\n ------------------------------");
        printf("\n Choose an Option (Integer).");
        printf("\n 1.Enter Parameters.");
        printf("\n 2.Create a new Child Process.");
        printf("\n 3.Destroy all Descendants of a Process.");
        printf("\n 4.Quit Program and Free Memory.\n");
        printf("\n Enter Selection:");
        scanf("%d", &inp);

        if(inp==1){
            printf("Chosen: 1\n");
            //Prompts for max processes and creates first node
            enterParam();

        } else if(inp==2){
            printf("Chosen: 2\n");
           // printf("\n Enter the Parent Process Index:");
            createChild();
            //break;
        } else if(inp==3){
            printf("Chosen: 3\n");
            //break;
        } else if(inp==4){
            printf("Chosen: 4\n");
            menu=false;
            //break;
        } else {
            printf("Error Choose a number 1-4.\n");
            //break;
        }
    }

    printf("Exited Menu Loop");
    free(mainProcess);
return 0;
}