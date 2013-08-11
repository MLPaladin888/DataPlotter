#include "Connection/Connection.h"

Connection::Connection(boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service)
    : isConnected(false),
    io_service(shared_ptr_io_service),
    rawData(new DataBucket(128)),
    reader(new AsyncReader(shared_ptr_io_service, 8))

{}

Connection::~Connection() {}

const size_t Connection::BufferSize() const
{   // Returns number of elements stored in the buffer
    return rawData->Size();
}

const size_t Connection::BufferCapacity() const
{   // Returns number of elements that would fit in the buffer
    return rawData->Capacity();
}

void Connection::SetBufferCapacity(const size_t capacity)
{   // Set number of elements that would fit in the buffer
    rawData->SetCapacity(capacity);
}

const DataBucket& Connection::GetData() const
{
    return *rawData;
}
