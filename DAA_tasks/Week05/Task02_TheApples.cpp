//task: https://judge.openfmi.net/practice/get_problem_description?contest_id=12&problem_id=34
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <queue>

int appleArray[1000][1000] = { 0 }, posX[2], posY[2];

void printArray(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << appleArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
}

bool coordineateValidity(int newX, int newY, int n, int m) {
    return newX < n && newY < m && newX >=0 && newY >= 0;
}

void contaminate(int n, int m, int t, int x, int y, long& counter, std::queue<std::pair<int, int>>& q) {
    std::pair<int, int> directionArr[4] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
    int newX, newY;
    std::cout << "x and y: " <<  x << y << std::endl;
    for (int i = 0; i < 4; ++i) {
        newX = directionArr[i].first + x;
        newY = directionArr[i].second + y;
        std::cout << newX << " " << newY << std::endl;
        if(coordineateValidity(newX, newY, n, m) && (appleArray[newX][newY] > t || appleArray[newX][newY] == 0)) {// 
            q.push({ newX, newY });
            counter += !(appleArray[newX][newY] > t) ;  
            appleArray[newX][newY] = t;
        }
    }

}

void bfs(int n, int m, int t, int startX, int startY, long& counter) {
    std::queue<std::pair<int, int>> q;
    std::pair<int, int> topBadApple = { startX, startY };
    q.push({ startX, startY });
    int startT = 1;
    
    if(appleArray[startX][startY] != 0) {
        counter--;
    }

    appleArray[startX][startY] = 1;

    while(!q.empty() && t >= startT) { 

        while(!q.empty() && appleArray[topBadApple.first][topBadApple.second] == startT) {
            contaminate(n, m, startT + 1, topBadApple.first, topBadApple.second, counter, q);
            printArray(n,m);
            q.pop();
            topBadApple = q.front();
        }

        startT++;
    }
}

long countBadApples(int n, int m, int t, int badAppleCounter) {
    
    long countAfterTDays = badAppleCounter;
    
    for (int i = 0; i < badAppleCounter; ++i) {
        bfs(n, m, t, posX[i], posY[i], countAfterTDays);
    }

    return countAfterTDays;
}

int main(void) {
    int m, n, t, badAppleCounter = 0;
    
    std::scanf(" %d %d %d", &n, &m, &t);
    
    while(std::scanf(" %d %d", &posX[badAppleCounter], &posY[badAppleCounter]) == 2) {
        badAppleCounter++;
    }
    
    long res = countBadApples(n, m, t, badAppleCounter);

    std::printf("%ld\n", n * m - res);

    return 0;
}
