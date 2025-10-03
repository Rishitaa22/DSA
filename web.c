Program:
#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct Node{
char url[100];
int prev;
int next;
}Node;
Node pages[MAX];
int current =-1;
int last =-1;
int createNode(char *url){
if(last>=MAX-1){
printf("History is Full :\n");
return -1;
}last++;
strcpy(pages[last].url,url);
pages[last].prev=-1;
pages[last].next=-1;
return last;
}
void visitPage(char *url){
int newNode = createNode(url);
if(newNode ==-1)
return;
if(current!=-1){
pages[current].next = -1;
pages[newNode].prev = current;
pages[current].next = newNode;
}
current = newNode;
printf("Visited: %s\n",pages[current].url);
}
void goBack(){if (current==-1||pages[current].prev==-1){
printf("No Previous pages!\n");
}else {
current = pages[current].prev;
printf("Went Back : %s\n",pages[current].url);
}
}
void goForward(){
if (current==-1||pages[current].next ==-1){
printf("No Forward pages!\n");
}else {
current = pages[current].next;
printf("Went Forward : 
%s\n",pages[current].url);
}
}
void showCurrent(){
if(current ==-1){
printf("No pages currently open!\n");
} else{printf("Current pages 
:%s\n",pages[current].url);
}
}
int main(){
int choice;
char url[100];
while(1){
printf("\n \t Browser Navigation \t\n");
printf("1. Visit page \n");
printf("2. Go Back \n");
printf("3. Go Forward \n");
printf("4. Show current page \n");
printf("5. Exit \n");
printf("Enter the choice :");
scanf("%d",&choice);
getchar();
switch (choice){
case 1:
printf("Enter the URL:");fgets(url,sizeof(url),stdin);
url[strcspn(url,"/n")]=0;
visitPage(url);
break;
case 2:
goBack();
break;
case 3:
goForward();
break;
case 4:
showCurrent();
break;
case 5:
printf("Exiting the program!\n");
return 0;
default :
printf("invalid Choice!\n");
}
}
}
