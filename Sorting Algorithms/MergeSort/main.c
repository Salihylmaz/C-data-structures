#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l, int m, int r){

    int i,j,k;
    int n1 = m - l + 1; // m+1 butun sol taraf
    int n2 = r - m; //size - m butun sag taraf

    int L[n1], R[n2];

    for(i = 0;i<n1;i++)
        L[i] = arr[l + i]; // L[i] = arr[i] //ba�tan ortaya
    for(j=0;j<n2;j++)
        R[j] = arr[m+1+j]; // R[j] = arr[j+m+1] m+1 ortadan sonras� i�in

    i = 0;
    j = 0;
    k = l;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i]; // arr[0] = L[i] e�itleyip k++ yap�yor. Taa ki ortaya gelene kadar
            i++;
        }
        else{
            arr[k] = R[j]; // Ortaya gelmi� ve sa� k�sm� kalan diziye ekliyor
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

//l = left index =0 olacak, r = right index = arr_size-1
void mergesort(int arr[], int l, int r){

    if(l < r){
        int m  = l + (r-l)/2;
        //mant�ken 0 ve 8 olsun ve 0 < 8 oldu�u i�in bu blo�a girecek
        //ard�ndan 0 + (8-0)/2 = 4 olacak m ortas� yani sonra s�rekli ikiye b�lecek taa ki b�l�nmeyene kadar
        mergesort(arr,l,m);   // ilk yar� // leftten m ye kadar
        mergesort(arr,m+1,r); // ikinci yar� san�rsma // m+1 den righta kadar
        merge(arr,l,m,r);
    }

}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergesort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;
}
