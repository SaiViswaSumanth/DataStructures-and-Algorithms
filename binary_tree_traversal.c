#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *rightchild;
  struct node *leftchild;

};

typedef struct node NODE;

NODE *root,*newnode;

int value;

NODE *getnode(int value){
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=value;
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;
    return newnode;
}

NODE *createnode(NODE *root,int value){
  char ch;
  if(root==NULL){
    return getnode(value);
  }
  printf("The current root node is %d\n",root->data);
  printf("Enter 'l'to go left or 'r' to go right");
  scanf(" %c",&ch);
  if(ch=='l'){
    root->leftchild=createnode(root->leftchild,value);
  }else if(ch=='r'){
    root->rightchild=createnode(root->rightchild,value);
  }
  return root;
}

void preorder(NODE *root){

  while(root!=NULL){
    printf("%d ",root->data);
    preorder(root->leftchild);
    preorder(root->rightchild);
  }
}

void postorder(NODE *root){
  while(root!=NULL){
    postorder(root->leftchild);
    postorder(root->rightchild);
    printf("%d ",root->data);
  }
}

void inorder(NODE *root){
  while(root!=NULL){
    postorder(root->leftchild);
      printf("%d ",root->data);
    postorder(root->rightchild);

  }
}

void main(){
  int choice,value;

  do {
    printf("1.Insert\n2.preOrder\n3.postOrder\n4.inOrder\n");
    printf("Enter choice\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
         printf("Enter the element to be inserted\n");
         scanf("%d",&value);
         root=createnode(root,value);
         break;
      case 2:
        preorder(root);
        break;
      case 3:
        postorder(root);
        break;
      case 4:
        inorder(root);
        break;

    }
    fflush(stdin);
  } while(choice!=5);
}
