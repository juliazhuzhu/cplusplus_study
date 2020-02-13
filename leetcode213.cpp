#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 0)
            return 0;

        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0], nums[1]);

        memo = vector<int>(nums.size() - 1, -1);

        //printf("rob  %d \n",tryRob(nums,0,nums.size() - 1));
        //int size = nums.size()-1;
        vector<int> nums1 ;
        for (int i = 1; i < nums.size(); i++){
            nums1.push_back(nums[i]);
        }

        vector<int> nums2 ;
        for (int i = 0; i < (nums.size() - 1); i++){
            nums2.push_back(nums[i]);
            
        }
        int t1 = tryRob(nums1,0);
        memo = vector<int>(nums.size() - 1, -1);

        int t2 = tryRob(nums2,0);

        //printf(" t1 %d, t2 %d \n", t1, t2);
        return  max(t1, t2);
    }

private:
    int tryRob(vector<int>& nums, int index){

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

    vector<int> memo;

};

int main() {
                
    int arr[] = {1,2,3,1};

    vector<int> nums(arr, arr +4);
    printf("Solution %d \n", Solution().rob(nums));
}