#ifndef ENVIRONMENT_H_INCLUDED
#define ENVIRONMENT_H_INCLUDED

#include "Threads/Threads.h"
#include "Window/Window.h"
#include "SerialModule/SerialConnection.h"
#include "Gui/Gui.h"


class Environment
{
public:
    Environment(sf::VideoMode videoMode);
    ~Environment();

public:
    boost::shared_ptr<sf::RenderWindow> window;
    dp::Gui gui;

private:
    boost::shared_ptr<boost::asio::io_service> io_service;
    boost::shared_ptr<boost::asio::io_service::work> io_work;
    boost::shared_ptr<boost::thread_group> worker_threads;


public:
    const std::vector<std::string> ScanPorts() const;
    void HandleEvents();
    void PollCallbacks();


};



#endif // ENVIRONMENT_H_INCLUDED
