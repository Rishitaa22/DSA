#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
  char url[100];
  struct Node*prev;
  struct Node*next;
};
struct Node*current=NULL;
struct Node*createNode(char*url){
  struct Node*newNode=(struct Node*)
  malloc(sizeof(struct Node));
  strcpy(newNode->url,url);
  newNode->prev=NULL;
  newNode->next=NULL;
  return newNode;
}

void openPage(char*url){
  struct Node*newNode=createNode(url);
  if (current!=NULL){
    struct Node*temp=current->next;
    while(temp!=NULL){
      struct Node*toDelete=temp;
      temp=temp->next;
      free(toDelete);
    }
    current->next=newNode;
    newNode->prev=current;
  }
  current=newNode;
  printf("Opened:%s\n",current->url);
}
void goBack(){
  if(current!=NULL && current->prev!=NULL){
    current=current->prev;
    printf("Back to:%s\n",current->url);
  }else{
    printf("No previous page\n");
  }
}
void goForward(){
  if(current!=NULL&& current->next!=NULL){
    current=current->next;
    printf("Forward to:%s\n",current->url);
  }else{
    printf("No forward page\n");
  }
}
void displayCurrent(){
  if(current!=NULL){
    printf("current page:%s\n",current->url);
}else{
    printf("No page Opened\n");
}
}
int main(){
  int choice;
  char url[100];
  while(1){
    printf("--Menu--\n");
    printf("1.Open New page\t2.Back\t3.Forward\t4.Current page\t5.Exit\n");
    printf("Enter Choice:");
    scanf("%d",&choice);
    switch(choice){
      case 1:printf("Enter URL:");
            scanf("%s",url);
            openPage(url);
            break;
      case 2:goBack();      
            break;
      case 3:goForward();
             break;      
      case 4:displayCurrent();
             break;      
      case 5:printf("Exiting Program\n");
             exit(0);
             break;
      default:printf("Invalid choice\n");      
    }
  }
  return 0;
}
