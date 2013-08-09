#include "Threads/Threads.h"

void InitThreadGroup(boost::shared_ptr<boost::thread_group> workers, boost::shared_ptr<boost::asio::io_service> io_service)
{
    for(int i = 0; i < 4; i++)
    {
        workers->create_thread( boost::bind(&ThreadStartupFunc, io_service) );
    }
}

void ThreadStartupFunc(boost::shared_ptr<boost::asio::io_service> io_service)
{
    std::cout << "Thread " << boost::this_thread::get_id() << " started.\n";
    boost::system::error_code ec;
    while(1)
    {
        try
        {
            io_service->run(ec);
            if(ec)
            {
                std::cout << "[" << boost::this_thread::get_id() << "] Exception: " << ec << "\n";
            }
            break;
        }
        catch( std::exception const &ex )
        {
            std::cout << "[" << boost::this_thread::get_id() << "] Exception: " << ex.what() << "\n";
        }
    }
}
