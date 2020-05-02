//The task: https://judge.openfmi.net/practice/get_problem_description?contest_id=12&problem_id=30
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int>> graph;
bool visited[500] = { false };

void addElements(int vertex, std::stack<int>& dfsStack) {
    for (size_t j = 0; j < graph[vertex].size(); j++) {
        dfsStack.push(graph[vertex][j]);
    }
}

void dfs(int i) {
    std::stack<int> dfsStack;
    int vertex;
    dfsStack.push(i);
    
    while(!dfsStack.empty()) {
        vertex = dfsStack.top();
        dfsStack.pop();

        if(!visited[vertex]) {
            visited[vertex] = true;
            addElements(vertex, dfsStack);
        }
    }
}

int solution(int n) {
    int studentsCounter = 0;
    for (int i = 0; i < n; ++i) {
        if(!visited[i]) {
            dfs(i); 
            studentsCounter++;
        }           
    }               

    return studentsCounter;
}

int main() {
    int n, m;
    int k, j;

    std::scanf(" %d %d", &n, &m);
    graph.reserve(n);

    for (int i = 0; i < m; ++i) {
        std::scanf(" %d %d", &k, &j);
        graph[k - 1].push_back(j - 1);
        graph[j - 1].push_back(k - 1);
    }
    
    int childrenTold = solution(n);
    
    std::printf("%d\n", childrenTold);
    return 0;
}
