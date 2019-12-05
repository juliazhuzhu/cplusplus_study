#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        int k = 0;
        int index = 0;
        int len = 0;
        while (len < nums.size()){
            printf("nums[%d] = %d\n",index,nums[index]);
            nums[k++] = nums[index];
            len++;
            if (index == (nums.size() -1))
                break;
            index = getNextElement(nums,nums[index],index+1);//[index,end)
            printf("index %d\n",index);
            

            
        }
        printf("len %d\n",len);
        return len;
    }
    
private:
    int getNextElement(vector<int>& nums, int val,int index){
        const int DUP_TIMES=2;
        int duplicate = 0;
        int i = index;
        printf("getNextElem val %d, index %d \n", val, index);
        for (i;i < nums.size();i++){
            if (val == nums[i]){
                duplicate++;
                if (i == nums.size() -1)
                    return i;
            }
            else{
                printf("duplicate %d , i %d \n",duplicate,i);
                if (duplicate >= 1){
                       return (i - 1); 
                }
                    
                printf("getNextElement return i %d \n",i);
                return i;
            }
               
        }
       
        return index;
    }
};

int main() {

    Solution sl;
    int num[9] = { 0,0,1,1,1,1,2,3,3};
    //int num[6] = {1,1,1,2,2,3};
    //int num[3] = { 1,1,1};
    int numLength = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + numLength);  //使用数组初始化向量

    int len = sl.removeDuplicates(nums);
    for (int i =0; i < len; i++)
        printf("%d ",nums[i]);
    printf("\n");

    return 1;
}