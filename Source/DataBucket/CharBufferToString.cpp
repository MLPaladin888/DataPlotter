#include "DataBucket/CharBufferToString.h"

std::string ToString(const boost::circular_buffer<unsigned char> &buffer)
{
    std::string returnString;
    BOOST_FOREACH(size_t i, buffer)
    {
        returnString.append( boost::lexical_cast<std::string>( (unsigned int)buffer[i-1] ) );
    }
    return returnString;
}

std::string ToString(const DataBucket& buffer)
{
    return ToString(buffer.Get());
}
