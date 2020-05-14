//https://www.spoj.com/problems/TOPOSORT/
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int n, m;
int parent[1000000];
std::vector<std::vector<int>> tasks;

//counts the number of tasks that need doing before yours.
void init() {
    for (int i = 0; i < n; ++i) {
        int j = 0;

        while( j < n ) {
            if(std::find(tasks[i].begin(), tasks[i].end(), j) != tasks[i].end()) {
                parent[j]++;
            }
            j++;
        }
    }
}


void printArr(std::vector<int> vec) {
    for (int i : vec) {
        std::printf("%d " , i + 1);
    }

    std::printf("\n");
}


void kahn() {
    //init();
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; 
    std::vector<int> res;

    for (int i = 0; i < n; ++i) {
        if(parent[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int index = pq.top();
        pq.pop();
        res.push_back(index);

        for (size_t i = 0; i < tasks[index].size(); ++i) {
            if(0 == --parent[tasks[index][i]]) {
                pq.push(tasks[index][i]);
            }
        }
    }

    if(res.size() < n) {
        std::printf("Sandro fails.\n");
    } else {
        printArr(res);
    }
}

int main() {
    
    std::scanf("%d %d", &n, &m);

    int before, after;
    tasks.reserve(n);

    for (int i = 0; i < m; ++i) {
        std::scanf("%d %d", &before, &after);
        tasks[before - 1].push_back(after - 1);
        parent[after - 1]++;
    }
    
    kahn();   
}
