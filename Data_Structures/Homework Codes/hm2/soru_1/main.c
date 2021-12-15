#include <stdio.h>
#include <stdlib.h>
 typedef struct node
{
    int data;
    void*        dataPtr;
    struct node* next;
}NODE;

struct node*head=NULL;
struct node*tail=NULL;

int addNode(int data){
if(head==NULL){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    head=tail=new;
}
else{
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    tail->next=new;
    tail=new;
}
}
addnodehead(int data){
if(head==NULL){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    head=tail=new;
}
else{
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    new->next=head;
    head=new;
}
}
int print(){

struct node*index=head;
while(index!=NULL){
    printf(" %d =",index->data);
    index=index->next;

}


}
////////////////////////////////////////////////////////UZUNLUK BULMA ISMENI GERÇEKLESTIREN FONK. BURASI . DIGER ADIMLAR LINKED LIST OLUSTURUYOR ///////////////////////

int uzunluk(struct node* sonuc,int sayi){
if(sonuc==NULL)
    return sayi;
if(sonuc!=NULL)
    return uzunluk(sonuc=sonuc->next,sayi+1);
}
// listeden data silme islemi
int delete(int data){
struct node*prev=NULL;
struct node*index=head;

//eger lists bos ise ?
if(head==NULL){
    printf("linked list zaten bos :D");
    return 1;
}
//eger silinecek olan eleman ilk eleman ise ?
if(head->data==data){
    struct node*t=head;
    head=head->next;
    free(t);
    return 1;
}
//eger silinecek olan eleman listede hic yoksa ne olucak ?
while(index!=NULL && index->data!=data){
    prev=index;
    index=index->next;

}
if(index==NULL){
    printf("istenilen elemana zaten ulasilamadi \n");
    return 1;
}

prev->next=index->next;
if(tail->data==data){
    tail=prev;
}
free(index);
return 1;
}

int main()
{
addNode(10);
addNode(11);
addNode(102);
addnodehead(15);
addNode(11);
addnodehead(1);
addnodehead(382);
delete(1);
int a=0;
struct node*sonuc=head;
print();


a=uzunluk(sonuc,a);
printf("\n %d",a);
    return 0;
}
