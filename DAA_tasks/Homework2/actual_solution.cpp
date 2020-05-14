//https://judge.openfmi.net/timed_contest/get_problem_description?contest_id=169&problem_id=524
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

int n, m;
std::vector<std::pair<int,int>> g[10000];
//first for weight. Second for number of routes
std::pair<int, int> dist[10000];

//ignore
bool visited[10000];


void initVisited() {
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
}

void topSort(int curr, std::vector<int>& res) {
    
    if(visited[curr]) {
        return;
    }

    visited[curr] = true;

    for (size_t i = 0; i < g[curr].size(); ++i) {
        int child = g[curr][i].first;
        dist[child].first = -1;
        dist[child].second = 0;
        topSort(child, res);
    }

    res.push_back(curr);
}

void alg(int src) {
    std::vector<int> res;
    initVisited();
    topSort(src, res);
    dist[src].first = 0;
    dist[src].second = 1;
    

    for (int i = res.size() - 1; i >= 0; --i) {
        int curr = res[i];
        for (size_t j = 0; j < g[curr].size(); ++j) {
            int child = g[curr][j].first;
            if(dist[child].first == -1 || dist[child].first < dist[curr].first + g[curr][j].second) {
                dist[child].first = dist[curr].first + g[curr][j].second;
                dist[child].second = dist[curr].second;
            } else if(dist[child].first == dist[curr].first + g[curr][j].second) {
                dist[child].second += dist[curr].second;
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
        g[from].push_back({ to, w });
    }
    
    std::scanf(" %d %d", &src, &dest);
    alg(src);

    std::printf("%d %d\n", dist[dest].first, dist[dest].second);
}
