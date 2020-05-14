#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

int n, m;
std::vector<std::pair<int, unsigned>> g[10000];
//first for weight. Second for number of routes
std::pair<int, int> dist[10000];
bool visited[10000];

void dijkstra(int start) {
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>> pq;
    
    for (int i = 0; i < n; ++i) {
        dist[i].first = -1;
        dist[i].second = 0;
        visited[i] = false;
    }


    dist[start] = { 0, 1 };
    pq.push({0, start});
    visited[start] = true;

    while(!pq.empty()) {
        int ind = pq.top().second;
        pq.pop();

        for(size_t i = 0; i < g[ind].size(); ++i) {
            std::pair<int, unsigned> child = g[ind][i];
            int childIndx = child.first;
            int childWeigth = child.second;

            if (dist[childIndx].first < dist[ind].first + childWeigth) {

                dist[childIndx].first = dist[ind].first + childWeigth;
                dist[childIndx].second = dist[ind].second;
                if(!visited[childIndx]){
                    pq.push({dist[childIndx].first, childIndx});
                }
            } else if (dist[childIndx].first == dist[ind].first + childWeigth) {
                dist[childIndx].second += dist[ind].second;
            }
        }
    }
}

int main() {
    
    std::scanf(" %d %d", &n, &m);
    int from, to, w, src, dest;

//    g.reserve(n);
    for (int i = 0; i < m; ++i) {
        std::scanf(" %d %d %d", &from, &to, &w);
        g[from].push_back({ to, w });
    }
    
    std::scanf(" %d %d", &src, &dest);
    dijkstra(src);

    std::printf("%d %d\n", dist[dest].first, dist[dest].second);
}
