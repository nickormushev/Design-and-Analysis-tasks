//https://judge.openfmi.net/practice/get_problem_description?contest_id=16&problem_id=39
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <queue>
#include <vector>

int n, m, x, y, z;
std::pair<int, std::vector<int>> distAndPath[50000];
std::vector<std::pair<int, int>> graph[100000];

using mPath = std::pair<int, std::vector<int>>;

void print(std::vector<int> v) {
    //Print minus one so the last character will not be duplicate. Plus it lets me add a new 
    //line for tests to pass
    for (size_t i = 0; i < v.size() - 1; ++i) { 
        std::printf("%d ", v[i] + 1); 
    }   
}

void dijkstra(int start = x) {
    std::priority_queue<mPath, std::vector<mPath>, std::greater<mPath>> pq;

    for (int i = 0; i < n; ++i) {
        distAndPath[i].first = -1;
        distAndPath[i].second.clear();
    }

    pq.push({0, {start}});
    distAndPath[start] = {0, {start}};

    while(!pq.empty()) {
        std::vector<int> cPath = pq.top().second;
        int curr = cPath[cPath.size() - 1];

          for (size_t i = 0; i < graph[curr].size(); ++i) {
            std::pair<int,int> child = graph[curr][i];

            if(distAndPath[child.first].first > distAndPath[curr].first + child.second || distAndPath[child.first].first == -1) {
                distAndPath[child.first].first = distAndPath[curr].first + child.second; 

                cPath.push_back(child.first);
                distAndPath[child.first].second = cPath;

                pq.push({distAndPath[child.first].first, cPath});
                cPath.pop_back();
            }
        }
        pq.pop();
    }
}

int main() {
    int from, to, w;
    std::scanf(" %d %d %d %d %d", &n, &m, &x, &y, &z);
    x--;
    y--;
    z--;
    
   // graph.reserve(n);

    for (int i = 0; i < m; ++i) {
        std::scanf(" %d %d %d", &from, &to, &w);
        graph[from - 1].push_back({ to - 1, w });
        graph[to - 1].push_back({ from - 1, w });
    }

    int cost;
    std::vector<int> res;

    dijkstra();
    cost = distAndPath[y].first;
    if(cost == -1) {
        std::printf("%d\n", -1);
        return 0;
    }
    res = distAndPath[y].second;

    dijkstra(y);

    if(distAndPath[z].first == -1) {
        std::printf("%d\n", -1);
        return 0;
    }

    std::printf("%d\n", cost + distAndPath[z].first);
    print(res);
    res = distAndPath[z].second;
    print(res);
    std::printf("%d\n", res[res.size() - 1] + 1);
}
