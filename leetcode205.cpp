#include <map>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if (s.size() != t.size())
            return false;
        
        map<char,int> map1;
        map<char,int> map2;
        for (int i = 0; i<s.size(); i++){
           
            //if (it1 == pattern_map.end())
            map<char, int>::iterator iter1 = map1.find(s[i]);
            map<char, int>::iterator iter2 = map2.find(t[i]);
            int i1 = (iter1 == map1.end() ? -1 : map1[s[i]]);
            int i2 = (iter2 == map2.end() ? -1 : map2[t[i]]);

            if(i1 != i2)
                return false;

            map1[s[i]] = i;
            map2[t[i]] = i;

        }

        return true;
    }


private:

    
};


int main(){

    Solution sl;


    bool ret = sl.isIsomorphic("egg","add");
    printf("isIsomorphic %s \n", ret?"yes":"no");
    ret = sl.isIsomorphic("foo","bar");
    printf("isIsomorphic %s \n", ret?"yes":"no");
    ret = sl.isIsomorphic("paper","title");
    printf("isIsomorphic %s \n", ret?"yes":"no");
  

}