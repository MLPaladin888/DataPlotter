#ifndef CHARBUFFERTOSTRING_H_INCLUDED
#define CHARBUFFERTOSTRING_H_INCLUDED

#include <string>
#include "DataBucket/DataBucket.h"
#include "boost/circular_buffer.hpp"
#include "boost/lexical_cast.hpp"


std::string ToString(const boost::circular_buffer<unsigned char> &buffer);
std::string ToString(const DataBucket &buffer);

#endif // CHARBUFFERTOSTRING_H_INCLUDED
