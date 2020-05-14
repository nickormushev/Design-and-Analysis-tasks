//https://www.spoj.com/problems/SUBMERGE/
//Look more into articulation point algorithm. Slow
#include <cstdio>
#include <iostream>
#include <vector>

int n, m;
std::vector<std::vector<int>> g; 
bool visited[10000];

void dfs(int curr, int sunken, int& visits) {

    if(sunken == curr) {
        visited[curr] = true;
        return;
    }

    if(visited[curr]) {
        return;
    }

    visited[curr] = true;
    visits++;
    for (size_t i = 0; i < g[curr].size(); ++i) {
        dfs(g[curr][i], sunken, visits);
    }  
}

void nullVisited() {
    for (int j = 0; j < n; ++j) {
        visited[j] = false;
    }
}

//void checkVisited(int& res) {
//    int j = 0;
//    while(visited[j] == true && j < n) {
//        j++;
//    }
//    
//    if (j < n) {
//        res++;
//    }
//}

int alg() {
    int res = 0;

    for (int i = 0; i < n; ++i) {
        int visits = 0;
        nullVisited();

        if(i == 0) {
            dfs(1, i, visits);
        } else {
            dfs(0, i, visits);
        }
        
        if(visits < n - 1) {
            res++;
        }
    }

    return res;
}

int main(void) {
    int from, to;
    std::vector<int> res;

    do {
        std::scanf(" %d %d", &n, &m);
        g.reserve(n);

        for (int i = 0; i < m; ++i) {
            std::scanf(" %d %d", &from, &to);

            g[from - 1].push_back(to - 1);
            g[to - 1].push_back(from - 1);
        }

        if(n != 0 && m != 0) {
           res.push_back(alg());
        }
        
    } while (n != 0 && m != 0);

    for (size_t i = 0; i < res.size(); ++i) {
        std::printf("%d\n", res[i]);
    }

    return 0;
}
