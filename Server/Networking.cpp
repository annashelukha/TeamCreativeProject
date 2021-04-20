#include <iostream>
#include <boost/asio.hpp>
#include "networking.h"

using namespace boost::asio;

class networking: public boost::enable_shared_from_this(networking)
{
  static pointer create(boost::asio::io_service& io_service)
  {
    return pointer(new con_handler(io_service));
  }

  tcp::socket& socket()
  {
    return socket;
  }

  void start()
  {
    boost::asio::async_read(socket, boost::asio::buffer(message_),
			    boost::bind(&tcp_connection::handle_write, shared_from_this()));

    boost::asio::async_write(socket, boost::asio::buffer(message_),
			     boost::bind(&tcp_connection::handle_write, shared_from_this()));
  }
  void read()
  {
    std::cout << "In read" << std::endl;
  }

  void write()
  {
    std::cout << "In write" << std::endl;
  }
}
