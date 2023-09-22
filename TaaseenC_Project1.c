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

int currProcess;
int maxProcess;
PCB *mainProcess;

void enterParam(){
    
    printf("\n Enter maximum number of processes:");
    scanf("%d", &maxProcess);
    mainProcess = (PCB*) malloc(sizeof(PCB)*maxProcess); //struct pcbNode
    mainProcess[0].process=0;
    mainProcess[0].child=NULL;
    for(int i = 1; i<maxProcess; i++){
        mainProcess[i].process=-1;
        mainProcess[i].child=NULL;
    }
    currProcess = 1;
}




void createChild(){
    if(currProcess=maxProcess){
        printf("Max processes reached");
        return;
    }
    currProcess++;

    int i;
    printf("\n\nEnter parent process index: ");
    scanf("%d", &i);
    PCB* n = &mainProcess[i];
    while (n->child != NULL)
    {
        n = n->child;
    }
    
/* allocate memory for new child process, initilize fields */
    PCB* new_child = (PCB*) malloc(sizeof(PCB));
    new_child->process = i;
    new_child->child = NULL;
    n->child = new_child;
    
    displayPCB();

}

void displayPCB(){
    int i = 0;
    while (mainProcess[i].process != NULL)
    {
        printf("\nPCB[%d] is the parent of PCB[%d]", i, mainProcess[i].child);
        i++;
    }
    
}

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