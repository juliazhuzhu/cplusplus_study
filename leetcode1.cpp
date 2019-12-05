#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> record;
        for (int i=0; i<nums.size(); i++){
            
            int compilement = target - nums[i];
            if (record.find(compilement) != record.end()){

                int t = record[compilement];
                int res[2] = {t,i};
                return vector<int>(res,res+2);
            }

            record[nums[i]] = i;
        }

        throw invalid_argument("input params is not valid.");

    }
};


int main(){

  
}