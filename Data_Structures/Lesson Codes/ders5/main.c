
#include <stdio.h>
#include <stdlib.h>

struct n{
 int x;
 struct n * next;
};

typedef struct n node;

void bastir( node * r){
  node * iter=r;//hareket eden eleman iter
  printf("\n %d \n",iter->x);//ilk elemani bir kere elle bastirip iteri 1 next ilerlettik yoksa donguye girmeyecegi icin hata alirdik
  iter = iter -> next;
 while (iter != r){
  printf("%d ", iter->x);
  iter = iter -> next;
 }
 printf("\n");
}

void ekle( node * r, int x){//sona eleman ekleme islemi
  node * iter=r;//hareket eden eleman iter
 while( iter -> next != r){
  iter =iter -> next;
 }
 node*yeni=( node * ) malloc ( sizeof ( node ) );
 yeni->x=x;
 iter->next=yeni;
 yeni->next=r;
}

node * ekleSirali ( node * r, int x){
 if( r == NULL){
  r = (node *) malloc ( sizeof ( node) );
  r -> next = r;
  r -> x = x;
  return r;
 }
 if(r->x > x){
  node * temp = ( node * ) malloc ( sizeof ( node ) );
  temp -> x = x;
  temp -> next = r;
  node * iter=r;
  while(iter->next!=r){
    iter=iter->next;
  }
  iter->next=temp;
  return temp;
 }
 node * iter = r;
 while( iter -> next != r && iter -> next -> x < x ){
  iter = iter -> next;
 }

 node * temp = (node*)malloc(sizeof(node));
 temp->next = iter->next;
 iter->next = temp;
 temp->x = x;
 return r;
}

node * sil(node *r, int x){
 node *temp;
 node *iter = r;
 if( r->x == x){//ilk eleman siliniyor
   while(iter->next!=r){//r'ye kadar ilerliyorki r yi silebilsin
     iter=iter->next;
   }
   iter->next=r->next;
   free(r);
   return iter->next;//yeni root artik iter->next'i bunu geri donduruyoruz
 }

 while ( iter->next != r && iter->next->x != x){
  iter = iter->next;
 }
 if ( iter->next == r){
  printf( "Sayi bulunamadi!\n" );
  return r;
 }
 temp = iter->next;
 iter->next = iter->next->next;
 free (temp);
 return r;
}

int main ()
{
 node * root;
 root = NULL;
 root = ekleSirali( root, 400);
  bastir(root);
 root = ekleSirali( root, 40);
   bastir(root);
 root = ekleSirali( root, 4);
   bastir(root);
 root = ekleSirali( root, 450);
   bastir(root);
 root = ekleSirali( root, 50);
   bastir(root);
 root = sil( root, 50);
 bastir(root);
 root = sil( root, 999);
 bastir(root);
 root = sil( root, 4);
 bastir(root);
 ekle(root,121);
 bastir(root);
 root = sil( root, 121);


 bastir(root);
}

//dairesel liste ornegi


























