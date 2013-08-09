#ifndef DATABUCKET_H_INCLUDED
#define DATABUCKET_H_INCLUDED

#include <vector>
#include "boost/circular_buffer.hpp"
#include "boost/thread/mutex.hpp"
#include "boost/foreach.hpp"

class DataBucket
{
private:
    size_t maxSize;
    boost::circular_buffer<char> data;
    boost::mutex mutex;


public:
    DataBucket(const size_t maxsize);
    void AddData(const char &newdata);
    void AddData(const std::vector<char> &newdata);
    const char ReadLatest();
};



#endif // DATABUCKET_H_INCLUDED
