#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
       
        vector<int> sub_res;
        backtrace(n,1,k,sub_res);
        return res;

    }

private:

    void backtrace(int n,int lastIndex,int depth,vector<int> sub_res){

        if (sub_res.size() == depth){
            res.push_back(sub_res);
            return;
        }

        for (int i = lastIndex; i<=n ; i++){
            sub_res.push_back(i);
            backtrace(n,i+1,depth,sub_res);
            //iter->second = 0;
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

int main(){

    printVector(Solution().combine(4,2));
    return 1;

}