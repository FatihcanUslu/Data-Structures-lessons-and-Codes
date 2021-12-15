#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n*next;

};
typedef struct n node;


int main()
{
    node*root;//pointer root
    node*iter;
    root=(node*)malloc(sizeof(node));//node kadar alani bize ayir ben bu alani node olarak kullanicam demek istedik. node*'a cast ettik cunku malloc void* olarak alan ayirir
    root->x=10;
    root->next=(node*)malloc(sizeof(node));
    root->next->x=20;
    root->next->next=(node*)malloc(sizeof(node));
    root->next->next->x=30;
    iter=root;
    printf("%d",iter->x);
    iter=iter->next;
    printf(" %d",iter->x);

    return 0;
}
