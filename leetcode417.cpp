#include <vector>
#include <iostream>
#include <queue>

/*
417 bfs 比较合适
可以考虑是逆流的方向，哪些点能流经到Pacific又能流向Atalantic
初始化一个矩阵来定义这个边界，Pacific边01,Atalantic 10，复合条件的点，在bfs过程中
异或

构建一个状态矩阵：
用第一个bit存储太平洋是否能达到此点
用第二个bit存储大西洋是否能达到此点
最终查询点状态为3（二进制为11）的点即可。

bfs各个边，最终就是检查即能流向Pacific又能流向Atalantic的点值一定是 11(3)
*/
using namespace std;
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    vector<vector<int> > pacificAtlantic(vector<vector<int> >& matrix) {
        vector<vector<int> > res;
        if (matrix.empty()) return res;
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int> > status(R, vector<int>(C, 0));
        queue<pair<int, int> > q;
        for (int i = 0; i < R; ++i) {
            q.push({i, 0});
            status[i][0] |= 1;
            q.push({i, C - 1});
            status[i][C - 1] |= 2;
        }
        for (int i = 0; i < C; ++i) {
            q.push({0, i});
            status[0][i] |= 1;
            q.push({R - 1, i});
            status[R - 1][i] |= 2;
        }

        //q.push( {0,1} );
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int r = p.first + dirs[i][0];
                int c = p.second + dirs[i][1];
                if (valid(r, c, R, C) && matrix[r][c] >= matrix[p.first][p.second]) {
                    if (status[r][c] != status[p.first][p.second]) {
                        status[r][c] |= status[p.first][p.second];
                        q.push({r, c});
                    }
                }
            }
        }
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (status[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

void printVector(vector<vector<int > > res){

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

    int matrix_arr[5][5] = {
                {1,   2,   2,   3,  5},
                {3,   2,   3,   4,  4},
                {2,   4,   5,   3,  1},
                {6,   7,   1,   4,  5},
                {5,   1,   1,   2,  4}
        };
    
    int m = 5, n = 5;
    vector<vector<int> > matrix = vector<vector<int> >(n, vector<int>(m, 0));

    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            matrix[i][j] = matrix_arr[i][j];

    printVector(matrix);

    printVector(Solution().pacificAtlantic(matrix));

    return 1;
}