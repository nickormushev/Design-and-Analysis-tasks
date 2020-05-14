//https://judge.openfmi.net/practice/get_problem_description?contest_id=55&problem_id=157
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>

int n, x, y, m;
long dist[100000]; 
std::vector<std::vector<std::pair<int,int>>> graph;

auto cmp = [](const std::pair<int, long>& lhs, const std::pair<int, long>& rhs) {
    return lhs.second >= rhs.second;
};

long djikstra(int start = x, int destination = y) {
    std::priority_queue<std::pair<int, long>, std::vector<std::pair<int, long>>, decltype(cmp)> pq(cmp); 
    std::pair<int, long> curr;
    pq.push({start, 0});
    dist[start] = 0;

    while(!pq.empty()) {
        curr = pq.top();

        for (size_t i = 0; i < graph[curr.first].size(); ++i) {
            std::pair<int,int> child = graph[curr.first][i];

            if(dist[child.first] > dist[curr.first] + child.second || dist[child.first] == -1) {
                dist[child.first] = dist[curr.first] + child.second;   
                pq.push({child.first, dist[curr.first] + child.second});
            }
        }
        pq.pop();
    }

    return dist[destination];
}

int main() {
    int from, to, w;
    std::scanf("%d %d %d %d",&n, &m, &x, &y);
    x--;
    y--;

    graph.reserve(n);
    for(int i = 0; i < m; ++i) {
        std::scanf("%d %d %d", &from, &to, &w);
        graph[to - 1].push_back({from - 1, w});
        graph[from - 1].push_back({to - 1, w});
    }

    for(int i = 0; i < n; ++i) {
        dist[i] = -1;
    }
    
    std::printf("%ld\n", djikstra());
}
