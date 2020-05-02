#include <iostream>

//cin.tie(NULL);
//ios::sync_with_stdio(false);
//the obove two lines are for fast cin and cout
const int MAX_SIZE = 20;
void input(int a[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
       	for(int j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void printMatrix(int arr[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols - 1; j++) {
            printf("%d ", arr[i][j]);
        }
    	printf("%d\n",arr[i][cols - 1]);
    }
}

int main() {
    int m, n, k;
    std::scanf("%d %d %d", &m, &n, &k);
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], res[MAX_SIZE][MAX_SIZE];
    input(a, m, n);
    input(b, n, k);
    
    for(int i = 0; i < m; i++) {
	    for(int j = 0; j < k; j++) {
	        res[i][j] = 0;
	        for(int t = 0; t < n; t++) {
       		    res[i][j] += a[i][t] * b[t][j];
	        }
	    } 
    } 
    
    printMatrix(res, m, k);

    return 0; 
}
