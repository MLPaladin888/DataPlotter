#ifndef THREADS_H_INCLUDED
#define THREADS_H_INCLUDED

#include "boost\thread.hpp"
#define _WIN32_WINNT 0x0501
#include "boost\asio.hpp"

#define THREADS_DEBUG
void InitThreadGroup(boost::shared_ptr<boost::thread_group> workers, boost::shared_ptr<boost::asio::io_service> io_service);
void ThreadStartupFunc(boost::shared_ptr<boost::asio::io_service> io_service);



#endif // THREADS_H_INCLUDED
