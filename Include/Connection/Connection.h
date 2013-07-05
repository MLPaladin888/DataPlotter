#ifndef CONNECTION_H_INCLUDED
#define CONNECTION_H_INCLUDED

#define _WIN32_WINNT 0x0501
#include "boost/asio.hpp"

typedef boost::system::error_code error_code;

class Connection
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// Abstract Type.  Maybe a Serial Port.  Maybe a TCP Socket.  Maybe a Tin Can & String. ////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
public:
    bool isConnected;
    Connection(boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service);
    ~Connection();
    virtual error_code Connect() = 0;       // should this be virtual?  All children classes should implement.
    virtual error_code Disconnect() = 0;                                    // but they may take different parameters.  :(

protected:
    boost::shared_ptr<boost::asio::io_service> io_service;                  // requires io_service to function.  Guess take a shared pointer to it?
};

#endif // CONNECTION_H_INCLUDED
