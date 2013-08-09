#include "DataBucket/DataBucket.h"

DataBucket::DataBucket(const size_t maxsize) : maxSize(maxsize), data(maxsize) {}

void DataBucket::AddData(const char &newdata)
{
    mutex.lock();
    data.push_back(newdata);
    mutex.unlock();
}

void DataBucket::AddData(const std::vector<char> &newdata)
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

const char DataBucket::ReadLatest()
{
    char retrievedData;
    mutex.lock();
    retrievedData = data.back();
    mutex.unlock();
    return retrievedData;
}
