#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {

        vector<int> sub_res;
        map<int,int> nums_map;
        for (int i=0; i < nums.size(); i++){
            nums_map[nums[i]] = 0;
        }
        backtrace(nums_map,sub_res);
        //cout<<"at end,sub_res.size "<<sub_res.size() <<endl;
        return res;
    }

private:

    void backtrace(map<int,int> nums,vector<int> sub_res){

        if (sub_res.size() == nums.size()){
            res.push_back(sub_res);
            return;
        }

        map<int,int>::iterator iter = nums.begin();
        for (;iter != nums.end(); iter++){
            if (iter->second == 0){
                sub_res.push_back(iter->first);
                iter->second = 1;
                backtrace(nums,sub_res);
                iter->second = 0;
                sub_res.pop_back();
            }
        }
    }
    vector<vector<int> > res;
};

void printVector(vector<vector<int > > res){

    cout<<"["<<endl;
    for (int i =0 ;i < res.size() ; i++){
        cout<<"     [";
        for(int j=0; j < res[i].size(); j++)
        {
            cout<<res[i][j];
            if (j != res[i].size()-1)
                cout<<",";
        }
        cout<<"]";
        if (i != res.size()-1)
            cout<<",";
        cout << endl;
    }
    cout<<"]"<<endl;
}

int main() {
    int nums_arr[] = {1,2,3};
    vector<int> nums(nums_arr,nums_arr+3);
    printVector(Solution().permute(nums));
    return 1;
}