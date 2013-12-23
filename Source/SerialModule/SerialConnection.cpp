#include "SerialModule/SerialConnection.h"

SerialConnection::SerialConnection(boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service, const SerialDeviceEnumeration &SerialDevEnum)
    : Connection(shared_ptr_io_service),
        port(new boost::asio::serial_port(*shared_ptr_io_service)),
        deviceEnum(SerialDevEnum)
{}

SerialConnection::~SerialConnection() {}

error_code SerialConnection::Connect()
{
    boost::system::error_code ec;
    port->open(deviceEnum.name, ec);
    if(!ec)
    {
        port->set_option( boost::asio::serial_port_base::baud_rate(deviceEnum.baud) );
        port->set_option( boost::asio::serial_port_base::character_size(deviceEnum.dataSize) );
        port->set_option( boost::asio::serial_port_base::flow_control(deviceEnum.flowType) );
        port->set_option( boost::asio::serial_port_base::parity(deviceEnum.parityType) );
        port->set_option( boost::asio::serial_port_base::stop_bits(deviceEnum.stopBitsType) );
    }
    else
    {
        std::cout << "Error opening port \"" << deviceEnum.name << "\".\n";
        std::cout << "Error: " << ec.message() << ".\n";
        return ec;
    }
    #ifdef SERIALCONNECTION_DEBUG
        std::cout << "Port opened.\n";
    #endif // SERIALCONNECTION_DEBUG
    return make_error_code(boost::system::errc::success);
}

error_code SerialConnection::Disconnect()
{
    boost::system::error_code ec;
    port->close(ec);
    if(ec)
    {
        std::cout << "Error closing port \"" << deviceEnum.name << "\".\n";
        std::cout << "Error: " << ec.message() << ".\n";
    }
    #ifdef SERIALCONNECTION_DEBUG
        std::cout << "Port closed.\n";
    #endif // SERIALCONNECTION_DEBUG
    return make_error_code(boost::system::errc::success);
}

error_code SerialConnection::AsyncRead()
{
    reader->AsyncRead(port, rawData);
    return make_error_code(boost::system::errc::success);
}




