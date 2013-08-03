#include <stdio.h>
#include "SerialModule/SerialMain.h"
#include "boost/thread.hpp"
#include "boost/thread/mutex.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////
// To Do:
// Create Reader/Writer Objects
///////////////////////////////////////////////////////////////////////////////////////////////////////

boost::mutex globalStreamLock;

void WorkerThreadFunc( boost::shared_ptr<boost::asio::io_service> io_service )
{
    globalStreamLock.lock();
    std::cout << boost::this_thread::get_id() << " calling io_service->run\n";
    globalStreamLock.unlock();
    io_service->run();
}

;void TestHandler( boost::shared_ptr<boost::array<char, 8> > data)
{
    globalStreamLock.lock();
    std::cout << boost::this_thread::get_id() << " handling TestHandler.\n";

    std::cout << "Data Received: ";
    for(unsigned int i = 0; i < data->size(); i++)
    {
        std::cout << (int)(*data)[i] << " ";
    }
    globalStreamLock.unlock();
}


int main(int argc, char **argv)
{
    boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service(new boost::asio::io_service);     // shared pointer because Connection (and later) objects access to it
    boost::shared_ptr<boost::asio::io_service::work> io_work( new boost::asio::io_service::work(*shared_ptr_io_service) );
    boost::thread_group worker_threads;
    for(int i = 0; i < 4; ++i)
    {
        worker_threads.create_thread( boost::bind( &WorkerThreadFunc, shared_ptr_io_service ) );
    }

    SerialDeviceEnumeration Com8Enum("Com8", 115200);                          // Define the device to connect to
    SerialConnection serialConnection1(shared_ptr_io_service, Com8Enum);       // Create the connection object
    serialConnection1.Connect();                                               // Connect!


    boost::shared_ptr< boost::array<char, 8> > data(new boost::array<char,8>);
    boost::asio::async_read(serialConnection1.port, boost::asio::buffer(*data), boost::bind(TestHandler, data) );


    std::cin.get();
    serialConnection1.Disconnect();
    shared_ptr_io_service->stop();
    worker_threads.join_all();
}
