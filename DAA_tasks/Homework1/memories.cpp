#include <iostream>
#include <cstdio>
#include <algorithm>
//#include <set>

std::pair<int, int> a[1000000];
int n, untrustWorthy;

bool compare(std::pair<int, int> fst, std::pair<int,int> snd) {
    return (fst.second - fst.first) < (snd.second - snd.first); 
}

int main() {
    
    std::scanf(" %d", &n);
    //std::set<int> visited;

    untrustWorthy = 0;

    for (int i = 0; i < n; ++i) {
        std::scanf(" %d %d", &a[i].first, &a[i].second);
    }

   bool flag; 
    for (int i = 0; i < n; ++i) {
        flag = true;
        for (int j = 0; j < n && flag; j++) {
            if(i != j && a[i].first >= a[j].first && a[i].second <= a[j].second) {
                untrustWorthy++;
                flag = false;
            }
        }
    }

    std::printf("%d\n", untrustWorthy);
    return 0;
}
