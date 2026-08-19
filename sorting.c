#include<stdio.h>


int main(){


int temp, n,roll[100],i,j;


printf("enter the number of students");

scanf("%d",&n);
printf("enter the roll number: \n");
for(i=0; i<n; i++){

    scanf("%d",&roll[i]);

}

printf("sort the roll number\n");

//Using bubble sort


for(i=0;i<n-1;i++){

     for(j=0;j<n-i-1;j++){

         if(roll[j]>roll[j+1]){

              temp=roll[j];
              roll[j]=roll[j+1];
              roll[j+1]=temp;

             }
 
         } 

    printf("pass %d: ",i+1);
  




    for(j=0; j<n; j++){

       printf(" %d",roll[j]);

                       }
    printf("\n");


   }


printf("The roll number in ascending order:");

for(i=0; i<n; i++){

    printf(" %d",roll[i]);

   } 
printf("\n");

return 0;

}




