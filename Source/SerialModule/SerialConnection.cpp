#include "SerialModule/SerialConnection.h"

SerialConnection::SerialConnection(boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service) : Connection(shared_ptr_io_service)
{

}

SerialConnection::~SerialConnection()
{

}

error_code SerialConnection::Connect(const DeviceEnumeration &SerialDevEnum)
{
    /*if(port->is_open())
    {
        port->set_option( boost::asio::serial_port_base::baud_rate(baudRate) );
        port->set_option( boost::asio::serial_port_base::character_size(charSize) );
        port->set_option( boost::asio::serial_port_base::flow_control(flowType) );
        port->set_option( boost::asio::serial_port_base::parity(parityType) );
        port->set_option( boost::asio::serial_port_base::stop_bits(stopBitsType) );
    }
    else
    {
        std::cout << "Cannot set options with closed port.\n";
    }*/
    return make_error_code(boost::system::errc::success);
}

error_code SerialConnection::Disconnect()
{

    return make_error_code(boost::system::errc::success);
}
