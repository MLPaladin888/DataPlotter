#include <stdio.h>
#include "SerialModule/SerialMain.h"
#include "Threads/Threads.h"
#include "Window/Window.h"
#include "DataBucket/CharBufferToString.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////
// To Do:
// Create Reader/Writer Objects
///////////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char **argv)
{
    boost::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(800,600), "Data Plotter", sf::Style::Default));

    boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service(new boost::asio::io_service);     // shared pointer because Connection (and later) objects access to it
    boost::shared_ptr<boost::asio::io_service::work> io_work( new boost::asio::io_service::work(*shared_ptr_io_service));
    boost::shared_ptr<boost::thread_group> worker_threads(new boost::thread_group);
    InitThreadGroup(worker_threads, shared_ptr_io_service);

    sf::Font font;
    font.loadFromFile("Fonts/DejaVuSans.ttf");
    sf::Text text;
    text.setFont(font);
    text.setPosition(25,25);
    text.setString("Woot");

    SerialDeviceEnumeration Com8Enum("Com8", 115200);                          // Define the device to connect to
    SerialConnection serialConnection1(shared_ptr_io_service, Com8Enum);       // Create the connection object
    serialConnection1.Connect();                                               // Connect!

    while(window->isOpen())
    {
        HandleEvents(window);

        serialConnection1.AsyncRead();
        window->clear(sf::Color::Black);
        text.setString( ToString(serialConnection1.GetData()) );
        window->draw(text);
        window->display();
    }

    serialConnection1.Disconnect();
    io_work.reset();
    shared_ptr_io_service->stop();
    worker_threads->join_all();
    return 0;
}
