
#include <stdio.h>
#include <stdlib.h>

struct n{
 int x;//ogrenci no
 struct n * next;//ileri gidis
 struct n * prev;//geri gidis
 char* ad;//char* yaptim cunku pointer tipinde olursa karakter boyutu sinirlandimamis olurum
 char* soyad;
 char*bolum;
 char*sinif;

};

typedef struct n node;

void bastir( node * r){//ekrana yazdirma (display list)
   while (r != NULL){
    printf("%d : %s %s %s %s", r->x, r->ad,r->soyad,r->bolum,r->sinif);
  r = r -> next;
  printf("\n");
 }
 printf("\n");
}


node * ekleSirali ( node * r, int x,char* ad,char* soyad,char* bolum,char* sinif){//link list olusturma ve sirali bir bicimde eleman ekleme (create link ve add node)
 if( r == NULL){//herhangi bir eleman yokken onemli olan nokta nasilki next null degerini gosteriyorsa prev degeride null gostermelidir
  r = (node *) malloc ( sizeof ( node) );
  r -> next = NULL;
  r->prev =NULL;
  r -> x = x;
  r->ad=ad;
  r->soyad=soyad;
  r->bolum=bolum;
  r->sinif=sinif;
  return r;
 }
 if(r->x > x){//r den kucuk bir sayi gelirse root degisecek
  node * temp = ( node * ) malloc ( sizeof ( node ) );
  temp -> x = x;

  temp->ad=ad;
  temp->soyad=soyad;
  temp->bolum=bolum;
  temp->sinif=sinif;

  temp -> next = r;
  r->prev=temp;
  //r=temp;
  return temp;//root degeri degistigi ici yeniden dondurulmeli
 }
 node * iter = r;
 while( iter -> next != NULL && iter -> next -> x < x ){//iter eklenecek arayi buldu
  iter = iter -> next;
 }

 node * temp = (node*)malloc(sizeof(node));
 temp->next = iter->next;
 iter->next = temp;
 temp->prev=iter;
 if(temp->next=NULL)//bu kontrolun sebebi normalde ortalardaki iki elemani birbirine baglarken sondaki elemandan araya giren elemana prev baglanmasi gerekir . eger bizim sondaki elemanimiz yoksa yani NULL ise bu durumda NULL'un prev degeri olmadigi icin bir islem yapmamaliyiz.
    temp->next->prev=temp;
 temp->x = x;
 //elemanin ozellikleri
 temp->ad=ad;
 temp->soyad=soyad;
 temp->bolum=bolum;
 temp->sinif=sinif;

 return r;
}

node * sil(node *r, int x){//eleman silme (delete node)
 node *temp;
 node *iter = r;
 if( r->x == x){//ilk eleman siliniyor
   temp=r;
   r=r->next;
   free(temp);
   return r;//yeni root artik iter->next'i bunu geri donduruyoruz
 }

 while ( iter->next != NULL && iter->next->x != x){
  iter = iter->next;
 }
 if ( iter->next == NULL){
  printf( "%d'no lu ogrenci bulunamadi!\n",x );
  return r;
 }
 temp = iter->next;
 iter->next = iter->next->next;
 free (temp);
 if(iter->next!=NULL)//eger en son elemani silmiyor isek bu islemi gerceklestir
    iter->next->prev =iter;
 return r;
}
void arama(node*r,int x)//(search node)
{
    node*iter=r;
    if(r==NULL)//eger listte eleman yoksa
    {
        printf("listede bastirilacak eleman yok");
    }

    else if(iter->x==x)//eger 1. eleman ise
    {
        printf("%d : %s %s %s %s\n", iter->x, iter->ad,iter->soyad,iter->bolum,iter->sinif);
    }
    else if(r->next!=NULL)//eger 1. eleman deilse
    {
        while( iter -> next != NULL && iter -> next -> x != x ){//iter eklenecek elemani ariyor buldu
  iter = iter -> next;
 }
    if(iter->next==NULL)
    {
        printf("listenin son elemanina kadar dondum ancak istenilen degeri bulamadim\n");
    }
    else if(iter->next->x==x)
    {
        printf("%d : %s %s %s %s\n", iter->next->x, iter->next->ad,iter->next->soyad,iter->next->bolum,iter->next->sinif);
    }
    }

}
node*destroylist(node*r)//(destroy list)node* olmasinin sebebi root icerisinde degisiklik yaptiktan sonra root'u geri dondurmezsem degisiklik yapilmis sayilmaz
{
    r=NULL;
    free(r);
    return r;
}

int main ()
{

 node * root;
 root = NULL;
 printf("create linked list ve add node islemleri siraliekle icerisinde gerceklesmektedir ;\n");
 printf("eklenen ilk eleman root'u yani linked listi olusturur 2. eleman ise add node islemini gerceklestirir\n");
 printf("ayni zamanda eklenen dugumler ogrenci numaralarina gore sirali olarak eklenir\n");
 printf("*************************************************************\n\n");
 root = ekleSirali( root, 1012,"ahmet","gider","computer science","3.sinif");
 root = ekleSirali( root, 1023,"ayse","durur","computer science","1.sinif");
 root = ekleSirali( root, 2012,"fatih","uslu","computer science","2.sinif");
 root = ekleSirali( root, 3021,"gezi","kulunk","computer science","3.sinif");
 root = ekleSirali( root, 1000,"yunus","bilgin","computer science","4.sinif");
 root = ekleSirali( root, 4000,"huseyin","ergul","computer science","1.sinif");
 root = ekleSirali( root, 5000,"ahmaaad","gezgin","computer science","3.sinif");
 root = ekleSirali( root, 6000,"ezgi","nova","computer science","3.sinif");
 printf("eger silinecek eleman bulunamazsa hatanin geri donduruldugu satir:\n\n");
 root = sil( root, 2);//eleman silme islemi
 root = sil( root, 6001);
 root = sil( root, 6000);
 root = sil( root, 3021);
printf("\n\n*************************************************************\n\n");
printf("listedeki elemanlarin gosterildigi satir:\n\n");
 bastir(root);
printf("\n\n*************************************************************\n\n");
printf("listedeki istenilen elemanin aranip bulundugu satir:\n\n");

arama(root,5000);
arama(root,1000);
arama(root,1023);
arama(root,2032);
arama(root,1000);
printf("\n\n*************************************************************\n\n");
printf("linked list'i yok etme , sonrasinda elemanlari kontrol etme:\n\n");
root=destroylist(root);
bastir(root);
printf("\n\n*************************************************************\n\n");

    //listeyi komple silme isleminden sonra tekrardan hatasiz bir sekilde yeni bir liste olusturup 2 eleman ekliyorum (kontrol amacli)
    root = ekleSirali( root, 1012,"ahmet","gider","computer science","3.sinif");
    root = ekleSirali( root, 1023,"ayse","durur","computer science","1.sinif");
    bastir(root);

}

//cift bagli liste



