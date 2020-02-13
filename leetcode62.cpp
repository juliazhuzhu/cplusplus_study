#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        paths = 0;
        backtrace(m,n,0,0);
        return paths;
    }



private:

    void  backtrace(int m, int n, int i, int j){

        if ( (i == m -1) && (j == n -1)){
            paths ++;
            return;
        }

        if (i == m || j == n){
            return;
        }

        backtrace(m, n, i+1,j);
        backtrace(m, n, i, j+1);
    }
    int     paths;
};
*/

class Solution {

public:
    int uniquePaths(int m, int n) {

        vector<vector<int> > dp(m, vector<int>(n, 0));
        return dfs(m - 1, n - 1, dp);
    }

private:
    int dfs(int x, int y, vector<vector<int> >& dp){

        if(x == 0 || y == 0) return 1;
        if(dp[x][y]) return dp[x][y];

        int res = dfs(x - 1, y, dp) + dfs(x, y - 1, dp);
        return dp[x][y] = res;
    }
};

int main(){

    
    printf("%d \n",Solution().uniquePaths(23,12));
}

