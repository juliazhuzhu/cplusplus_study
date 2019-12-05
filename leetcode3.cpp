#include <string>
using namespace std;

class Solution {
private:
    
public:
    int lengthOfLongestSubstring(string s) {
        
        int freq[256] = {0};
        int l = 0, r = -1; //[l...r]
        int res = 0;
        while (l < s.size()){
            
            if ((r + 1) < s.size() && freq[s[r+1]] == 0)
                freq[s[++r]] ++;
            else{
                freq[s[l++]]--;
                printf("freq[%d] %d\n", s[l -1],freq[s[l-1]]);
            }
               

            printf("r %d , l %d \n", r,l);
            
            res = max(res, r-l+1);
            
        }
        

        
        return res;
        
        
    }

};


int main() {

    Solution s1;
    int res = s1.lengthOfLongestSubstring("abcbd");

    printf("result %d \n", res);
}