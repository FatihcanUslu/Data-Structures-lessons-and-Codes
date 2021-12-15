#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int * CopiedselectionSortforproblemB(int last){
    //printf("%d",last);
    int list[last];
    for(int i=0;i<last;i++){
        list[i]=rand()%100000;
    }
    for(int i=0;i<last;i++)
   {
     //printf("\nElement number %d::%d",i+1,list[i]);
   }


    //////////////////////////////////////////////////////////////////////////////////////////
// Local Declarations
int smallest;
int holdData;
// Statements
for (int current = 0; current < last; current++)
 {
 smallest = current;
 for (int walker = current + 1;
 walker <= last;
 walker++)
 if (list[ walker ] < list[ smallest ])
     smallest = walker;
 // Smallest selected: exchange with current
 holdData = list[ current ];
 list[current] = list[ smallest ];
 list[smallest] = holdData;
 } // for current

 //////////////////////////////////////
for (int current = 0; current < last; current++)//selectionsort için
 {
 smallest = current;
 for (int walker = current + 1;
 walker <= last;
 walker++)
 if (list[ walker ] < list[ smallest ])
     smallest = walker;
 // Smallest selected: exchange with current
 holdData = list[ current ];
 list[current] = list[ smallest ];
 list[smallest] = holdData;
 }
  //for(int i=0;i<500;i++){printf("\nElement number %d::%d",i+1,list[i]);}




return list;
} // selectionSort

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int * CopiedselectionSortForProblemC(int last){
    //printf(last);
    int list[last];
    for(int i=0;i<last;i++){
        list[i]=rand()%100000;
    }
    for(int i=0;i<last;i++)
   {
     //printf("\nElement number %d::%d",i+1,list[i]);
   }



// Local Declarations
int smallest;
int holdData;
// Local Declarations
int largest;
// Statements
for (int current = 0; current < last; current++)
 {
 largest = current;
 for (int walker = current + 1;
 walker <= last;
 walker++)
 if (list[ walker ] > list[ largest ])
     largest = walker;

 holdData = list[ current ];
 list[current] = list[ largest ];
 list[largest] = holdData;
 } // for current


  //for(int i=0;i<500;i++){printf("\nElement number %d::%d",i+1,list[i]);}

 //////////////////////////////////////
for (int current = 0; current < last; current++)//selectionsort için
 {
 smallest = current;
 for (int walker = current + 1;
 walker <= last;
 walker++)
 if (list[ walker ] < list[ smallest ])
     smallest = walker;
 // Smallest selected: exchange with current
 holdData = list[ current ];
 list[current] = list[ smallest ];
 list[smallest] = holdData;
 }
  //for(int i=0;i<500;i++){printf("\nElement number %d::%d",i+1,list[i]);}




return list;
} // selectionSort

int main()
{
double time_spent = 0.0;
clock_t begin = clock();
int number_of_element=500000;

//a bolumu için
/*


    int array[number_of_element];
    for(int i=0;i<number_of_element;i++){
        array[i]=rand()%100000;
    }
    for(int i=0;i<number_of_element;i++)
   {
    // printf("\nElement number %d::%d",i+1,array[i]);
   }
    selectionSort(array,number_of_element);


   clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("gecen zaman %f saniye", time_spent);

*/
//a bolumu için

//b bolumu için
/*
int array[number_of_element];
    for(int i=0;i<number_of_element;i++){
        array[i]=i+1;
        //printf("%d \n",array[i]);

    }
selectionSort(array,number_of_element);

   //int* array2;
    //array2=CopiedselectionSortforproblemB(number_of_element);

    clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("gecen zaman %f saniye", time_spent);
*/
//b bolumu için

//c bolumu için

int array[number_of_element];
for(int i=number_of_element;i>0;i--){
        array[i]=i;
        //printf("%d \n",array[i]);

    }
selectionSort(array,number_of_element);

    //int* array3;
   // array3=CopiedselectionSortForProblemC(number_of_element);

    clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("geçen zaman %f saniye", time_spent);


//c bolumu için





    return 0;
}





/* ================== selectionSort ===================
Sorts list [1…last] by selecting smallest element in
unsorted portion of array and exchanging it with
element at beginning of the unsorted list.
 Pre list must contain at least one item
 last contains index to last list element
 Post list has been sorted smallest to largest
*/

void selectionSort (int list[], int last)
{
// Local Declarations
int smallest;
int holdData;
// Statements
for (int current = 0; current < last; current++)
 {
 smallest = current;
 for (int walker = current + 1;
 walker <= last;
 walker++)
 if (list[ walker ] < list[ smallest ])
     smallest = walker;
 // Smallest selected: exchange with current
 holdData = list[ current ];
 list[current] = list[ smallest ];
 list[smallest] = holdData;
 } // for current


  for(int i=0;i<500;i++){
        //printf("\nElement number %d::%d",i+1,list[i]);
        }




return;
} // selectionSort

