//Task: https://judge.openfmi.net/practice/get_problem_description?contest_id=37&problem_id=110
#include <cstdio>
#include <iostream>
#include <stdio.h>

long tubes[10000];

bool testLength;

bool check(int mid, int n, int k) {
    int counter = 0;

    for (int i = 0; i < n; ++i) {
        counter += tubes[i]/mid; 
    }

    return counter >= k; 
}


long tubeLength(int n, int k, long low, long high) {
    long lastMiddle;

    while(low <= high) {
        int middle = (low + high)/2;

        if(check(middle, n, k)) {
            lastMiddle = middle;
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    
    return lastMiddle;
}


void solution(int n, int k) {
    long low = -1, high = 10000000;

    for (int i = 0; i < n; ++i) {
        std::scanf(" %ld", &tubes[i]);

        if(low > tubes[i]) {
            low = tubes[i];
        } else if(high < tubes[i]) {
            high = tubes[i];
        }
    }

   std::printf("%ld\n", tubeLength(n, k, low, high));
}


int main(void) {
    int t, n, k; 

    std::scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        std::scanf(" %d %d", &n, &k); 
        solution(n,k);
    }

    return 0;
}
