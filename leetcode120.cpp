#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        /*sum = 0;
        current_sum = 0;
        first = 0;
        backtrace(triangle, 0,0);
        return sum;*/

        int n = triangle.size();
        for(int i = 1 ; i < n ; i ++){

            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
            for(int j = 1 ; j < i ; j ++)
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        }

        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }

private:

    void backtrace(vector<vector<int> >& triangle, int layer, int index){

        if (layer == triangle.size()){
            //printf("layer %d current_sum %d\n", layer,current_sum);
            if (first == 0){
                sum = current_sum;
                first++;
            }
            else
                sum = min(current_sum, sum);
            //printf("sum %d \n", sum);
            return;
        }

        for (int i = index; i < triangle[layer].size(); i++){
            int added = triangle[layer][i];
            //printf("layer %d, i %d ,added %d \n", layer, i, added);
            if (i > index + 1)
                return;
            layer = layer + 1;
            current_sum = current_sum + added;
            if (i == 0)
                backtrace(triangle, layer, i);
            else
                backtrace(triangle, layer, i-1);
            layer = layer - 1;
            current_sum = current_sum - added;
        }

    }
    int     sum;
    int     first;
    int     current_sum;
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
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
*/

/*
[[-1],
[2,3],
[1,-1,-3]]
*/

/*
[[-1],
[2,3],
[1,-1,-1]]
*/
int main() {

    //vector<vector<int > > res;
   /* vector<int > layer1;
    layer1.push_back(2);
    res.push_back(layer1);
    vector<int > layer2;
    layer2.push_back(3);
    layer2.push_back(4);
    res.push_back(layer2);
    vector<int > layer3;
    layer3.push_back(6);
    layer3.push_back(5);
    layer3.push_back(7);
    res.push_back(layer3);
    vector<int > layer4;
    layer4.push_back(4);
    layer4.push_back(1);
    layer4.push_back(8);
    layer4.push_back(3);
    res.push_back(layer4);*/

    /*vector<int > layer1;
    layer1.push_back(-1);
    res.push_back(layer1);
    vector<int > layer2;
    layer2.push_back(2);
    layer2.push_back(3);
    res.push_back(layer2);
    vector<int > layer3;
    layer3.push_back(1);
    layer3.push_back(-1);
    layer3.push_back(-3);
    res.push_back(layer3);*/


   /*vector<vector<int> > triangle = { {-1},
                                     {3, 4},
                                     {1,-1,3}
                                    };*/

    vector<vector<int> > triangle = { {2},
                                     {3, 4},
                                     {6,5,7},
                                     {1,4,8,3}
                                    };


    printVec(triangle);

    printf("min sum %d \n",Solution().minimumTotal(triangle));

    return 1;
}