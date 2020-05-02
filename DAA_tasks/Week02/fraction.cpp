#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    int n;
    scanf("%d", &n);
    
    printf("0 ");
    std::vector<std::pair<int, int>> result;

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(std::__gcd(i,j) == 1) {
                result.push_back(std::pair<int, int>(i, j));
            }
        }
    } 

    for(size_t i = 0; i < result.size(); i++) {
        for(size_t j = 0; j < result.size() - 1; j++) {
            if(result[j].first * result[j + 1].second > result[j + 1].first * result[j].second) {
                std::swap(result[j], result[j + 1]);
            }
        }
    }

    for(size_t i = 0; i < result.size(); i++) {
        printf("%d/%d ", result[i].first, result[i].second);
    }   
}
