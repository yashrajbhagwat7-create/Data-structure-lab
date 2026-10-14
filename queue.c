#include<stdio.h>

#define MAX 50




int queue[MAX];

int front = -1;
int rear = -1;


//a.add patient 


void add(int patientID){

     if(rear==MAX-1){
         printf("Queue is full\n");
         return;
         }
     
        front = 0;
        rear++;
        queue[rear]=patientID;
        
        printf("Patient %d added to queue\n",patientID);
       
}


//b. attend patient


void attend(){

     if(front ==- 1 || front >rear){
        printf("No patient waiting\n");
        }


     printf("Patient %d is being attended\n",queue[front]);
     front++;
     if(front>rear){
        rear=-1;
        front=-1;
     }

}
void view(){
     int i;
     if(front == -1){
        printf("No  patient waiting\n");
        return;
     }
     printf("patients currently waiting.\n");
     for(i=front; i<=rear; i++){
         printf("patient ID: %d\n",queue[i]);
     }
}


//check if queue is empty or not \



void isQueueempty(){
     if(front == -1){
         printf("Queue is empty");
     }
     else{
         printf("Queue is not empty");
     }
}


int main(){
    int choice;
    int patientID;
    do{
        printf("\n--------Hospital Patient registration ----------\n");
        printf("1. add patient \n");
        printf("2. Attent Patient \n");
        printf("3. view Patient \n");
        printf("4. check queue Empty\n");
        printf("5. Exit");

        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        
        switch(choice){
              case 1:
                 printf("Enter the Patient ID:");

                 scanf("%d",&patientID);
                 add(patientID);
                 break;
              case 2:
                 attend();
                 break;
              case 3:
                 view();
                 break;
              case 4:
                 isQueueempty();
                 break;
              case 5:

                 return 0;
        default:
              printf("Invalid choice");
           }
     }while(choice);
     return 0;
}
