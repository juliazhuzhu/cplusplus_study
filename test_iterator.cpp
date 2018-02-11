#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char** argv){

    std::list<int> lst1;

    vector<int> vec_z;
    vec_z.push_back(1);
    vec_z.push_back(1);
    vec_z.push_back(1);
    vec_z.push_back(1);
    vec_z.push_back(1);
    vec_z.push_back(2);
    vec_z.push_back(2);
    vec_z.push_back(2);
    vec_z.push_back(2);
    vec_z.push_back(2);
    vec_z.push_back(3);
    vec_z.push_back(4);
    //vec_z.push_back(2);
    vec_z.push_back(5);

    unique_copy(vec_z.begin(),vec_z.end(),front_inserter(lst1));

    for_each(lst1.begin(), lst1.end(),[](int t){cout<<t<<endl;});

    return 1;
}