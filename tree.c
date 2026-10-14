#include<stdio.h>
#include<stdlib.h>

struct Node {
       int rollno;
       char name[50];
       struct Node*left;
       struct Node*right;
};





//function to creat new node

struct Node* creatnode(int rollno, const char* name){
       struct Node* newnode =( struct Node* ) malloc (sizeof(struct Node));
       newnode->rollno = rollno;
       printf(newnode->name, sizeof(newnode->name),"%s",name);
       newnode->left = NULL;
       newnode->right = NULL;
       return newnode;
}


//a.add a new student record into a tree


struct Node* insert(struct Node* root, int rollno , const char* name){
       if(root == NULL){
          return creatnode(rollno , name);
       }
       if(rollno <root->rollno){
          root->left = insert(root->left, rollno, name);
       }
       else if(rollno> root->rollno){
          root->right = insert(root->right, rollno, name);
       }
       else{
           printf("Roll number %d already exists\n",rollno);
       }
       return root;
}

//helper function to find the node with minimum roll no 


struct Node* findmin(struct Node* node){
       struct Node* current  = node;
       while(current && current ->left !=NULL){
            current = current->left;
       }
       return current;
}




//b. remove a student record based on roll no \


struct Node* deletenode(struct Node* root, int rollno){
       if(root == NULL){
          return root;
       }
       if(rollno<root->rollno){
          root->left = deletenode(root->left , rollno);
       }
       else if( rollno > root->rollno){
          root->right = deletenode(root->right ,rollno);
       }
       else{
           //nod ewith only once chikld or no child
          if(root->left ==NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
          }
          else if(root->right == NULL){
            struct Node* temp= root->left;
            free(root);
            return temp;
          }
          //node with two childre get the inorder sequence 
          struct Node* temp = findmin(root->right);
          //copy the inorder successor's content to this node
          root->rollno = temp->rollno;
          printf(root->name,sizeof(root->name), "%s",temp->name);
          //delete the inorder sequence
          root->right = deletenode(root->right,temp->rollno);
          }
      return root;
}



//c.search for a specific student by rol number 

struct Node* search( struct Node* root, int rollno){
       if(root== NULL || root->rollno == rollno){
          return root;
        }
       if(root->rollno<rollno){
          return search(root->right,rollno);
        }
       return search(root->left,rollno);
}




//d. dsiplay student using inorder traversal(left,root, right)



void inorder(struct Node* root){
     if(root != NULL){
        inorder(root->left);
        printf("Roll No:%d | Name: %s \n",root->rollno,root->name);
        inorder(root->right);
     }
}



//d. display student in preorder traversal(root , left right)


void  preorder(struct Node* root){
      if(root!= NULL){
        printf("Roll No: %d | Name:%s\n",root->rollno, root->name);
        preorder(root->left);
        preorder(root->right);
      }
}



//d.display student in post order traversal( left right root)




void postorder(struct Node* root){
     if(root!=NULL){
       postorder(root->left);
       postorder(root->right);
       printf("Roll No : %d | Name: %s \n",root->rollno, root->name);

      }

}




int main(){
    int rollno, choice;
    char name[50];
    struct Node* root=NULL;
    do{
      printf("================student BST management==============");
      printf("1. add new student record\n");
      printf("2. remove a student record \n");
      printf("3. search for student record\n");
      printf("4. display records ( inorder)\n");
      printf("5. display records ( preorder)\n");
      printf("6. dsiplay records ( postorder) \n");
      printf("7. exit\n");
      switch(choice){
           case 1:
              printf("enter roll number:\n");
              scanf("%d",&rollno);
              printf("enter the name:\n");
              scanf("%s", &name);
              root = insert(root,rollno,name);
              break;
           case 2:
              printf("enter roll number to remove\n");
              scanf("%d",rollno);
              root= deletenode(root,rollno);
              printf("Record removed  \n");
              break;
           case 3:
              printf("Enter the roll number to search\n");
              scanf("%d",&rollno);
              struct Node* found = search(root, rollno);
              if(found != NULL){
                 printf("Roll No: %d | Name: %s\n", found->rollno , found->name);
              }
              else{
                 printf("Student wit rollno %d not found\n",rollno);
              }
              break;
           case 4:
              printf("=====inorder traversal=======\n");
              inorder(root);
              break;
           case 5:
              printf("=====preorder traversal======\n");
              preorder(root);
              break;
           case 6:
              printf("====postorder traversal======\n");
              postorder(root);
              break;
           case 7: 


              printf("\nExiting programm......\n");
              exit(0);
           default:
              printf("invalid choice please try again");
             }
       }while(choice);
return 0;
}
            
               
     
     
