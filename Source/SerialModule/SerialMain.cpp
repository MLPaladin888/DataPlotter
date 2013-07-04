#include "SerialModule/SerialMain.h"

/*SerialPort::SerialPort(const std::string& device)   : port(new boost::asio::serial_port(this->io_service)), deviceName(device)
{
}

SerialPort::~SerialPort()
{
}

void SerialPort::SetOptions(const unsigned int baudRate, const unsigned int charSize, const boost::asio::serial_port_base::flow_control::type flowType,
                            const boost::asio::serial_port_base::parity::type parityType, const boost::asio::serial_port_base::stop_bits::type stopBitsType)
{
    if(port->is_open())
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
    }
}

void SerialPort::Open()
{
    if(!port->is_open())
    {
        boost::system::error_code ec;
        port->open(deviceName, ec);
        if(ec)
        {
            std::cout << ec.value();
        }
    }
    else
    {
        std::cout << "Port already open.\n";
    }
}

void SerialPort::Close()
{
    boost::system::error_code ec;
    port->close(ec);
    if(ec)
    {
        std::cout << ec.value();
    }
}

void SerialPort::RunThread()
{
    boost::thread t(boost::bind(&boost::asio::io_service::run, &this->io_service));
}
*/












