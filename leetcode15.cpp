#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        
        if (nums.size() < 3)
            throw invalid_argument("invalide params");

        vector<vector<int> > res;
        vector<int> record;
        record.push_back(nums[0]);
        record.push_back(nums[1]);
        for (int i=2; i<nums.size(); i++){
            int third = nums[i];
            unordered_map<int,int> sub_record;
            for (int j=0; j < record.size(); j++){
                int second = record[j];
                int first = -(third + second);
                if (sub_record.find(first) != sub_record.end()){
                    int sub_res_arr[3] = {first,second,third};
                    res.push_back(vector<int>(sub_res_arr,sub_res_arr+3));
                }
                sub_record[record[j]] = j;

            }

            record.push_back(nums[i]);

        }

        return res;
    }
};