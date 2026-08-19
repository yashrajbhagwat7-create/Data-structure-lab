//Lab assignment : 01 */





#include<stdio.h>



int main(){


int marks[100],n=0,i,choice,pos,value;
int low ,high,mid,temp,found;

do {
printf("\n----MENU---\n");
printf("1. insert Marks \n");
printf("2. Delete marks\n");
printf("3. Display marks \n");
printf("4. Linear search\n");
printf("5. sort and binary search \n");
printf("6. Exit \n");


scanf("%d",&choice);

switch(choice){

    case 1:
        printf("enter the number of students: ");
        scanf("%d",&n);
        
        printf("enter the marks: ");
        for(i=0;i<n;i++){
           scanf("%d",&marks[i]);
        }
        break;
        
    case 2:
        printf("enter the position to delete (1-%d): ",n);
        scanf("%d",&pos);
        if (pos<1  || pos>n)
        {
           printf("invalid position\n");
        }
        else
        {
           for(i=pos; i<n; i++){
               marks[i]=marks[i+1];
        }
           n--;
           printf("mark deleted successfully.\n");
    
        }
       break;
    
    case 3:
        if(n==0)
        {
            printf("No marks available\n");
    
          }
    
       else 
       {
           printf("students marks \n");
               for(i=0;i<n;i++)
               {
                 printf("%d",marks[i]);
    
               }
    
              printf("\n");;
      }
      break;
    
    case 4:
        printf("enter the mark to search\n");
        found=0;   
        scanf("%d",&value);
    
        for(i=0;i<n;i++){
    
           if(marks[i]==value){
           printf("marks found at position %d\n",i+1);
           found = 1;
           break;
           }
         
       }
       if (found==0){
        printf("marks not found\n");
     
    }
    break;
    
    
    case 5:
    
    //sorting using bubble sort
    
        for(i=0;i<n-1;i++){
        int j;
    
             for(j=0;j<n-i-1;j++){
                   if(marks[j]>marks[i+1]){
                        temp=marks[j];
                        marks[j]=marks[j+1];
                        marks[j+1]=temp;
                        }
                   }
         }
        printf("Sorted Makrs:\n");
        for(i=0; i<n; i++){
              printf("%d",marks[i]);
     } 
    
        printf("\n");
    
    
        printf("enter the marks to search: \n");
        scanf("%d",&value);
      low=0;
      high = n-1;
      found=0;
    
      while (low<=high){
        mid=(low+high)/2;
    
        if(marks[mid]==value){
          printf("marks found at position %d(sorted array)\n",mid+1);
          found =1;
          break;
      }
        else if(marks[mid]<value){
          low=mid+1;
    
      }
        else{
          high=mid-1;
    
      }
    }
    
     if(!found){
    
         printf("marks not found\n");
    }
    break;
    
    case 6:
       printf("Exiting program...\n");
    
       break;
    
    default:
      printf("invalid choice\n");
    }
    
    
    }while (choice!=6);
    
return 0;

}
