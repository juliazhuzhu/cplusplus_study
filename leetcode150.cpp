#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> ops;
        for (int i=0; i<tokens.size();i++){
            string c = tokens[i];
            if (isArithmeticExpression(c)){
                int l1,l2,ret = 0;
                l1 = atoi(ops.top().c_str());
                ops.pop();
                l2 = atoi(ops.top().c_str());
                ops.pop();
                if (c.compare("+") == 0){
                    ret = l1 + l2;
                }else if (c.compare("-") == 0){
                    ret = l2 - l1;
                }else if (c.compare("*") == 0) {
                    ret = l2 * l1;
                }
                else if (c.compare("/") == 0) {
                    ret = l2 / l1;
                }

                char buf[64] = {0};
                sprintf(buf,"%d",ret);
                ops.push(buf);
            }
            else {
                ops.push(c);
            }               
            
        }

        assert(ops.size() != 0);
        return atoi(ops.top().c_str());        
    }

private:
    bool isArithmeticExpression(string token){

        if (token.compare("+") == 0||
            token.compare("-") == 0||
            token.compare("*") == 0||
            token.compare("/") == 0)
            return true;
        
        return false;
    }
};

int main(){
    string inputs[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::vector<string> v(inputs, inputs+13);
    Solution sl;
    printf("%d \n",sl.evalRPN(v));


    return 1;
}
