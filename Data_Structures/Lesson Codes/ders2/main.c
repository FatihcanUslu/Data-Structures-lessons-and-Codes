#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n*next;
    struct n*before;
    char* adi;


};
typedef struct n node;

void bastir(node*r)//b�t�n node'lar� ekrana yazd�rma
{

    while (r!=NULL)
    {
        printf("\n %d \n",r->x);
        r=r->next;

    }
}
void sonaekle(node*r,int x)//sona eleman ekleme islemi
{
    while (r->next!=NULL)
    {
        r=r->next;
    }

    node* yeni=(node*)malloc(sizeof(node));//yeni gelen eleman
    yeni->x=x;
    r->next=yeni;

    yeni->next=NULL;

}
int main()
{
    node*root;//pointer root
    node*iter;
    root=(node*)malloc(sizeof(node));//node kadar alani bize ayir ben bu alani node olarak kullanicam demek istedik. node*'a cast ettik cunku malloc void* olarak alan ayirir
    root->x=120;
    root->next=NULL;
    iter=root;

    for(int i=0;i<5;i++)
    {
        sonaekle(root,i*10);

        /*eski yontem
        iter->next=(node*)malloc(sizeof(node));
        iter=iter->next;
        iter->x=i*10;
        iter->next=NULL;//sona null eklenmesi i�lemi bu sayede son eleman o anl���na olu�mu� olur
        */

    }
    bastir(root);
    return 0;
}
