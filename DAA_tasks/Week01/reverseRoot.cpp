#include<iostream>
#include<stack>
#include<cmath>

int main() {
    std::cin.tie(NULL); //cin does not wait for cout if they are one after another
    std::ios::sync_with_stdio(false); //Mixing C and C++ I/O is harder by disabling this feature 
    
    std::stack<double> result;
    int input; 
    

    while(std::cin >> input) {
        result.push(sqrt(input));
    }

    while(!result.empty()){
        printf("%lf\n",result.top());
        result.pop();
    }
}
