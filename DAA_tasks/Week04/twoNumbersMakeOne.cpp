#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

int nArr[1000000], mArr[10];

bool binarySearch(int n, int key, int low) {
    int mid;
    int high = n - 1;

    while(low <= high) {
        mid = (low + high)/2;

        if(nArr[mid] < key) {
            low = mid + 1;
        } else if(nArr[mid] > key) {
            high = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}

void result(int n, int m) {
    bool res;

    for (int i = 0; i < m; ++i) {
        res = false;

        for (int j = 0; j < n && !res && mArr[i] >= sqrt(nArr[j]); j++) {
            res = binarySearch(n, mArr[i] - nArr[j], j + 1);
        }

        if(!res) {
            std::printf("%s\n", "NO");
        } else {
            std::printf("%s\n", "YES");
        }
    }
}

int main(void) {
    int n, m;
    std::scanf(" %d %d", &n, &m);  

    for (int i = 0; i < n; ++i) {
        std::scanf("%ld", &nArr[i]); 
    }
    
    for (int i = 0; i < m; ++i) {
        std::scanf("%ld", &mArr[i]);
        
    }

    std::sort(nArr, nArr + n);

    result(n,m);

    return 0;
}
