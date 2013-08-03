#ifndef SERIALCONNECTION_H_INCLUDED
#define SERIALCONNECTION_H_INCLUDED

#include "Connection\Connection.h"
#include "SerialModule\SerialDeviceEnumeration.h"
#include "boost\asio\serial_port.hpp"

typedef boost::system::error_code error_code;

class SerialConnection : public Connection
////////////////////////////////////////////////////////////////////////////////////////
////////// Specific Type of Connection: For Serial Ports                          //////
////////// Handles Connect/Disconnect.  Setting port options from deviceEnum type //////
////////////////////////////////////////////////////////////////////////////////////////
{
public:
    SerialConnection(boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service, const SerialDeviceEnumeration &SerialDevEnum);
    ~SerialConnection();
    error_code Connect();
    error_code Disconnect();

public: // make private again later
    boost::asio::serial_port port;
    SerialDeviceEnumeration deviceEnum;
};



#endif // SERIALCONNECTION_H_INCLUDED
