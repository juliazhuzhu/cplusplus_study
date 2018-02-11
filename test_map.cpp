
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){

    map<string, string> info_out;
    info_out["abc"] = "1";

    printf("%s \n",info_out["abc"].c_str());
    printf("%s \n",info_out["bbb"].c_str());
    return 0;
}


