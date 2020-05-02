#include <cstdio>
#include <iostream>
#include <vector>

void printArray(int * arr, int size) {

   for(int i = 0; i < size; i++) {
       std::printf("%d ", arr[i]); 
   }

   std::printf("\n");
}

int * merge(int * arr1, int * arr2, int size1, int size2, long& counter) {
    int i = 0;
    int j = 0;
    
    int * res = new int [size1 + size2];

    while(i < size1 && j < size2) {

        if(arr1[i] <= arr2[j]) {
            res[i + j] = arr1[i];
            i++;
        } else {
            res[i + j] = arr2[j];
            counter += size1 - i;
            j++;
        }
    }

    while(i < size1) {
        res[i + j] = arr1[i];
        i++;
    }

    while(j < size2) {
        res[i + j] = arr2[j];
        j++;
    }
    
    delete[] arr1;
    delete[] arr2;

    return res;
}

int * mergeSort(int * arr, int low, int high, long& swapCounter) {

    if(low >= high) {
        int * newArr = new int [1];
        newArr[0] = arr[low];
        return newArr;
    }

    int middle = (low + high)/2;

    return merge(mergeSort(arr, low, middle, swapCounter), mergeSort(arr, middle + 1, high, swapCounter),
                middle - low + 1, high - middle, swapCounter);
}


int main() {
    int n;
    
    std::scanf(" %d", &n); 

    int * arr = new int [n];
    int * res = new int [n];

    for(int i = 0; i < n; i++) {
        std::scanf(" %d", &arr[i]);
    }

    long swapCounter = 0;
    res = mergeSort(arr, 0, n - 1, swapCounter) ;

    printf("%ld\n", swapCounter);

    delete[] res;
    delete[] arr;

    return 0;
}
