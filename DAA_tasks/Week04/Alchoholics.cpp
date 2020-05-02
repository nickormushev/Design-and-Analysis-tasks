#include <stdio.h>
#include <iostream>

int a[100000], b[100000];
bool check(int x, int n) {
    long long nextStateOffset = b[0]; 
    for (int i = 0; i < n - 1; ++i) {
        //std::cout << "b[" << i << "]: " << nextStateOffset << std::endl; 
        if(nextStateOffset < x) {
            nextStateOffset = b[i + 1] - ((a[i + 1] - a[i]) + (x - nextStateOffset));
        } else if(nextStateOffset > x && ((nextStateOffset - x) - (a[i + 1] - a[i])) > 0) {
            nextStateOffset =  b[i + 1] + (nextStateOffset - x) - (a[i + 1] - a[i]);  
        } else {
            nextStateOffset = b[i + 1];
        }
    }

    //std::cout << "b[n - 1]: " <<  nextStateOffset << std::endl; 
    //here nextStateOffset should equal the remaining alchohol for the last building
    return nextStateOffset >= x;
}

int maxRakia(int l, int r, int n) {
    int m;
    int lastTrue = 0;
    
    while(l <= r) {
        m = (l + r)/2;

        if(check(m, n)) {
            lastTrue = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return lastTrue;
}

int main() {
    int n;
    
    std::scanf("%d", &n);
    
    int r = 0;

    for (int i = 0; i < n; ++i) { 
        std::scanf("%d %d", &a[i], &b[i]);
        if(b[i] > b[r]) {
            r = i;
        }
    }
    
    //std::cout << "RESULT: " << check(51, n) << std::endl;
    int res = maxRakia(0, b[r], n);
    std::printf("%d\n", res);
    
}
