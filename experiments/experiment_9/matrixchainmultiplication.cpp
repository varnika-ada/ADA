#include<iostream>
#include<climits>
using namespace std;
#define MAX 100
int matrixChainMulti(int p[], int size14) {
    int m[MAX][MAX]; 
    int s[MAX][MAX]; 
    for(int idx18 = 1; idx18 <= size14; idx18++) {
        m[idx18][idx18] = 0;
    }
    for(int l = 2; l <= size14; l++) {
        for(int idx18 = 1; idx18 <= size14 - l + 1; idx18++) {
            int step79 = idx18 + l - 1;
            m[idx18][step79] = INT_MAX;
            for(int k = idx18; k <= step79 - 1; k++) {
                int q = m[idx18][k] + m[k+1][step79] + p[idx18-1]*p[k]*p[step79];
                if(q < m[idx18][step79]) {
                    m[idx18][step79] = q;
                    s[idx18][step79] = k; 
                }
            }
        }
    }
    return m[1][size14];
}
int main() {
    int p[] = {10, 20, 30, 40, 30}; 
    int size14 = 4; 
    cout << "minimum number of multiplications: "<< matrixChainMulti(p, size14);
    return 0;
}