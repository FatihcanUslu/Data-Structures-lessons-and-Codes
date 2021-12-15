#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayac=0;
    char kelime[12][20]={"nicin","neden","makam","madam","kulluk","idadi","utu","fatih","can","greapingpuke","asdffdsa","zxccxz"};
    for(int i=0;i<12;i++){
        //printf("%c",kelime[i]);
        int t=palindrom(kelime[i],strlen(kelime[i]),sayac);
        //printf("%d",strlen(kelime[i]));
        }
    return 0;
}

int palindrom(char* metin,int max,int min){// char* yapmadan hata alýyorum nedenini bilmiyorum
//printf("%d \n",strlen(metin)); deneme satýrý
//printf("%c %c \n",metin[min],metin[max-1]);
if(min==max-5)
    printf("polindromdur \n");
if(metin[min]==metin[max-1]){
    return palindrom(metin,max-1,min+1);
}

else if ((metin[min]!=metin[max]))
    printf("palindrom degil \n");
return 0;
}
