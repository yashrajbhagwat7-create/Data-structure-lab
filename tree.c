#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node{
char name[20];
int rollno;

struct Node *left;
struct Node *right;
};


//creat a Tree node

struct Node* createnode(int rollno ,const char *name){

struct Node*newnode = (struct Node*)malloc(sizeof(struct Node));
newnode ->rollno=rollno;

snprintf(newnode->name,sizeof(newnode->name),"%s",name);

newnode->left=NULL;
newnode->right=NULL;
return newnode;


}


//insert a record


struct Node * insert(struct Node*root , int rollno,const char* name){

if(root==NULL){
return  createnode(rollno,name);
}

if(root->rollno<rollno){
root->right = insert(root->right,rollno,name);
}
else if(root->rollno>rollno){
root->left = insert(root->left,rollno,name);
}

else{
printf("roll no already exists\n");
}
return root;
}


//helper function to find the minimin

struct Node* findmin(struct Node* node){
struct Node* current =node;
while(current && current->left!=NULL){
current=current->left;
}
return current;
}


//delete node

struct Node* delete(struct Node* root,int rollno){

if(root==NULL){
return root;}


if(root->rollno<rollno){
root->right=delete(root->right,rollno);
}
else if(root->rollno>rollno){
root->left= delete(root->left,rollno);
}

else{
   if(root->left==NULL){
      struct Node* temp = root->right;
      free(root); 
      return temp;
 }

   else if(root->right ==NULL){
      struct Node*temp = root->left;
      free(root);
      return temp;
   }
   struct Node *temp = findmin(root->right);
   root->rollno= temp->rollno;
   snprintf(root->name, sizeof(root->name),"%s",temp->name);
   root->right = delete(root->right,temp->rollno);
  }
return root;
}

//search 

struct Node* search(struct Node* root, int rollno){
   if(root==NULL|| root->rollno==rollno){
return root;
}

if(rollno>root->rollno){
return search(root->right,rollno);
}
return search(root->left,rollno);
} 

      
//traversal 

void inorder(struct Node* root){
    if(root!=NULL){
     inorder(root->left);
     printf("Roll NO: %d || Name: %s \n",root->rollno,root->name);
     inorder(root->right);
     }
}
void preorder(struct Node* root){
if(root!=NULL){
printf("Roll No: %d || Name: %s\n",root->rollno,root->name);
preorder(root->left);
preorder(root->right);
}

}

void postorder(struct Node*root){
if(root!=NULL){
postorder(root->left);
postorder(root->right);
printf("Rollno: %d || Name: %s \n",root->rollno,root->name);

}
}



int main(){
int choice;

char name[20];
struct Node *root = NULL;

int rollno;


do {
   printf("\n==================Tree==================\n");
   printf("1.add student\n");
   printf("2.remove student\n");
   printf("3.search \n");
   printf("4.display inorder\n");
   printf("5.display preoder\n");
   printf("6.display postorder\n");
   printf("7.exit........\n");
   printf("enter choice\n");
   scanf("%d",&choice);
   switch(choice){
          case 1:
             printf("Enter name:\n");
             scanf("%s",name);
             printf("Enter roll no:\n");
             scanf("%d",&rollno);
             root=insert(root,rollno , name);
             break;
          case 2:
             printf("enter the roll no:\n");
             scanf("%d",&rollno);
             root = delete(root,rollno);
             break;
          case 3:{
             
             printf("Enter the rollno:\n");
             scanf("%d",&rollno);
             struct Node* found = search(root,rollno);
             if(found!=NULL){
                 printf("record found \n Rollno: %d || Name: %s\n",found->rollno,found->name);
             }
             else{ 
                 printf("Record Not found\n");}
 
             break;}
         case 4:
             inorder(root);
             break;
         case 5:
             preorder(root);
             break;
         case 6:
             postorder(root);
             break;
         case 7:
             exit(0);
         }
}while(choice!=7);


return 0;

}
          
