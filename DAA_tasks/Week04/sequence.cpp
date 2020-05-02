#include <cstdio>
#include <iostream>
#include <stdio.h>

long sequ[1000000];


int main(void) {
    long n, k, res, counter = 0, startElement = 0;

    std::scanf(" %ld %ld", &n, &k); 
    
    for (int i = 0; i < n; ++i) {
        std::scanf(" %ld", &sequ[i]); 

        if(startElement > sequ[i]) {
            if(counter >= k) {
                res = sequ[i - counter];
            }

            counter = 0;
        } else {
            counter++;
        }
    }

    std::printf("%ld\n", res);
    

    return 0;
}
