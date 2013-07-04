#include <stdio.h>
#include "SerialModule/SerialMain.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////
// To Do:
// Resolve DeviceEnumeration inheretence confusion.  Should Connection.Connect() really be virtual?
///////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    boost::shared_ptr<boost::asio::io_service> io_service(new boost::asio::io_service);     // shared pointer because Connection (and later) objects access to it
    SerialConnection serialConnection1(io_service);




}
