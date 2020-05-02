#include <cstdio>
#include <iostream>
#include <stdio.h>

int rangeCap(int a, int b, int * seqs, int n, int l, int r, int l1, int r1) {

    if(a > b) {
        return 0;
    }

    int m, m1, lastLeft = -1, lastRight = -1;

    while(l <= r || l1 <= r1) {
        m = (l + r)/2;
        m1 = (l1 + r1)/2; 

        if(l <= r && seqs[m] >= a) {
            lastLeft = m;
            r = m - 1;
        } else if (l <= r) {
            l = m + 1;
        }

        if(l1 <= r1 && seqs[m1] > b) {
            r1 = m1 - 1;
        } else if(l1 <= r1) {
            lastRight = m1;
            l1 = m1 + 1;
        }
    }
    
    if(lastRight < lastLeft || lastLeft == -1 || lastRight == -1) {
        return 0;
    }

    return (lastRight - lastLeft) + 1;
}

int main() {
    int n, m, a[10000], b[10000], seqs[100000];

    std::scanf(" %d", &n);
    for (int i = 0; i < n - 1; ++i) {
        std::scanf("%d ", &seqs[i]);    
    }

    std::scanf(" %d", &seqs[n - 1]); 
    std::scanf(" %d", &m);

    for (int i = 0; i < m; ++i) {
        std::scanf(" %d  %d", &a[i], &b[i]);    
    }

    int res;

    for (int i = 0; i < m; ++i) {
        res = rangeCap(a[i], b[i], seqs, n, 0, n - 1, 0, n - 1);
        std::printf("%d\n", res);
    }
    
    return 0;
}
