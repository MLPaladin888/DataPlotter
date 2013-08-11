#include "Readers/AsyncReader.h"

AsyncReader::AsyncReader(boost::shared_ptr<boost::asio::io_service> io_serv, const size_t dataFrameSize)
        : io_service(io_serv), dataArray(std::vector<unsigned char>(dataFrameSize,0))
{
    #ifdef ASYNCREADER_DEBUG
        std::cout << "Creating AsyncReader object.\n";
    #endif // ASYNCREADER_DEBUG
}

AsyncReader::~AsyncReader()
{
    #ifdef ASYNCREADER_DEBUG
         std::cout << "Destroying AsyncReader object.\n";
    #endif // ASYNCREADER_DEBUG
}

void AsyncReader::AsyncRead(boost::shared_ptr<boost::asio::serial_port> streamToReadFrom, boost::shared_ptr<DataBucket> bucket)
{
    if(!readInProcess)
    {
        #ifdef ASYNCREADER_DEBUG
            std::cout << "Queuing async_read operation.\n";
        #endif // ASYNCREADER_DEBUG

        readInProcess = true;
        boost::asio::async_read(*streamToReadFrom, boost::asio::buffer(dataArray),
                                    boost::bind(&AsyncReader::ReadCompleteHandler,
                                                    shared_from_this(),
                                                    boost::asio::placeholders::error,
                                                    boost::asio::placeholders::bytes_transferred,
                                                    bucket) );
    }
}

void AsyncReader::ReadCompleteHandler(const boost::system::error_code& error, std::size_t bytes_transferred, boost::shared_ptr<DataBucket> bucket)
{
    if(!error)
    {
        #ifdef ASYNCREADER_DEBUG
            std::cout << "Writing dataArray 8-byte buffer into DataBucket...\n";
        #endif // ASYNCREADER_DEBUG
        bucket->AddData( dataArray );
    }
    else
    {
        std::cout << "ERROR: " << error.message() << "\n";
    }
    readInProcess = false;

}
