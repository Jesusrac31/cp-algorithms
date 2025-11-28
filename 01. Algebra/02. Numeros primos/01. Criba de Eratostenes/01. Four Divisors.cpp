#include<bits/stdc++.h>
using namespace std;

// Copia a partir de aquí
class Solution {
public:
    int getDivisors(int num){
        vector<int> divisors;
        for (int i = 1; i*i<=num; i++){
            if (num%i == 0){
                if (i*i == num) divisors.push_back(i);
                else {
                    divisors.push_back(i);
                    divisors.push_back(num/i);
                }
            }
        }
        int add = 0;
        if (divisors.size() == 4) add = divisors[0]+divisors[1]+divisors[2]+divisors[3];
        return add;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sol = 0;
        for (auto x:nums){
            sol+=getDivisors(x);
        }
        return sol;
    }
};

// https://leetcode.com/problems/four-divisors/