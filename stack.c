#include<string.h>
#include<stdio.h>

#include<stdlib.h>

#define MAX 100
#define SIZE 100

int main(){
    char frontstack[SIZE][MAX];
    char backstack[SIZE][MAX];
    int fronttop=-1;
    int backtop = -1;
    char currentpage[MAX]="Home";
    char newpage[MAX];
    int choice;
    do{
      printf("\nBrowser Navigation system\n");
      printf("1. Visitt New page\n");
      printf("2. back page\n");
      printf("3. forward page\n");
      printf("4. Display status\n");
      printf("5. Exit..\n");
      printf("Enter your choice\n");
      if(scanf("%d",&choice) !=1){
         printf("Invalid Choice\n");
         while(getchar()!='\n');
         continue;
      }
      switch(choice){
             case 1:
                  if(backtop>=SIZE-1){
                     printf("History full\n");
                     break;
                  }
                  printf("Enter the page name\n");
                  scanf("%99s", newpage);
                  backtop++;
                  strcpy(backstack[backtop],currentpage);
                  strcpy(currentpage,newpage);     
                  fronttop = -1;
                  printf("Current Page: %s\n",currentpage);
                  break;
             case 2:
                  if(backtop==-1){
                     printf("The Browser history is empty\n");
                  }
                  else{
                     if(fronttop>=SIZE-1){
                        printf("Forward Memory limited\n");
                        break;
                     }
                     fronttop++;
                     strcpy(frontstack[fronttop],currentpage);
                     strcpy(currentpage,backstack[backtop]);
                     backtop--;
                     printf("Current Page: %s",currentpage); 
                  }
                  break;
             case 3:
                  if(fronttop == -1){
                     printf("Forward History is empty\n");
                  }
                  else{
                     if(backtop>=SIZE-1){
                        printf("Backward history is full\n");
                        break;
                     }
                     backtop++;
                     strcpy(backstack[backtop],currentpage);
                     strcpy(currentpage,frontstack[fronttop]);
                     fronttop--;
                     printf("Current page: %s",currentpage);
                  }
                  break;  
             case 4:
                  printf("\n----------Browser Status----------\n");
                  printf("back History Top: %s\n",(backtop!=-1)?backstack[backtop]:"[EMPTY]");
                  printf("Front history Top: %s\n",(fronttop!=-1)?frontstack[fronttop]:"[EMPTY]");
                  printf("Current page: %s\n",currentpage);
                  break;
             case 5:
                  printf("Exiting........\n");
                  break;
            }
        }while(choice!=5);
     return 0;
}
 
                                 
