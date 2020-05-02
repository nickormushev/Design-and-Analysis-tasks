#include <cstdio>
#include <iostream>

void printArray(int * arr, int size) {

   for(int i = 0; i < size; i++) {
       std::printf("%d ", arr[i]); 
   }

   std::printf("\n");
}

void permutate(int * arr, int low, int high, int& pivot) {
    int i = low;
    int j = high;
    
    while(i <= pivot) { 

        if(arr[i] >= arr[pivot]) {

            while(arr[j] >= arr[pivot] && j > pivot) {
                j--;
            }
           

            if(j > i) {
                std::swap(arr[i], arr[j]);
            }

            if(j > i && i == pivot) {
                pivot = j;
            } else if(j == pivot && j > i) {
                pivot = i;
                i--;
            }
        }

        i++;
    }

}

void quickSort(int * arr, int low, int high) {

    if(low >= high) {
        return;
    }

    int pivot = (low + high)/2;

    permutate(arr, low, high, pivot);
    
    quickSort(arr, low, pivot-1);
    quickSort(arr, pivot + 1, high);
}

int main() {
    int n;
    
    std::scanf(" %d", &n); 

    int * arr = new int [n];

    for(int i = 0; i < n; i++) {
        std::scanf(" %d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printArray(arr, n);

    delete[] arr;

    return 0;
}
