#ifndef ASYCREADER_H_INCLUDED
#define ASYCREADER_H_INCLUDED

#include <vector>
#include <cstdlib>
#include "boost/thread.hpp"
#define _WIN32_WINNT 0x0501
#include "boost/asio.hpp"
#include "DataBucket/DataBucket.h"
#include "boost/enable_shared_from_this.hpp"

class AsyncReader : public boost::enable_shared_from_this<AsyncReader>
{
private:
    boost::shared_ptr<boost::asio::io_service> io_service;
    std::vector<char> dataArray;
    void ReadCompleteHandler(const boost::system::error_code& error, std::size_t bytes_transferred, boost::shared_ptr<DataBucket> bucket);
    bool readInProcess;

public:
    AsyncReader(boost::shared_ptr<boost::asio::io_service> io_serv, const size_t dataFrameSize);
    ~AsyncReader();
    void AsyncRead( boost::shared_ptr<boost::asio::serial_port> streamToReadFrom, boost::shared_ptr<DataBucket> readIntoHere);
};



#endif // ASYCREADER_H_INCLUDED
