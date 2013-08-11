#ifndef CONNECTION_H_INCLUDED
#define CONNECTION_H_INCLUDED

#define _WIN32_WINNT 0x0501
#include "boost/asio.hpp"
#include "Readers/AsyncReader.h"

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
    virtual error_code Connect() = 0;
    virtual error_code Disconnect() = 0;
    virtual error_code AsyncRead() = 0;
    const size_t BufferSize() const;                // Returns number of elements stored in the buffer
    const size_t BufferCapacity() const;            // Returns number of elements that would fit in the buffer
    void SetBufferCapacity(const size_t capacity);   // Set number of elements that would fit in the buffer
    const DataBucket& GetData() const;

protected:
    boost::shared_ptr<boost::asio::io_service> io_service;                  // requires io_service to function.  Guess take a shared pointer to it?
    boost::shared_ptr<DataBucket> rawData;
    boost::shared_ptr<AsyncReader> reader;

};

#endif // CONNECTION_H_INCLUDED
