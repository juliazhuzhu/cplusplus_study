
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        

        for (int i=0; i < grid.size(); i++){

            for (int j=0; j < grid[0].size(); j++){
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0 && j != 0)
                    grid[i][j] = grid[i][j] + grid[i][j-1];
                else if (j == 0 && i != 0)
                    grid[i][j] = grid[i][j] + grid[i-1][j];
                else 
                    grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
            }

        }
        return grid[grid.size() -1][grid[0].size()-1];
    }

    

};

void printVec(vector<vector<int > > res){ 

    for (int i=0 ;i < res.size(); i++){
        cout<<"[";
        for (int j = 0; j< res[i].size(); j++){
            cout<<res[i][j];
            if (j != res[i].size() -1)
                cout<<",";
        }

        cout<<"]"<<endl;
    }
}

/*

[[1,3,1],[1,5,1],[4,2,1]]
*/
int main() {


    vector<vector<int> > grid = {   {1,3, 1},
                                    {1,5, 1},
                                     {4,2,1}
                                    };


    printVec(grid);

    printf("%d\n",Solution().minPathSum(grid));

    return 1;
}