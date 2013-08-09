#include <stdio.h>
#include "SerialModule/SerialMain.h"
#include "Readers/AsyncReader.h"
#include "Threads/Threads.h"
#include "SFML/Graphics.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////
// To Do:
// Create Reader/Writer Objects
///////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Data Plotter", sf::Style::Default);

    boost::shared_ptr<boost::thread_group> worker_threads(new boost::thread_group);
    boost::shared_ptr<boost::asio::io_service> shared_ptr_io_service(new boost::asio::io_service);     // shared pointer because Connection (and later) objects access to it
    boost::shared_ptr<boost::asio::io_service::work> io_work( new boost::asio::io_service::work(*shared_ptr_io_service));
    InitThreadGroup(worker_threads, shared_ptr_io_service);

    boost::shared_ptr<DataBucket> bucketOfData(new DataBucket(128));
    boost::shared_ptr<AsyncReader> readerOne(new AsyncReader(shared_ptr_io_service, 8));

    sf::Font font;
    font.loadFromFile("Fonts/DejaVuSans.ttf");
    sf::Text text;
    text.setFont(font);
    text.setPosition(400,300);
    text.setString("Woot");

    SerialDeviceEnumeration Com8Enum("Com8", 115200);                          // Define the device to connect to
    SerialConnection serialConnection1(shared_ptr_io_service, Com8Enum);       // Create the connection object
    serialConnection1.Connect();                                               // Connect!

    while(window.isOpen())
    {
        sf::Event SFMLEvent;
        while(window.pollEvent(SFMLEvent))\
        {
            if(SFMLEvent.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();

        readerOne->AsyncRead(serialConnection1.port, bucketOfData);
    }

    serialConnection1.Disconnect();
    io_work.reset();
    shared_ptr_io_service->stop();
    worker_threads->join_all();
    return 0;
}
