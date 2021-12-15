#include <stdio.h>
#include <stdlib.h>

#define F 2

int main()
{

int sayilar[50]={};
    for(int i=0;i<50;i++){
       sayilar[i]=i;
       int b=asallik(sayilar[i],F);

       printf("%d . eleman: %d \n",i+1,b);
    }

    return 0;
}

int asallik(int gelen,int G){
    if(gelen==G)
        return 1;
    if(gelen%G==0 || gelen==0 || gelen==1)
        return 0;
    else
        return asallik(gelen,G+1);


}







