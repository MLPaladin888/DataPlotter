#include "SerialModule/SerialDeviceEnumeration.h"

SerialDeviceEnumeration::SerialDeviceEnumeration(std::string &devicename, const unsigned int baudrate, const unsigned int datasize,
                                                   const flow_Type flowtype, const parity_Type paritytype, const stopBits_Type stopbitstype)
    : name(devicename),
    baud(baudrate),
    dataSize(datasize),
    flowType(flowtype),
    parityType(paritytype),
    stopBitsType(stopbitstype)
{
}
