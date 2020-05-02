#include <iostream>
#include <vector>

char ask(int x, int who) {
    return 'h';
}

int main(void) {
    
    int high;
    int people[200];
    int acounter = 0;
    int hcounter = 0;
    int answ;
    int low = 0;
    int size;

    std::cin >> high;  
    size = high;
    high--;
//1 2 3  3 - 2 = 0 
    while(low < high) {
        answ = ask(people[low], high);
        low++;

        if (answ == 'h') {
            hcounter++;
        } else {
            acounter++;
            if (acounter > hcounter) {
                high--;
                acounter = 0;
                hcounter = 0;
            }
        }

        if (high == low) {
           return high; 
        }

        if (hcounter - acounter >= high - low - 1) {
           return high; 
        }

    }
    
    std::vector<char> res;

    for (int i = 0; i < size; ++i) {
      if (i != high) {
        res.push_back(ask(people[high], people[i])); 
      } else {
        res.push_back('h');
      }
    } 

    return 0;
}
