#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        
       /* paths = 0;
        backtrace(obstacleGrid,0,0);
        return paths;*/

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));


    }


private:

    
    int dfs(vector<vector<int> >& obstacleGrid, int x, int y, vector<vector<int> >& dp){

        if(x == 0 || y == 0) return 1;
        if(dp[x][y]) return dp[x][y];

        if (obstacleGrid[x][y] == 1){
            dp[x][y] = 0;
            return dp[x][y] = 0;
        }

        int res = dfs(obstacleGrid,x - 1, y, dp) + dfs(obstacleGrid,x, y - 1, dp);
        return dp[x][y] = res;
    }


    void backtrace(vector<vector<int> >& obstacleGrid, int i, int j){

        
        
        if ( (i == obstacleGrid.size() -1 )&& (j == obstacleGrid[0].size() - 1)){
            paths ++;
            return;
        }

        if (i == obstacleGrid.size() || j == obstacleGrid[0].size()){
            return;
        }

        if (obstacleGrid[i][j] == 1)
            return;

        backtrace(obstacleGrid,i + 1,j);
        backtrace(obstacleGrid,i ,j + 1);
    }

    int paths;
};

