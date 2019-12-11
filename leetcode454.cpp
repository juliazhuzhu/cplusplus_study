#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int i=0;
        int j=0;
        unordered_map<int,int> record;
        for (i=0;i<A.size(); i++)
            for(j=0;j<B.size(); j++)
                record[A[i]+ B[j]]++;
        
        int res = 0;
        for (i=0;i<C.size(); i++)
            for(j=0;j<D.size(); j++){
                if (record.find(0-C[i]-D[j]) != record.end()){
                    res +=record[0-C[i]-D[j]];
                }
            }
        return res;

    }

    
};


int main(){
    return 1;
}