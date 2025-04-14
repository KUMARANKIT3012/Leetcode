#include <bits/stdc++.h>
using namespace std;

int* printDivisors(int n, int &size) {
    vector<int> divisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end()); // Sort divisors in ascending order
    
    size = divisors.size();  // update size

    // allocate dynamic array to return
    int* result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = divisors[i];
    }

    return result;
}
