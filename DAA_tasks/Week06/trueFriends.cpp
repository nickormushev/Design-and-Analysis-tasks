//https://www.spoj.com/problems/TFRIENDS/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int n;
std::vector<std::vector<int>> g;
std::vector<std::vector<int>> revG;
bool visited[100];

void nullVisited() {
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
}

void topSortImpl(int curr, std::vector<int>& res) { 
    if(visited[curr]) {
        return;
    }

    visited[curr] = true;
    
    for (size_t i = 0; i < revG[curr].size(); ++i) {
        topSortImpl(revG[curr][i], res);
    }

    res.push_back(curr);
}

std::vector<int> topSort() {
    std::vector<int> res;
    nullVisited();

    for (int i = 0; i < n; ++i) {
        if(!visited[i]) {
            topSortImpl(i, res);
        }
    }

    std::reverse(res.begin(), res.end());   
    return res;
}

void dfs(int curr) {
    if(visited[curr]) {
        return;
    }

    visited[curr] = true;
    
    for (size_t i = 0; i < g[curr].size(); ++i) {
        dfs(g[curr][i]);
    }
}

int alg() {
    int groups = 0;
    std::vector<int> order = topSort();
    nullVisited();

    for (int i = 0; i < n; ++i) {
        if(!visited[order[i]]) {
            dfs(order[i]);
            groups++; 
        }
    }
    
    return groups;
}

void cleans(std::vector<std::vector<int>>& arr) {
    for (int i = 0; i < n; i++) {
        while(!arr[i].empty()) {
            arr[i].pop_back();
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    std::vector<int> res;
       
    for(int i = 0; i < t; ++i) {
        std::cin >> n;
        std::string inp;

        g.reserve(n);
        revG.reserve(n);

        cleans(g);
        cleans(revG);

        int cnt;
        for (int j = 0; j < n; ++j) {
            std::cin >> inp;
            cnt = 0;

            for (char k : inp) {
                if(k == 'Y') {
                    g[j].push_back(cnt);
                    revG[cnt].push_back(j);
                }
                
                cnt++;
            }
        }
        res.push_back(alg());
    }

    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i] << std::endl;
    }

    return 0;
}
