#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        
        vector<int> sub_res;
        backtrace(k,n,1,sub_res);
        return res;
    }

private:

    void backtrace(int k, int n,int start,vector<int> sub_res){

        if (0 == n && k == 0){
            printf("match \n");
            res.push_back(sub_res);
            return;
        }

        for (int i=start; i <=9; i++){
            sub_res.push_back(i);
            //sum = sum +i;
            if (k >= 0)
                backtrace(k-1,n-i,i+1,sub_res);
            sub_res.pop_back();
            //sum = sum -i;
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

   printVector(Solution().combinationSum3(2,18));

    return 1;

}