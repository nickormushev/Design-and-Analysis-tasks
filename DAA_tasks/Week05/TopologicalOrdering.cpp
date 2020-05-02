#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int n, m;
std::vector<std::vector<int>> graph;
bool visited[10000] = { false };
bool cycle = false;

void topologicalSort(std::vector<int>& res, int index, std::set<int> paths) {
    if(index < 0 || index >= n) {
        return;
    }
    
    if(paths.find(index) != paths.end()) {
        cycle = true;
        return;
    }
    
    if(visited[index]) {
        return;
    }

    paths.insert(index);
    visited[index] = true;

    for (size_t i = 0; i < graph[index].size(); ++i) {
       topologicalSort(res, graph[index][i], paths);
    }

    res.push_back(index);
}

void solution(std::vector<int>& res) {
    
    std::set<int> paths;
    //int sortCounter = 0;
    for (int i = n - 1; i >= 0; --i) {
        if(!visited[i]) {
            //res.push_back(std::vector<int>());
            //topologicalSort(res[sortCounter++], i, paths);
            topologicalSort(res, i, paths);
        }
    }

   std::reverse(res.begin(), res.end());
}


void print(std::vector<int> res) {
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i] + 1 << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cin >> n >> m;
    int x, y;

    graph.reserve(n);
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        graph[x - 1].push_back(y - 1);  
    }

    std::vector<int> res;
    solution(res);
    if(cycle) {
        std::cout << "Sandro fails." << std::endl;
        return 0;
    }

    print(res);
    return 0;
}
