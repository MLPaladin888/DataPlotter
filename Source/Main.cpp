#include <stdio.h>
#include "SerialModule/SerialMain.h"

int main(int argc, char **argv)
{
    SerialPort myPort("COM3");
    myPort.Open();
    myPort.SetOptions(115200, 8, boost::asio::serial_port_base::flow_control::none, boost::asio::serial_port_base::parity::none, boost::asio::serial_port_base::stop_bits::one);

    myPort.Close();
}
