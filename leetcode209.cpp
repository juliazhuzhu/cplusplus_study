#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int r = -1;
        int l = 0;
        int sum = 0;
        int res = nums.size() + 1;
        while (l < nums.size())
        {  
            if (sum < s && r+1 <nums.size())
                sum = sum + nums[++r];
            else {
                sum = sum - nums[l++];
            }
            
            printf("l = %d \n",l);
            if (sum >= s){
                int len =r-l;
                res = min(len, res);
            }
        }
      
        if (res == nums.size() + 1)
            return 0;
        return res + 1;
    }
};

int main() {

    Solution sl;
    int num[9] = { 0,0,1,1,1,1,2,3,3};
    //int num[6] = {1,1,1,2,2,3};
    //int num[3] = { 1,1,1};
    int numLength = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + numLength);  //使用数组初始化向量

    sl.minSubArrayLen(100,nums);

    return 1;
}