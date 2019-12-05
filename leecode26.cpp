#include <vector>
#include <stdio.h>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int k=1;//point to the next unduplicated element
        for (int i=0;k<len && i<len; ){
            if (nums[i] == nums[k]){
                
                if ((k+1) < len)
                {   
                    len --;
                    int t =k;
                    for (;t<len;t++)
                        nums[t]=nums[t+1];
                   
                }
                else
                {

                    len --;
                }
                
               
            }
            else{
                i++;
                k++;
                
            }
        }
        
        return len;
        
    }
};

int main() {
    
    Solution sl;
    int num[2] = { 1,1};
    int numLength = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + numLength);  //使用数组初始化向量
    for (int i =0; i < numLength; i++)
        printf("%d ",num[i]);
    printf("\n");
    //vector<int> nums = [0,0,1,1,1,2,2,3,3,4];
    int size = sl.removeDuplicates(nums);
    for (int i =0; i < size; i++)
        printf("%d ",nums[i]);
    printf("\n");
    return 1;
}