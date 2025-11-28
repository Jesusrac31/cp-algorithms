#include<bits/stdc++.h>
using namespace std;

// Copia a partir de aquí
class Solution {
public:
    int criba(int n) {
        int count = 1;
        vector<bool> isPrime = vector<bool>(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i=3; i<n; i+=2) {
            if (isPrime[i]) {
                count++;
                for (int h=2; h*i<n; ++h) {
                  isPrime[i*h] = 0;
                }
            }
        }
        return count;
    }
    int countPrimes(int n) {
        return (n>2 ? criba(n):0);
    }
};

// https://leetcode.com/problems/count-primes/