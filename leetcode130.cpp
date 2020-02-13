#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        
        m = board.size();
        if (m == 0)
            return;
        n = board[0].size();
        visited = vector<vector<bool> >(m,vector<bool>(n, false));
        vector<pair<int,int> > record;
        for (int i = 0; i < m ; i++)
            for (int j = 0; j < n; j++)
                    if (board[i][j] == 'O' && !visited[i][j]){
                        record.clear();
                        if (bfs(board,i,j,record)) {
                            for(int k = 0 ; k < record.size() ; k ++)
                                board[record[k].first][record[k].second] = 'X';
                        }
                    }
    }

private:

    bool bfs(vector<vector<char> >& board, int x, int y,vector<pair<int,int> >& record){

        queue<pair<int,int> > q;
        q.push(make_pair(x,y));
        visited[x][y] = true;
        bool ret = true;
        while (!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            record.push_back(pair<int, int>(cur.first, cur.second));
            //visited[xx][yy] = true;
          //  printf("xx %d, yy %d \n", xx,yy);
            
           
            for (int i=0; i<4; i++){

                int newx = cur.first + d[i][0];
                int newy = cur.second + d[i][1];
                
                if (!inArea(newx,newy)){
                    //the xx and yy is at edge
                    //hence is not suroud by x
                    ret =  false;
                }
                else if( board[newx][newy] == 'O' && !visited[newx][newy]){
                    visited[newx][newy] = true;
                    q.push(make_pair(newx, newy));
                 //   printf("newx %d, newy %d \n", newx,newy);
                }

            }
        }
        
        return ret;
    }

    bool dfs(vector<vector<char> >& board, int x, int y,vector<pair<int,int> >& record){

        if (board[x][y] == 'O' && !visited[x][y])    {
            //board[x][y] = 'X';
            record.push_back(make_pair(x,y));
            visited[x][y] = true;
           // printf("x %d, y %d \n",x,y);
            //printf("put x %d, y %d \n", x,y);
            for( int i = 0 ; i < 4 ; i ++ ){
                int newx = x + d[i][0];
                int newy = y + d[i][1];
                if (!inArea(newx,newy)){
                    visited[x][y] = false;
                    return false;
                }
                //printf("newx %d newy %d \n", newx, newy);
                if( board[newx][newy] == 'O'){
                    if (dfs(board,newx,newy,record) == false){
                        //printf("pop x %d, y %d \n", x,y);
                        visited[x][y] = false;
                        return false;
                    }
                }
            }
        }

        return true;

    }
    bool inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int m;
    int n;
    int d[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
    vector<vector<bool> >   visited;
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

/*
    char board_array[9][9] =
    {
        {'O','X','O','O','O','O','O','O','O'},{'O','O','O','X','O','O','O','O','X'},{'O','X','O','X','O','O','O','O','X'},
        {'O','O','O','O','X','O','O','O','O'},{'X','O','O','O','O','O','O','O','X'},{'X','X','O','O','X','O','X','O','X'},
        {'O','O','O','X','O','O','O','O','O'},{'O','O','O','X','O','O','O','O','O'},{'O','O','O','O','O','X','X','O','O'}
    };

    int m = 9, n = 9;

    char board_array[6][6] =
    {
        {'O','O','O','O','X','X'},
        {'O','O','O','O','O','O'},
        {'O','X','O','X','O','O'},
        {'O','X','O','O','X','O'},
        {'O','X','O','X','O','O'},
        {'O','X','O','O','O','O'}
    };
    int m = 6, n = 6;
    */
    char board_array[4][4] = {
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}
    };
    int m = 4, n = 4;
    vector<vector<char> > board = vector<vector<char> >(n, vector<char>(m, ' '));

    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            board[i][j] = board_array[i][j];

    printVector(board);

    Solution().solve(board);
    printVector(board);


    return 1;
}