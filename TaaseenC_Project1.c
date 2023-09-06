#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void op1(){}

void op2(){}

void op3(){}

//void op4(){}

int main(){
    bool menu = true;
    int inp;
    int *arr = NULL; // pointer

    while(menu == true){
        printf("Process Creation and Destruction");
        printf("\n ------------------------------");
        printf("\n Choose an Option (Integer).");
        printf("\n 1.Enter Parameters.");
        printf("\n 2.Create a new Child Process.");
        printf("\n 3.Destroy all Descendants of a Process.");
        printf("\n 4.Quit Program and Free Memory.\n");
        scanf("%d", &inp);

        if(inp==1){
            printf("Chosen: 1\n");
            //break;
        } else if(inp==2){
            printf("Chosen: 2\n");
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