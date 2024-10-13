#include <stdio.h>
#include <stdlib.h>



void insertion_sort(int dizi[],int size){
    int key,j;
    for(int i =0;i<size;i++){
        key = dizi[i];
        j = i -1;

         while(dizi[j]>key&& j > -1){
            dizi[j+1] = dizi[j];
            j--;
         }
         dizi[j+1]= key;
    }

}

void print_array(int dizi[],int size){
    for(int i = 0;i<size;i++){
        printf("%d ",dizi[i]);
     }

}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr,n);
    print_array(arr,n);

    return 0;
}
