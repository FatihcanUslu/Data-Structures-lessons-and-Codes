#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n*next;
    struct n*before;
    char* adi;


};
typedef struct n node;

void bastir(node*r)//bütün node'larý ekrana yazdýrma
{

    while (r!=NULL)
    {
        printf("\n %d \n",r->x);
        r=r->next;

    }
}
void sonaekle(node*r,int x)//sona eleman ekleme islemi
{


    //else{
    while (r->next!=NULL)
    {
        r=r->next;
    }

    node* yeni=(node*)malloc(sizeof(node));//yeni gelen eleman
    yeni->x=x;
    r->next=yeni;

    yeni->next=NULL;

}

node* siraliekle(node*r,int x)//sirali eleman eklemek icin //eger node* tanimlamazsan ve eger root degerinin degismesi gerekirse islemler bittikten sonra root degismez . degisikligi onaylamak icin return ile yeni rootu geri gondermelisin
{

if(r==NULL)//hic eleman yok ise
    {
        r=(node*)malloc(sizeof(node));//yeni gelen eleman
        r->next=NULL;
        r->x=x;
        return r;//root degeri degistigi icin bu adim kesinlikle yapilmalidir yoksa sistem degismemiz gibi varsayip giren r degerini geri dondurur ama r degeri degisti
    }
    if(r->x>x)//eger var olan tek eleman gelen sayidan buyuk ise gelen kutuyu link listin basina eklemeliyim
    {
        node*temp=(node*)malloc(sizeof(node));
        temp->next=NULL;
        temp->x=x;
        temp->next=r;
        r=temp;
        return r;//r degeri degistigi icin bu adim kesinlikle olmali yoksa root degismemis gibi geriye deger doner
    }
    node*iter=r;
    while(iter->next !=NULL && iter->next->x<x)//diger durumlar yani gelen elemanin daha buyuk oldugu durum
    {
        iter=iter->next;


    }


    node*temp=(node*)malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->x=x;
    return r;
}




int main()
{
    node*root;//pointer root
    node*iter;
    //root=(node*)malloc(sizeof(node));//node kadar alani bize ayir ben bu alani node olarak kullanicam demek istedik. node*'a cast ettik cunku malloc void* olarak alan ayirir
    root=NULL;
    iter=root;

    root=siraliekle(root,200);//root'un degisme ihtimalini dusunmeliyiz
    root=siraliekle(root,100);
    root=siraliekle(root,400);
    root=siraliekle(root,700);
    bastir(root);
    return 0;
}

//sirali liste ornegi

