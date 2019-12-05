#include <map>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        vector<string> words = Split(str);
        if (words.size() != pattern.size())
            return false;
        
        map<char,int> pattern_map;
        map<string,int> str_map;

        for (int i = 0; i<pattern.size(); i++){
            char e1 = pattern[i];
            string e2 = words[i];
            //if (it1 == pattern_map.end())
            map<char, int>::iterator iter1 = pattern_map.find(pattern[i]);
            map<string, int>::iterator iter2 = str_map.find(words[i]);
            int i1 = (iter1 == pattern_map.end() ? -1 : pattern_map[pattern[i]]);
            int i2 = (iter2 == str_map.end() ? -1 : str_map[words[i]]);

            if(i1 != i2)
                return false;

            pattern_map[e1] = i;
            str_map[e2] = i;

        }

        return true;
    }


private:

    vector<string> Split(string str){
        vector<string> res;
        const char s[2] = " ";
        char *token;
        /* 获取第一个子字符串 */
        token = strtok((char*)str.c_str(), s);
        /* 继续获取其他的子字符串 */
        while( token != NULL ) {
            //printf( "%s\n", token );
            res.push_back(token);
            token = strtok(NULL, s);
        }

        return res;

    }
};


int main(){

    Solution sl;


    bool ret = sl.wordPattern("abba","dog cat cat dog");
    printf("match pattern %s \n", ret?"yes":"no");
    ret = sl.wordPattern("abba","dog cat cat fish");
    printf("match pattern %s \n", ret?"yes":"no");
    ret = sl.wordPattern("aaaa","dog cat cat dog");
    printf("match pattern %s \n", ret?"yes":"no");
    ret = sl.wordPattern("abba","dog dog dog dog");
    printf("match pattern %s \n", ret?"yes":"no");
    ret = sl.wordPattern("aba","dog cat cat");
    printf("match pattern %s \n", ret?"yes":"no");

}