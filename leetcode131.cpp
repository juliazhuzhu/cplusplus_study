

#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(const char *str, int begin, int end)
{
    while (begin <= end)
    {
        if (str[begin] == str[end])
        {
            begin++;
            end--;
        }
        else
            return false;
    }
    return true;
}

class Solution {
public:
    vector<vector<string > > partition(string s) {
        
        vector<string> sub_res;
        backtrace(s,0,sub_res);
        return res;
    }

private:
    void backtrace(string s, int lastIndex, vector<string> sub_res){

        
        if (lastIndex == s.size()){
            res.push_back(sub_res);
            return;
        }

        for (int i = lastIndex;i<s.size(); i++){

            string pal_candidate = s.substr(lastIndex,i-lastIndex+1);
            if (isPalindrome(pal_candidate.c_str(),0,pal_candidate.size() - 1)){
                sub_res.push_back(pal_candidate);
                backtrace(s,i+1,sub_res);
                sub_res.pop_back();
                
            }
        }
        
    }
    vector<vector<string > > res;
};

void printVector(vector<vector<string > > res){

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

    printVector(Solution().partition("abb"));
    //cout<<"================================"<<endl;
    printVector(Solution().partition("cdd"));

    return 1;
}