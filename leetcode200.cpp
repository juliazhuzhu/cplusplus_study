#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector< vector<char > >& grid) {
        num_of_islands = 0;
        m = grid.size();
        if (m == 0)
            return num_of_islands;
        n = grid[0].size();
        visited = vector<vector<bool> >(m, vector<bool>(n, false));
        for (int i = 0 ; i < m ; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1' && !visited[i][j]){
                    num_of_islands ++;
                    searchIslands(grid,i,j);
                }
        
        return num_of_islands;

    }

private:

    bool inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void searchIslands(vector< vector<char > >& grid,int startX, int startY){

        if (visited[startX][startY] == false){
            visited[startX][startY] = true;
            if (grid[startX][startY] == '1'){
                for( int i = 0 ; i < 4 ; i ++ ){
                    int newx = startX + d[i][0];
                    int newy = startY + d[i][1];
                    if( inArea(newx, newy) && !visited[newx][newy])
                        searchIslands(grid,newx,newy);
                    }
            }
            //visited[startX][startY] = false;
            
        }

    }

    int num_of_islands;
    int d[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
    int m, n;
    vector<vector<bool> > visited;
};

void printVector(vector<vector<char > > res){

    cout<<"["<<endl;
    for (int i =0 ;i < res.size() ; i++){
        cout<<"     [";
        for(int j=0; j < res[i].size(); j++)
        {
            cout<<res[i][j];
            if (j != res[i].size()-1)
                cout<<",";
        }
        cout<<"]";
        if (i != res.size()-1)
            cout<<",";
        cout << endl;
    }
    cout<<"]"<<endl;
}

int main(){

    return 1;
}