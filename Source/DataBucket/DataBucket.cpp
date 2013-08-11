#include "DataBucket/DataBucket.h"

DataBucket::DataBucket(const size_t capacity) : capacity(capacity), data(capacity) {}

const size_t DataBucket::Capacity() const
{   // Return maximum number of elements
    return data.capacity();
}

const size_t DataBucket::Size() const
{   // Return number of elements currently stored
    return data.size();
}

void DataBucket::SetCapacity(const size_t capacity)
{   // Set maximum number of elements
    this->capacity = capacity;
    try
    {
        data.set_capacity(capacity);
    }
    catch(const std::exception &ex)
    {
        std::cout << ex.what() << "\n";
    }
}

void DataBucket::AddData(const elementType &newdata)
{
    mutex.lock();
    data.push_back(newdata);
    mutex.unlock();
}

void DataBucket::AddData(const std::vector<elementType> &newdata)
{
    mutex.lock();

    std::cout << " ";
    BOOST_FOREACH(size_t i, newdata)
    {
        data.push_back(newdata[i-1]);
        std::cout << i << ": ";
        std::cout << (unsigned int)newdata[i-1] << "\n";
    }
    std::cout << "\n";
    mutex.unlock();
}

const elementType DataBucket::ReadLatest()
{
    char retrievedData;
    mutex.lock();
    retrievedData = data.back();
    mutex.unlock();
    return retrievedData;
}

const bufferType& DataBucket::Get() const
{
    return data;
}
