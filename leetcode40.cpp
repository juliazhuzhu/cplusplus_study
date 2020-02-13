#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
/*
思路
一重减枝
本题和39题唯一不同的是
39题原数组的每个元素可以重复使用
此题只能使用一次
由39题题解可知
且原数组的单个元素可以重复使用
意味着下一个for循环中的元素选取，要从前一个元素开始，因为可以重复使用，不然如果跟着for的自增变量i走，会漏掉可能解
将自增变量i传递下去
此题不能重复，意思就是当前自增变量不能传递下去，要传递下一个自增变量 i + 1
二重减枝
和47题一样，既然不能重复当前元素，那么利用排序，将相邻两个相同的元素只取前一个去组合，当前直接跳过，直接进入下一个元素进行组合

*/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        //set<int> candidates2;
        //copy(candidates.cbegin(),candidates.cend(),inserter(candidates2,candidates2.begin()));
        //candidates.clear();
        //copy(candidates2.cbegin(),candidates2.cend(),back_inserter(candidates));
        //copy(candidates2.begin(),candidates2.end(),candidates.begin());
        sort(candidates.begin(), candidates.end());
        vector<int> sub_res;
        backtrace(candidates,0,sub_res,target);
        return res;
    }

private:
    void backtrace(vector<int>& candidates, int index, vector<int> sub_res,int target){

        if (target == 0){
            res.push_back(sub_res);
            return;
        }

        for (int i = index; i < candidates.size(); i++){
            //cur_sum = cur_sum + candidates[i];
            /*if (cur_sum > target){
                cur_sum = cur_sum - candidates[i];
                continue;
            }*/
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            if (target >= candidates[i]){
                sub_res.push_back(candidates[i]);
                backtrace(candidates,i+1,sub_res,target-candidates[i]);
                //cur_sum = cur_sum - candidates[i];
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
    int arr1[7]={10,1,2,7,6,1,5};
    vector<int> t1(arr1,arr1+7);
    printVector(Solution().combinationSum2(t1,8));

    int arr2[5]={2,5,2,1,2};
    vector<int> t2(arr2,arr2+5);
    printVector(Solution().combinationSum2(t2,5));

}