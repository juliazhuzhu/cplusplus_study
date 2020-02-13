#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
       /* max_sum = 0;
        backtrace(nums,0,0);
        return max_sum;*/

        memo = vector<int>(nums.size(), -1);

        return tryRob(nums,0);
    }

private:
    void backtrace(vector<int>& nums, int index,int sum){

        if (index >= nums.size() -1){
            if (index == nums.size() -1)
                sum = sum + nums[index];
            max_sum = max(max_sum, sum);
            return;
        }

        for (int i = index; i < nums.size(); i ++){
            int tmp = nums[i];
            sum = sum + tmp;
            backtrace(nums, i+2,sum);
            sum = sum - tmp;
        }
    }
    int max_sum;
    vector<int> memo;
    
private:
    int tryRob(vector<int>& nums ,int index){

        if (index >= nums.size()){
            return 0;
        }
        if (memo[index] != -1)
            return memo[index];

        int res = -1;
        for (int i = index; i <nums.size(); i++){
            res = max(res, nums[i] + tryRob(nums,i + 2));
        }
        memo[index] = res;

        return res;
    }
};

int main() {

    int arr[] = {1,2,3};

    vector<int> nums(arr, arr +3);
    printf("Solution %d \n", Solution().rob(nums));
}