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

    bool operator==(Edge& other) {
        return other.cost == cost && 
               other.from == from &&
               other.to   == to;
    }
};

Edge g[10000];
//first for weight. Second for number of routes
std::pair<int, int> dist[10000];
bool visited[10000];
std::vector<int> predecessor[10000];

void cleans(std::vector<int>& arr) {
    while(!arr.empty()) {
        arr.pop_back();
    }
}

void bellman_ford(int start) {
    
    for (int i = 0; i < n; ++i) {
        dist[i].first = 1;
        dist[i].second = 0;
        visited[i] = false;
    }


    dist[start] = { 0, 1 };
    visited[start] = true;
    bool change = true;
    int cnt = 0;
    
    while(change && cnt < n - 1) {
        cnt++;
        change = false;
        
        for(int i = 0; i < m; ++i) {
            if (dist[g[i].from].first != 1 && dist[g[i].to].first > dist[g[i].from].first + g[i].cost) {
                change = true;

                dist[g[i].to].first = dist[g[i].from].first + g[i].cost;
                dist[g[i].to].second = dist[g[i].from].second;

                //predecessor[g[i].to].clear();
                cleans(predecessor[g[i].to]);
                predecessor[g[i].to].push_back(g[i].from);
            } else if (dist[g[i].from].first != 1 && dist[g[i].to].first == dist[g[i].from].first + g[i].cost) {
                if(std::find(predecessor[g[i].to].begin(), predecessor[g[i].to].end(), g[i].from) == predecessor[g[i].to].end()) {
                    dist[g[i].to].second += dist[g[i].from].second;
                    predecessor[g[i].to].push_back(g[i].from);
                }
            }
        }
    }
}

int main() {
    
    std::scanf(" %d %d", &n, &m);
    int from, to, w, src, dest;

    //g.reserve(n);
    for (int i = 0; i < m; ++i) {
        std::scanf(" %d %d %d", &from, &to, &w);
        g[i] = { from, to, -w };
    }
    
    std::scanf(" %d %d", &src, &dest);
    bellman_ford(src);

    std::printf("%d %d\n", -dist[dest].first, dist[dest].second);
}
