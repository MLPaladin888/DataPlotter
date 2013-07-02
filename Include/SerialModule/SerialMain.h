#ifndef SERIALMAIN_H_INCLUDED
#define SERIALMAIN_H_INCLUDED

#define _WIN32_WINNT 0x0501             // Wish I knew why this is necessary.
#include "boost\asio.hpp"
#include "boost\asio\serial_port.hpp"
#include "boost\bind.hpp"
#include "boost\thread.hpp" // Cant get this shit to link!!!!!!


class SerialPort
{
    public:
        SerialPort(const std::string& device);
        ~SerialPort();
        void Open();
        void Close();
        void RunThread();
        void SetOptions(const unsigned int baudRate, const unsigned int charSize, const boost::asio::serial_port_base::flow_control::type flowType,
                        const boost::asio::serial_port_base::parity::type parityType, const boost::asio::serial_port_base::stop_bits::type stopBitsType);

    private:
        boost::asio::io_service io_service;
        boost::shared_ptr<boost::asio::serial_port> port;
        std::string deviceName;
};



#endif // SERIALMAIN_H_INCLUDED
