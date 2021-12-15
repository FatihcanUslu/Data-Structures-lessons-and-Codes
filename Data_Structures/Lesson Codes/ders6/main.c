
#include <stdio.h>
#include <stdlib.h>

struct n{
 int x;
 struct n * next;
 struct n * prev;
};

typedef struct n node;

void bastir( node * r){
   while (r != NULL){
    printf("%d ", r->x);
  r = r -> next;
 }
 printf("\n");
}


node * ekleSirali ( node * r, int x){
 if( r == NULL){//herhangi bir eleman yokken onemli olan nokta nasilki next null degerini gosteriyorsa prev degeride null gostermelidir
  r = (node *) malloc ( sizeof ( node) );
  r -> next = NULL;
  r->prev =NULL;
  r -> x = x;
  return r;
 }
 if(r->x > x){//r den kucuk bir sayi gelirse root degisecek
  node * temp = ( node * ) malloc ( sizeof ( node ) );
  temp -> x = x;
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
 return r;
}

node * sil(node *r, int x){
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
  printf( "Sayi bulunamadi!\n" );
  return r;
 }
 temp = iter->next;
 iter->next = iter->next->next;
 free (temp);
 if(iter->next!=NULL)//eger en son elemani silmiyor isek bu islemi gerceklestir
    iter->next->prev =iter;
 return r;
}

int main ()
{

 node * root;
 root = NULL;
 root = ekleSirali( root, 400);
 root = ekleSirali( root, 40);
 root = ekleSirali( root, 4);
 root = ekleSirali( root, 450);
 root = ekleSirali( root, 50);
 root = sil( root, 50);
 bastir(root);
 root = sil( root, 999);
 bastir(root);
 root = sil( root, 4);
 bastir(root);
 bastir(root);
 root = sil( root, 121);


 bastir(root);
}

//cift bagli liste



