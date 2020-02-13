
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string sub_res;
        backtrace(digits,0,sub_res);
        return res;
    }

private:

    void backtrace(string digits, int digitIndex,string sub_res){
        if (digitIndex == digits.size()){
            res.push_back(sub_res);
            return;
        }
        
        char digit = digits[digitIndex];
        string letters = letterMaps[digit - '1'];
        for (int j = 0; j < letters.size(); j++){
            sub_res.push_back(letters[j]);
            backtrace(digits,digitIndex + 1,sub_res);
            sub_res.pop_back();

        }
    }

    const string letterMaps[10] = {
        " ",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    vector<string> res;

};

void printVector(vector<string> res){

    cout << "[ ";
    for (int i=0; i <res.size(); i++){
        cout << res[i];
        if (i != res.size() -1)
            cout<<",";

    }
    cout <<" ]"<<endl;

}

int main(){
    printVector(Solution().letterCombinations("23"));
    return 1;
}