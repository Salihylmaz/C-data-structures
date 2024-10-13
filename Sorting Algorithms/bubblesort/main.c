#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void bubble_sort(int dizi[],int size){

    bool swapped = false;
    for(int i =0;i<size -1 ;i++){

        for(int j=0;j<size -i-1;j++){
            if(dizi[j]>dizi[j+1]){
                swap(&dizi[j],&dizi[j+1]);
                swapped = true;
            }

        }
        if (swapped == false)
            break;
    }


}


void print_array(int dizi[], int size){
    for(int i =0;i<size;i++){
        printf("%d ",dizi[i]);
    }
}

int main()
{
    int dizi[] = {24,52,63,12,98,78};
    int size = sizeof(dizi)/sizeof(dizi[1]);
    print_array(dizi,size);
    printf("\nSorted array:");
    bubble_sort(dizi,size);
    print_array(dizi,size);

    return 0;
}
