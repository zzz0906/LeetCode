#include<iostream>
#include<stdio.h>
#include<stdlib.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag = 1;
        int answer = 0;
        if (dividend == 0) return 0;


        double tmp = dividend;
        if (divisor < 0){
            flag = -1;
            divisor = -divisor;
            if (dividend < 0){
                flag = 1;
                tmp = double(dividend);
                tmp = tmp * - 1;
            }
        } else {
            if (dividend < 0){
                flag = -1;
                tmp = double(dividend);
                tmp = tmp * - 1;
            }
        }
        while (tmp >= divisor) {
            tmp -= divisor;
            answer ++;
        }
        
        return flag * answer;
    }
};