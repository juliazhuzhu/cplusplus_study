#include <boost/uuid/uuid.hpp>  
#include <boost/uuid/uuid_generators.hpp>  
#include <boost/uuid/uuid_io.hpp>  

#include <iostream>  
#include <vector>  
#include <assert.h>  
#include <boost/uuid/uuid.hpp>  
#include <boost/uuid/uuid_generators.hpp>  
#include <boost/uuid/uuid_io.hpp>  
#include <boost/random/random_device.hpp>  
#include <boost/random.hpp>
//#include <boost/generator_iterator.hpp"> 

using namespace boost::uuids;  
using namespace std;  


/*int randString()   
{  
    // We first define the characters that we're going 
     //    to allow.  This is pretty much just the characters 
      //   on a standard keyboard. 
      
    std::string chars(  
        "abcdefghijklmnopqrstuvwxyz"  
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"  
        "1234567890"  
        "!@#$%^&*()"  
        "`~-_=+[{]}\\|;:'\",<.>/? ");  
    //<< We use __random_device as a source of entropy, since we want 
      //   passwords that are not predictable. 
      
    boost::random::random_device rng;  
    //<< Finally we select 8 random characters from the 
      //   string and print them to cout. 
      
    boost::random::uniform_int_distribution<> index_dist(0, chars.size() - 1);  
    for(int i = 0; i < 8; ++i) {  
        std::cout << chars[index_dist(rng)];  
    }  
    std::cout << std::endl;  
}  */

   
int main()  
{  
   /* uuid u;  
    std::fill_n(u.begin(), u.size(), 0xab);  
    cout<<u<<endl;  
    std::memset(u.data, 0, 16);  
    cout<<u<<endl;  
  
    //字符串生成器对象  
    string_generator sgen;   
    uuid u0 = sgen("01-23456789abcdef0123456789abcdef");  
    cout<<u0<<endl;  */
   

    /*random_generator rgen;//随机生成器  
    uuid u4 = rgen();//生成一个随机的UUID  
    cout<<u4<<endl;  */
    //randString();

    return 0;
}