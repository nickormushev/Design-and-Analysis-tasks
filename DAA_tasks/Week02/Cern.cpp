#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int size(int n) {
    int res = 0;

    while(n/10 != 0) {
        res++;
    }

    return res;
}

//bool cmp(const int& num, const int& num2) {

    //int usedNum1 = num;
    //int usedNum2 = num2;
    //int currSize1 = size(num);
    //int currSize2 = size(num2); 

    //while(num != 0 && num2 != 0) {
        //if((usedNum1 / currSize1) != (usedNum2 / currSize2)) {
            //return (num / currSize1) < (num2 / currSize2); 
        //}

        //usedNum1 = usedNum1 / currSize1;
        //usedNum1 = usedNum2 / currSize2;
        //currSize1 = currSize1 / 10;
        //currSize2 = currSize2 / 10;
    //}

    //return num2 == 0;
//}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::string> nums;
    std::string num;
    for(int i = 0; i < n; i++) {
        std::cin >> num;
        nums.push_back(num);
    }

    std::sort(nums.begin(), nums.end());

    for(size_t i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << std::endl;
    }

}
