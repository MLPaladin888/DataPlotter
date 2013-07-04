#ifndef SERIALDEVICEENUMERATION_H_INCLUDED
#define SERIALDEVICEENUMERATION_H_INCLUDED

#define _WIN32_WINNT 0x0501
#include "boost\asio\serial_port.hpp"
#include "Connection\DeviceEnumeration.h"

class SerialDeviceEnumeration : public DeviceEnumeration
//////////////////////////////////////////////////////////////////////////
////// Carries device name and port options for serial ports /////////////
//////////////////////////////////////////////////////////////////////////
{
typedef boost::asio::serial_port_base::flow_control::type flow_Type;
typedef boost::asio::serial_port_base::parity::type parity_Type;
typedef boost::asio::serial_port_base::stop_bits::type stopBits_Type;

public:
    SerialDeviceEnumeration(std::string &devicename, const unsigned int buadrate, const unsigned int datasize,
                                const flow_Type flowtype, const parity_Type paritytype, const stopBits_Type stopbitstype);

    std::string name;
    unsigned int baud;
    unsigned int dataSize;
    flow_Type flowType;
    parity_Type parityType;
    stopBits_Type stopBitsType;
};



#endif // SERIALDEVICEENUMERATION_H_INCLUDED
