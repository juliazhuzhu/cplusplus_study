#include <map>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        int ret = 0;
        while (n != 0){
            int z = n%10;
            n = n/10;
            ret = ret + z*z;
        }

        if (ret == 1)
            return true;
        
        if (numbers[ret] != 0)
            return false;

        numbers[ret] ++;
        return isHappy(ret);
    }


private:

    map<int,int> numbers;


    
};


int main() {
    int numbers[] = {19,21,31,34,35};
    Solution sl;
    for (int i = 0; i < 5; i++){
        bool ret = sl.isHappy(numbers[i]);
        printf("%d happy number %s \n",numbers[i],ret?"yes":"no");
    }
    

}

