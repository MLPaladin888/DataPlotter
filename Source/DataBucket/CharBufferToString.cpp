#include "DataBucket/CharBufferToString.h"

std::string ToString(const boost::circular_buffer<unsigned char> &buffer)
{
    std::string returnString;
    for(const unsigned char &i : buffer)    /////////// CHECK THIS LINE //////////
    {
        returnString.append( boost::lexical_cast<std::string>( (unsigned int)i ) );
    }
    return returnString;
}

std::string ToString(const DataBucket& buffer)
{
    return ToString(buffer.Get());
}
