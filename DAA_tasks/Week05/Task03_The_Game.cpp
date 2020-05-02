//Task https://judge.openfmi.net/practice/get_problem_description?contest_id=15&problem_id=38
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>

int input, desired, n, inputAsArr[5];
std::set<int> visited;

int powersArray[5] = { 10000, 1000, 100, 10, 1 };

int calculate(int * arr) {
    int res = 0;
    for (int i = 0; i < 5; ++i) {
        res += arr[i];
    }

    return res;
}

bool isVisited(int curr){
    return visited.find(curr) != visited.end();
}

//first is int 
int depth() {
    std::queue<std::pair<int,int>> q;
    q.push({0, input});

    while(!q.empty()) {
        if(q.front().second == desired) {
            return q.front().first;
        }

        visited.insert(q.front().second);

        int newDepth = q.front().first + 1;

        for (int i = 0; i < 5; ++i) {
            int powNum = powersArray[i];
            int newNum;

            if(q.front().second > powNum && (q.front().second / powNum) % 10 == 9) {
                newNum = q.front().second - 9 * powNum;
            } else {
                newNum = q.front().second + powNum;
            }

            if(q.front().second < powNum || (q.front().second / powNum) % 10 == 0 ) {
               powNum = -9 * powNum; 
            }
            
            int newMinusNum = q.front().second - powNum;

            q.push({newDepth, newNum});
            q.push({newDepth, newMinusNum});
        }

        while(!q.empty() && isVisited(q.front().second)) {
            q.pop();
        }
    }

    return -1;
}

int main() {
    
    std::scanf(" %d", &input);
    std::scanf(" %d", &desired);  
    std::scanf(" %d", &n);
    
    int reseter = 0;
    for (int i = 0; i < n; ++i) {
        std::scanf(" %d", &reseter);
        visited.insert(reseter);
    }

    int res = depth();

    std::printf("%d\n", res);
    
    return 0;
}
