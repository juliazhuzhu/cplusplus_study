
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() == 0)
            return res;
        
        vector<int> ip;
        dfs(s,0,ip);
        return res;
    }
private:

    void dfs(string s, int index, vector<int> &ip){

        //a condition that validate the ip
        if (index == s.size()){
            if (ip.size() == 4){
                res.push_back(get_string(ip));
                return;
            }
        }

        if (index == 0){
            ip.push_back(s[0] - '0');
            dfs(s,index+1,ip);
        }else{
            /*
            如果在当前扩展结点处不能再向纵深方向移动，则当前扩展结点就成为死结点。
            此时，应往回移动（回溯）至最近的活结点处，并使这个活结点成为当前扩展结点。
            */

            int next = ip.back() * 10 + (s[index] - '0');
            printf("next %d \n", next);
            if (next <= 255){
                ip.back() = next;
                printf("index %d \n",index);
                dfs(s,index+1,ip);
                ip.back()/=10;//横向回朔后,ip...
                printf("ip.back %d index %d\n",ip.back(),index);
            }
        }
        if (ip.size() < 4){
            printf("index %d, ip %d ,ip back %d\n", index, s[index] - '0',ip.back());
            ip.push_back(s[index] - '0');
            dfs(s,index+1,ip);//深度回朔后，ip出栈
            ip.pop_back();
            printf("ip size %d \n",ip.size());
        }




    }

    string get_string(const vector<int>& ip){
        string res = to_string(ip[0]);
        for(int i = 1; i < ip.size(); i ++)
            res += "." + to_string(ip[i]);
        return res;
    }
    vector<string> res;
};

void print_vec(const vector<string>& vec){

    for(const string& e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    print_vec(Solution().restoreIpAddresses("25525511135"));
    return 1;
}