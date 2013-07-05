#include <stdio.h>
#include "SerialModule/SerialMain.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////
// To Do:
// Resolve DeviceEnumeration inheretence confusion.  Should Connection.Connect() really be virtual?
///////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service(new boost::asio::io_service);     // shared pointer because Connection (and later) objects access to it

    SerialDeviceEnumeration Com3Enum("Com3", 115200);                          // Define the device to connect to
    SerialConnection serialConnection1(shared_ptr_io_service, Com3Enum);       // Create the connection object
    serialConnection1.Connect();                                               // Connect!


    serialConnection1.Disconnect();
}
