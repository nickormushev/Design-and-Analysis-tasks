//Task: https://judge.openfmi.net/practice/get_problem_description?contest_id=84&problem_id=262 #include <cstdio> #include <cstdio>
#include <iostream>
#include <algorithm>

long aArr[1000000];
std::pair<int, long> qArr[1000];

void indexChanger(int index, int high, int low) {
    for (int i = low; i <= high; ++i) {
        qArr[i].second = index;
    }
}

int binarySearch(long sumIhave, int low, int high, int shopIndex) {
    int startLow = low; //Needed to for the print at the end
    int lastTrue = -1; //Needed to get the last 11 in this example 3 4 4 4 5 11 11 11 

    while(low <= high) {

        int mid = (low + high)/2;

        if( qArr[mid].second > sumIhave ) {
            high = mid - 1;
        } else if(qArr[mid].second < sumIhave) {
            low = mid + 1;
        } else {
            lastTrue = mid;
            low = mid + 1;
        }
    }

    if(lastTrue != -1) { //If the sum I have is in the array
        indexChanger(shopIndex, lastTrue, startLow);
        return lastTrue + 1;
    } else {
        indexChanger(shopIndex, high, startLow);
        return high + 1;
    }
}

void result(int n, int q, int k) {
    int low = 0, high = q - 1;
    long currSum = 0;
    
    for (int j = 0; j < k ; ++j) {
        currSum += aArr[j];
    }
 
    if(qArr[low].second <= currSum) { // if the currSum is lower that the one we have looked at we shouldn't enter
        low = binarySearch(currSum, low, high, 0);
    }   

    for (int i = 1; low <= high && i < n - k + 1; ++i) {
        currSum += (-aArr[i - 1]) + aArr[i + k - 1];

        if(qArr[low].second <= currSum) { // if the currSum is lower that the one we have looked at we shouldn't enter
            low = binarySearch(currSum, low, high, i);
        }
    } 

    indexChanger(-1, high, low);
}

bool compareByValue(std::pair<int, long> fst, std::pair<int, long> snd) {
    return fst.second < snd.second;
}

bool compareByIndex(std::pair<int, long> fst, std::pair<int, long> snd) {
    return fst.first < snd.first;
}

int main() {
    int n, q, k;

    std::scanf(" %d %d %d", &n, &k, &q);
    for (int i = 0; i < n; ++i) {
        std::scanf("%ld", &aArr[i]);    
    }

    for (int i = 0; i < q; ++i) {
        qArr[i].first = i;
        std::scanf(" %ld", &qArr[i].second);
    }

    std::sort(qArr, qArr + q, compareByValue);
    result(n,q,k);
    std::sort(qArr, qArr + q, compareByIndex);
    
    for(int i = 0; i < q; i++) {
        std::printf("%ld\n", qArr[i].second); 
    }

    return 0;
}
