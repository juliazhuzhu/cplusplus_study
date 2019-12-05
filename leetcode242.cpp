
#include <string>
#include <map>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        map<char,int> s_map;
        for (int i = 0; i<s.size(); i++)
            s_map[s[i]]++;
        
        for (int j = 0; j < t.size(); j++){
            if (s_map.find(t[j]) != s_map.end() && s_map[t[j]] > 0){
                s_map[t[j]] --;
                if (s_map[t[j]] == 0){
                    s_map.erase(t[j]);
                }
            }else{
                return false;
            }
        }

        if (s_map.size() == 0)
            return true;        
        
        return false;
    }
};


int main() {

    Solution sl;
    bool val = false;
    val = sl.isAnagram("anagram","nagaram");
    printf("it is anagram %s\n", val?"yes":"no");
    val = sl.isAnagram("rat","car");
    printf("it is anagram %s\n", val?"yes":"no");

    string s = "anagram";
    string t = "nagaram";

    sort(s.begin(),s.end());
    printf("%s \n",s.c_str());
    return 1;
}








