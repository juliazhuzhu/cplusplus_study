#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int > > q;

        q.push(make_pair(beginWord,1));
        map<string,int> visited;
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word.compare(endWord) == 0){
                return step;
            }
            vector<string> res = nextLayerWords(word, wordList);
            for (int i = 0; i< res.size(); i++){
                if (visited[res[i]] == 0){
                    q.push(make_pair(res[i],step + 1));
                    visited[res[i]]= 1;
                }
            }


        }

        return 0;

    }

private:

    vector<string> nextLayerWords(string word,vector<string>& wordList){
        vector<string> res;

        for (int i = 0; i < wordList.size(); i++){
            int diff_char = 0;
            for (int j = 0; j < word.size();j ++){
                if (word[j] != wordList[i][j])
                    diff_char ++;
            }
            if (diff_char == 1){
                //printf("%s ", wordList[i].c_str());
                res.push_back(wordList[i]);
            }
        }
       // printf("\n");

        return res;
    }
};


int main(){
    string beginWord = "hit";
    string endWord = "cog";
    string wordListArr[] = {"hot","dot","dog","lot","log","cog"};
    vector<string> wordList(wordListArr,wordListArr+6);

    Solution sl;
    int step = sl.ladderLength(beginWord,endWord,wordList);

    printf("step %d \n", step);

}