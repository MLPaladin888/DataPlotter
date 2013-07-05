#ifndef SERIALDEVICEENUMERATION_H_INCLUDED
#define SERIALDEVICEENUMERATION_H_INCLUDED

#define _WIN32_WINNT 0x0501
#include "boost\asio\serial_port.hpp"

class SerialDeviceEnumeration
//////////////////////////////////////////////////////////////////////////
////// Carries device name and port options for serial ports /////////////
//////////////////////////////////////////////////////////////////////////
{
typedef boost::asio::serial_port_base::flow_control::type flow;
typedef boost::asio::serial_port_base::parity::type parity;
typedef boost::asio::serial_port_base::stop_bits::type stopBits;

public:
    SerialDeviceEnumeration(const std::string &devicename, const unsigned int baudrate);
    SerialDeviceEnumeration(const std::string &devicename, const unsigned int buadrate, const unsigned int datasize,
                                const flow flowtype, const parity paritytype, const stopBits stopbitstype);

    std::string name;
    unsigned int baud;
    unsigned int dataSize;
    flow flowType;
    parity parityType;
    stopBits stopBitsType;
};



#endif // SERIALDEVICEENUMERATION_H_INCLUDED
