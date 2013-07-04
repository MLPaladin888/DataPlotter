#include "Connection/Connection.h"

Connection::Connection(boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service)
    : isConnected(false),
    io_service(shared_ptr_io_service)

{}

Connection::~Connection() {}
