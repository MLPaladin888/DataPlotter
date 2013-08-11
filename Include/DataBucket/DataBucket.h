#ifndef DATABUCKET_H_INCLUDED
#define DATABUCKET_H_INCLUDED

#include <vector>
#include "boost/circular_buffer.hpp"
#include "boost/thread/mutex.hpp"
#include "boost/foreach.hpp"

typedef unsigned char elementType;
typedef boost::circular_buffer<elementType> bufferType;

class DataBucket
{
private:
    size_t capacity;
    bufferType data;
    boost::mutex mutex;

public:
    DataBucket(const size_t capacity);
    const size_t Capacity() const;
    const size_t Size() const;
    void SetCapacity(const size_t capacity);
    void AddData(const elementType &newdata);
    void AddData(const std::vector<elementType> &newdata);
    const elementType ReadLatest();
    const bufferType& Get() const;
};



#endif // DATABUCKET_H_INCLUDED
