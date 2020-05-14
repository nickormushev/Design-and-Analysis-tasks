//overly complicated slow and might not work. But still my first attempt at bellman_ford
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

int n, m;

struct Edge {
    int from;
    int to;
    int cost;
};

Edge g[500000];
//first for weight. Second for number of routes
std::pair<int, int> dist[10000];
std::vector<Edge*> predecessor[10000];

void cleans(std::vector<Edge*>& arr) {
    while(!arr.empty()) {
        arr.pop_back();
    }
}

void bellman_ford(int start) {
    
    for (int i = 0; i < n; ++i) {
        dist[i].first = 1;
        dist[i].second = 0;
    }

    dist[start] = { 0, 1 };
    bool change = true;
    
    while(change) {
        change = false;
        
        for(int i = 0; i < m; ++i) {
            if (dist[g[i].from].first != 1 && dist[g[i].to].first > dist[g[i].from].first + g[i].cost) {
                change = true;

                dist[g[i].to].first = dist[g[i].from].first + g[i].cost;
                dist[g[i].to].second = dist[g[i].from].second;
                predecessor[g[i].to].clear();
                cleans(predecessor[g[i].to]);
                predecessor[g[i].to].push_back(&g[i]);
            } else if (dist[g[i].from].first != 1 &&
                       dist[g[i].to].first == dist[g[i].from].first + g[i].cost &&
                       std::find(predecessor[g[i].to].begin(), predecessor[g[i].to].end(), &g[i]) == predecessor[g[i].to].end()) {

                dist[g[i].to].second += dist[g[i].from].second;
                predecessor[g[i].to].push_back(&g[i]);
            }
        }
    }
}

int main() {
    
    std::scanf(" %d %d", &n, &m);
    int from, to, w, src, dest;

    for (int i = 0; i < m; ++i) {
        std::scanf(" %d %d %d", &from, &to, &w);
        g[i] = { from, to, -w };
    }
    
    std::scanf(" %d %d", &src, &dest);
    bellman_ford(src);

    std::printf("%d %d\n", -dist[dest].first, dist[dest].second);
}
