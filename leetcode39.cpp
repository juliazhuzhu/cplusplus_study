#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> sub_res;
        backtrace(candidates,0,0,sub_res,target);
        return res;
    }

private:
    void backtrace(vector<int>& candidates, int index,int cur_sum, vector<int> sub_res,int target){

        if (cur_sum >= target){
            if (cur_sum == target)
                res.push_back(sub_res);
            return;
        }

        for (int i = index; i < candidates.size(); i++){
            cur_sum = cur_sum + candidates[i];
            sub_res.push_back(candidates[i]);
            backtrace(candidates,i,cur_sum, sub_res,target);
            cur_sum = cur_sum - candidates[i];
            sub_res.pop_back();
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
    int arr1[4]={2,3,6,7};
    vector<int> t1(arr1,arr1+4);
    printVector(Solution().combinationSum(t1,7));

}