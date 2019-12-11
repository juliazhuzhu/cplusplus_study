
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

typedef struct _call_info{
    std::string call_id;
    std::string conf_id;
    std::string mru_ip;
}call_info;

void test_print(int ttt){
    printf("test %d \n",ttt);
}

int main(){

    map<string, string> info_out;
    info_out["abc"] = "1";

    //printf("%s \n",info_out["abc"].c_str());
    //printf("%s \n",info_out["bbb"].c_str());

    info_out["abc"] = "2";
    //printf("%s \n",info_out["abc"].c_str());
    info_out.clear();
    info_out.erase("abc");
    //string ip_forward_list = "114.245.40.112,172.31.9.14,1.1.1.1";
    string ip_forward_list = "114.245.40.112";
    size_t pos = ip_forward_list.find(",");
    if ( pos == string::npos){
        pos = ip_forward_list.size();
    }
    

    string first_ip = ip_forward_list.substr(0, pos);
    //printf("%s\n", first_ip.c_str());

    map<string, call_info> call_map;

  
    call_map["124"].call_id = "asdfadsf";
    call_map["124"].conf_id = "jjjjjj";
    call_map["124"].mru_ip = "10.1.1.1";
    printf("%s \n",call_map["124"].call_id.c_str());
    printf("%p \n",&call_map["333"]);
    printf("%s \n",call_map["333"].conf_id.c_str());
    printf("%s \n",call_map["124"].mru_ip.c_str());

    call_map["333"].call_id="uuuuu";
    call_map["333"].conf_id="ffffff";
    printf("%s \n",call_map["333"].conf_id.c_str());


    string test;
    printf("test length %d\n",strlen(test.c_str()));


    int a = 0;
    int b = 1;

    if (a == 0 && b > 0){
        printf("operator okay \n");
    }

    printf("1. call_map.size() %d \n",call_map.size());
    std::string key = "124";
    call_map.erase(key);
    printf("2. call_map.size() %d \n",call_map.size());

    std::queue<int> m_queue;

    for (int t = 0 ; t< 200; t++){
        m_queue.push(t);
        printf("m_queue.size() %d \n",m_queue.size());
    }
    int i = 0;
    //test_print(i++);

    test_print(++i);

    auto it = call_map.begin();

    for (;it != call_map.end();){
        call_map.erase(it++);
    }// to erase elements in a iterate way.
    // it++ will return the previus element before ++;
    return 0;
}


