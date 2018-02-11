

#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>

#include <set>
#include <memory>
#include <functional>
#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_inserter.hpp>
#include <boost/scope_exit.hpp>
#include <array>
#include <algorithm>
#include <boost/config.hpp>
#include <boost/detail/lightweight_test.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <typeinfo>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>
#include <thread>
#include <map>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

void reset(boost::shared_ptr<int> &sh)
{
  sh.reset();
}

void print(boost::weak_ptr<int> &w)
{
  boost::shared_ptr<int> sh = w.lock();
  if (sh)
    std::cout << *sh << '\n';
}


//#define BOOST_SP_USE_QUICK_ALLOCATOR
/*
  BOOST_SCOPE_EXIT is used to define a block that will be executed when the scope 
  the block is defined in ends. In Example foo the block defined with BOOST_SCOPE_EXIT 
  is executed just before foo() returns.
*/

static int g_couter = 8;
int* get_couter(){
  return &g_couter;
}

void dec_couter(int* j){
  printf("dec_couter %d \n", *j);
  g_couter = g_couter -(*j);
  //delete j;
}

int *foo()
{
  int *i = new int{10};
  BOOST_SCOPE_EXIT(&i)
  {
    delete i;
    i = 0;
  } BOOST_SCOPE_EXIT_END
  std::cout << *i << '\n';
  return i;
}


class xiaoyeTest{
public:

  void init() {
    curent_val = 1;
    map<string, string> value_map;

    printf("xiaoye TEst \n");
    value_map.insert(make_pair("1","mac"));
    value_map.insert(make_pair("2","thinkpad"));

    
    std::for_each(value_map.begin(),value_map.end(),[this](const std::pair<string, string>& pair)
												{ 
													cout<<pair.first<<":"<<pair.second<<endl;
                          cout<<get_value()<<std::endl;
													
												}
				);
  }

  int get_value() { return curent_val;};

  private:

    int curent_val;

};

int main()
{
 
 
  //solo ownership pointer
  /*
  boost::scoped_ptr<int> p{new int{1}};
  std::cout << *p << '\n';
  int * t = p.get();
  *t = 2;
  printf("t = %d\n", *t);
  p.reset(new int{2});
  std::cout << *p.get() << '\n';
  p.reset();
  std::cout << std::boolalpha << static_cast<bool>(p) << '\n';

  long * lp = new long;
  boost::scoped_ptr<long> dp ( lp );
  BOOST_TEST( dp.get() == lp );

  */
		
 //solo ownership pointer array	
 /*
  boost::scoped_array<int> sp{new int[2]};
  *p.get() = 1;
  sp[0] = 1;
  sp[1] = 2;
  sp.reset(new int[3]);
  */

  //auto ptr 可以转让owner ship
  //copy constructor release the left pointer, and allocate a new one to the right.
  /*
  std::auto_ptr<int> pt1( new int{5} );
  std::auto_ptr<int> pt2;

  pt2 = pt1;
  //pt1.reset();
  std::cout << *pt2.get() << '\n';
  std::cout << *pt1.get() << '\n';
  */

  // scoped_ptr 有着与std::auto_ptr类似的特性，而最大的区别在于它不能转让所有权而auto_ptr可以
  /*
  boost::scoped_ptr<int> spt1( new int{6} );
  boost::scoped_ptr<int> spt2;
  
  spt2 = spt1;
  spt1.reset();
  std::cout << *spt2.get() << '\n';
  */

  //return a reference to a dynamically allocated object and not a pointer.
  /*boost::ptr_vector<int> v;
  v.push_back(new int{1});
  v.push_back(new int{2});
  std::cout << v.back() << '\n';
  */

  /*
    With boost::ptr_set, the order of the elements depends on the int values. 
    std::set compares pointers of type std::unique_ptr and not the variables the pointers refer to
  */
  /*
  boost::ptr_set<int> s;
  s.insert(new int{2});
  s.insert(new int{1});
  std::cout << *s.begin() << '\n';

  std::set<std::unique_ptr<int>, boost::indirect_fun<std::less<int>>> v;
  v.insert(std::unique_ptr<int>(new int{2}));
  v.insert(std::unique_ptr<int>(new int{1}));
  std::cout << **v.begin() << '\n';
  */

  /*
  boost::ptr_vector<int> v;
  std::array<int, 3> a{{0, 1, 2}};
  std::copy(a.begin(), a.end(), boost::ptr_container::ptr_back_inserter(v));
  std::cout << v.size() << '\n';
  */


  /*
  int *j = foo();
  std::cout << j << '\n';
  */
  
  //int *j = foo_2();
  //std::cout << j << '\n';

/*
  //the shared object is not released until the last copy of the shared 
  //pointer referencing the object is destroyed. 
  boost::shared_ptr<int> p1{new int{1}};
  std::cout << *p1 << '\n';
  boost::shared_ptr<int> p2{p1};
  p1.reset(new int{2});
  std::cout << *p1.get() << '\n';
  p1.reset();
  std::cout << *p2.get() << '\n';
  std::cout << std::boolalpha << static_cast<bool>(p2) << '\n';
*/

  /*
  //Using boost::make_shared() is more efficient than calling new to create 
  //a dynamically allocated object and calling new again in the constructor 
  //of boost::shared_ptr to allocate memory for the reference counter.
  auto p1 = boost::make_shared<int>(1);
  std::cout << typeid(p1).name() << '\n';
  auto p2 = boost::make_shared<int[]>(10);
  std::cout << typeid(p2).name() << '\n';
  */

  //As a second parameter, a deleter can be passed to the constructor
  // of boost::shared_ptr.
  /*
  int * p = new int{8};
  boost::shared_ptr<int> tester(p,dec_couter);

  std::cout<<*tester.get()<< "\n";
  tester.reset();

  printf("g_couter %d\n", g_couter);
  std::cout<<*p<< "\n";
  */
  
  
  //shared the pointer array
  //the smart pointers p1 and p2 share ownership of the dynamically allocated int array. 
  //When the array in p2 is accessed with operator[] to store the number 1, 
  //the same array is accessed with p1. Thus, the example writes 1 to standard output.
  /*
  boost::shared_array<int> p1{new int[1]};
  {
    boost::shared_array<int> p2{p1};
    p2[0] = 1;
  }
  std::cout << p1[0] << '\n';
  */

  /*
  boost::shared_ptr<int> p;
  std::time_t then = std::time(nullptr);
  for (int i = 0; i < 10000000; ++i)
    p.reset(new int{i});
  std::time_t now = std::time(nullptr);
  std::cout << now - then << '\n';
  */

  //lock() returns a shared pointer that points to a valid object if one exists at the time of the call. 
  //If not, the shared pointer is set to 0 and is equivalent to a null pointer.
  /*
  boost::shared_ptr<int> sh{new int{99}};
  boost::weak_ptr<int> w{sh};
  std::thread t1{reset, std::ref(sh)};
  std::thread t2{print, std::ref(w)};
  t1.join();
  t2.join();
  */
/*
  std::map<std::string, std::string> value_map;


  value_map.insert(std::make_pair("1","mac"));
  value_map.insert(std::make_pair("2","thinkpad"));

  std::for_each(begin(value_map), end(value_map),
           [](std::pair<std::string, std::string> pair){ std::cout << pair.first << " has value " << pair.second << std::endl;});
*/
  xiaoyeTest test;
  test.init();
	return 0;
}
