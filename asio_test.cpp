
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>


void print(const boost::system::error_code& /*e*/)
{
  std::cout << "Hello, world!" << std::endl;
}

void print(const boost::system::error_code& /*e*/,
    boost::asio::deadline_timer* t, int* count)
{
  if (*count < 5)
  {
    std::cout << *count << std::endl;
    ++(*count);

    t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
    t->async_wait(boost::bind(print,
          boost::asio::placeholders::error, t, count));
  }
}


int main()
{
   //n this simple example we perform a blocking wait on the timer. 
   //That is, the call to deadline_timer::wait() will not return until the timer has expired, 5 seconds after it was created  
 /* boost::asio::io_service io;

  boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
  t.wait();

  std::cout << "Hello, world!" << std::endl;
*/

// callback handlers will only be called from threads that are currently calling io_service::run().
/*
  boost::asio::io_service io;

  boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
  t.async_wait(&print);

  std::cout << "Going on" <<std::endl;

  io.run();
  */

    /*
    boost::asio::io_service io;

    int count = 0;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));
    t.async_wait(boost::bind(print,
    boost::asio::placeholders::error, &t, &count));

    io.run();

    std::cout << "Final count is " << count << std::endl;
    */
     
    
  return 0;
}