
#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;
//#define max(a,b)            (((a) > (b)) ? (a) : (b))

class Solution {
public:
    int integerBreak(int n) {
         

         return breakInteger(n);
    }

private:
    int max3(int a, int b, int c){
        return max(a, max(b,c));
    }

    map<int,int>    record;
    int breakInteger(int n){

        if (n == 1)
            return 1;
        int res = -1;
        if (record[n] != 0)
            return record[n];

        for (int i = 1; i <= n -1; i++){
            res = max3(res, i*(n-i),i*breakInteger(n-i));
            record[n] = res;
        }

        return res;
    }

    //int res;

    
};


int main() {

    printf(" %d \n",Solution().integerBreak(58));
    return 1;
}

