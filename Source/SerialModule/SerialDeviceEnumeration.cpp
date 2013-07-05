#include "SerialModule/SerialDeviceEnumeration.h"

SerialDeviceEnumeration::SerialDeviceEnumeration(const std::string &devicename, const unsigned int baudrate)
/////// Defaults to 8bit DataSize, FlowControl: None, Parity: None, StopBits: One ///////////
    : name(devicename), baud(baudrate)
{
    dataSize = 8;
    flowType = boost::asio::serial_port_base::flow_control::none;
    parityType = boost::asio::serial_port_base::parity::none;
    stopBitsType = boost::asio::serial_port_base::stop_bits::one;
}


SerialDeviceEnumeration::SerialDeviceEnumeration(const std::string &devicename, const unsigned int baudrate, const unsigned int datasize,
                                                   const flow flowtype, const parity paritytype, const stopBits stopbitstype)
    : name(devicename),
    baud(baudrate),
    dataSize(datasize),
    flowType(flowtype),
    parityType(paritytype),
    stopBitsType(stopbitstype)
{
}
