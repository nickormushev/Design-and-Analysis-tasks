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

void solution(std::vector<std::vector<int>>& res) {
    
    std::set<int> paths;
    for (int i = 0; i < n; ++i) {
        if(!visited[i]) {
            res.push_back(std::vector<int>());
            topologicalSort(res[i], i, paths);
        }
    }

 //   std::reverse(res.begin(), res.end());
}

bool compare(std::vector<int> fst, std::vector<int> snd) {
    size_t i = 0;
    while(i < fst.size() && i < snd.size()) {
        if(fst[i] < snd[i]) {
            return true;
        } else if(snd[i] > fst[i]) {
            return false;
        }
    }

    if(fst.size() > i) {
        return false;
    } 

    return true;
}

void printArray(std::vector<std::vector<int>> res) {
    std::sort(res.begin(), res.end(), compare);

    for (size_t i = 0; i < res.size(); ++i) {
        for (size_t j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " " ;
        }
    }
}

void normalPrint(std::vector<int> res) {
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
        graph[y - 1].push_back(x - 1);  
    }

    std::vector<std::vector<int>> res;
    //std::vector<int> res;
    solution(res);
    if(cycle) {
        std::cout << "Sandro fails." << std::endl;
        return 0;
    }

    normalPrint(res);
    //printArray(res);
    return 0;
}
