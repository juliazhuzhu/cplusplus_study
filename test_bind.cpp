
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using std::placeholders::_1;

bool is_greater(const string &s, int len){
    cout<<s<<endl;
    return s.size() >= len;
}

int main(int argc, char** argv){

    vector<string> words;
    words.push_back("hero");
    words.push_back("cascade");
    words.push_back("nekolas");
    words.push_back("classic");
    words.push_back("tmo");
    words.push_back("jd");
    words.push_back("blaster");
    words.push_back("huizhao");
    words.push_back("xinmu");
    words.push_back("ricard");
    words.push_back("david");
    int sz = 6;
    //auto wc = find_if(words.begin(), words.end(), [=](const string &s)
      //                                              { return s.size() >= sz;});

    auto wc2 = find_if(words.begin(), words.end(), bind(is_greater,_1,sz));

    
    //user_info.source_ip = last_ip;
   /* ostream &os = cout;
    char c = ' ';
    for_each(wc.begin(), wc.end(), [&os, c](const string &s){ os <<s <<c;} );*/
    string test;
    printf("test length %d\n",strlen(test.c_str()));

    return 1;
}