#include <stdio.h>
#include <stdlib.h>
int carpanlara_ayirma(int sayi,int i)
{
if(sayi%i==0)
{
while(free)
 {
    sayi=sayi/i;
    printf("%d ",i);
if(sayi==1)

    return 0;
if(sayi%i != 0)

    break;
 }
}

return carpanlara_ayirma(sayi,i+1);


}
int main()
{

    int sayilar[8]= {11,4,32,45,91,97,56,3202};
    for(int i=0; i<8; i++)
    {
        printf("%d deki sayi: ",i+1);
        carpanlara_ayirma(sayilar[i],2);
        printf("\n");
    }

    return 0;
}
