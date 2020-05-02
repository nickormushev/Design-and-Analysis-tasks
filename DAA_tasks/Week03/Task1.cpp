#include <cstdio>
#include <queue>

int main() {
    char cmd;
    int number;

    std::priority_queue<int> prQueue;

    while(cmd != 'Q') {
        std::scanf(" %c", &cmd);

        if(cmd == 'A') {
            std::scanf(" %d", &number);
            prQueue.push(number); 
        } else if(prQueue.size() == 0) {
            std::printf("Not available\n");
        } else if (cmd == 'R') {
            std::printf("%d\n", prQueue.top());
            prQueue.pop();
        } else if (cmd == 'L') {
            std::printf("%d\n", prQueue.top()); 
        }
    }

    return 0;
}
