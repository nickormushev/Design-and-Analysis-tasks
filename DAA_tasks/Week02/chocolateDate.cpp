#include<iostream>
#include<algorithm>

const int MAX_SIZE = 100;

struct Date {
    int id;
    int month;
    int day;
    int year;
};

bool cmp(const Date &a, const Date &b) {
    return !(b.year < a.year || (a.year == b.year && b.month < a.month) ||
            (a.year == b.year && b.month == a.month && b.day < a.day) ||
            (a.year == b.year && b.month == a.month && b.day == a.day && b.id < a.id)); 
}


int main() {

    int n;
    scanf("%d", &n);
    Date arr[MAX_SIZE];
    
    for(int i = 0; i < n; i++) {
        scanf("%d.%d.%d", &arr[i].day, &arr[i].month, &arr[i].year);
        arr[i].id = i + 1;
    }
    
    std::sort(arr, arr + n, cmp); 

    for(int i = 0; i < n; i++) {
        printf("%d\n", arr[i].id);
    }  
}
