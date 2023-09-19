#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pcbNode
{
    int parent;
    int processIndex;
    struct pcbNode * child;
};

typedef struct pcbNode PCB;

void enterParam(){
    int n;
    printf("\n Enter maximum number of processes:");
    scanf("%d", &n);
    PCB *mainProcess = malloc(sizeof(n)); //struct pcbNode
    mainProcess->parent=0;
    mainProcess->processIndex = 0;
    mainProcess->child=NULL;
    
    for(int i = 1; i<n; i++){
        mainProcess[i].parent=-1;
        mainProcess[i].processIndex = i;
        mainProcess[i].child=NULL;
        /*
        if(i+1 > n-1){
            mainProcess[i].child=NULL;
        } else {
            mainProcess[i].child=i+1;
        }*/
    }
    //print all processes
    for(int i = 0; i<n; i++){
        printf("\n PCB[%d]", i);
        printf("\n Parent: PCB[%d]", mainProcess[i].parent);
        printf("\n Process Id: %d", mainProcess[i].processIndex);
        //printf("\n Child: PCB[%d]", mainProcess->child);
    }
}

void createChild(){
    //mainProcess[1].parent=1;
}

void destroyChildren(){}

//void op4(){}

int main(){
    bool menu = true;
    int inp;
    int *arr = NULL; // pointer

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
            enterParam();
            
            //head->childlink=NULL;


        } else if(inp==2){
            printf("Chosen: 2\n");
            printf("\n Enter the Parent Process Index:");

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
    free(arr);
return 0;
}