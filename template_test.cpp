
#include <string>

template<class T> 
class Topic{
public:
    T* sub;

};

typedef Topic<std::string> MeTopic;

int main() {

    std::string name = "me";
    MeTopic metopic;
    //metopic.sub = name;
    metopic.sub = &name;
    std::string mcu_addr = "123456@172.24.0.1";
    int start = mcu_addr.find("@") + 1;
    if (start == std::string::npos){
        return 0;
    }
    int end = mcu_addr.length();
    std::string ip = mcu_addr.substr(start,end-start);  

    printf("ip %s\n",ip.c_str());

    end = mcu_addr.find("@");
    std::string conf_number = mcu_addr.substr(0,end);
    printf("conf_number %s\n",conf_number.c_str());

    return 1;
}