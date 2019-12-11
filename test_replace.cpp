#include <iostream>
#include <string>
#include <boost/algorithm/string/replace.hpp>
 
int main()
{
    std::string str1("Quick+brown+fox");
    std::string str2 =  boost::replace_all_copy(str1, "+", " ");
    std::cout << str2 << "\n";
}