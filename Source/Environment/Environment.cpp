#include "Environment/Environment.h"

Environment::Environment(sf::VideoMode videoMode)
    :   window( new sf::RenderWindow(videoMode, "DataPlotter", sf::Style::Default ) ),
        gui(*window),
        io_service( new boost::asio::io_service() ),
        io_work( new boost::asio::io_service::work(*io_service) ),
        worker_threads( new boost::thread_group() )
{
    InitThreadGroup(worker_threads, io_service);
    sf::Font font;
    font.loadFromFile("Fonts/DejaVuSans.ttf");
    gui.setGlobalFont(font);
}

Environment::~Environment()
{
    io_work.reset();
    io_service->stop();
    worker_threads->join_all();
}

const std::vector<std::string> Environment::ScanPorts() const
{
    std::vector<std::string> validNames;
    std::string portName;

    for(unsigned int i = 1; i < 17; i++)
    {
        portName = "Com";
        portName.append( boost::lexical_cast<std::string>(i));
        #ifdef SERIALCONNECTION_DEBUG
            std::cout << "Trying port name: " << portName << "...";
        #endif // SERIALCONNECTION_DEBUG
        SerialDeviceEnumeration Enum(portName, 9600);
        SerialConnection Connection(io_service, Enum);
        if( !Connection.Connect() )
        {
            #ifdef SERIALCONNECTION_DEBUG
                std::cout << "valid.\n";
            #endif // SERIALCONNECTION_DEBUG
            validNames.push_back(portName);
        }
        else
        {
            #ifdef SERIALCONNECTION_DEBUG
                std::cout << "invalid.\n";
            #endif // SERIALCONNECTION_DEBUG
        }
        Connection.Disconnect();
    }
    return validNames;
}

void Environment::HandleEvents()
{
    sf::Event SFMLEvent;
    while(window->pollEvent(SFMLEvent))
    {
        if(SFMLEvent.type == sf::Event::Closed)
        {
            window->close();
        }
        gui.handleEvent(SFMLEvent);
    }
}

void Environment::PollCallbacks()
{
    tgui::Callback callback;
    while(gui.pollCallback(callback))
    {
        if(callback.id == 1)
        {
            tgui::Widget::Ptr widgetPtr = gui.getFromChild("Serial Connection Options", "PortsCombo");

            if(widgetPtr->getWidgetType() == tgui::WidgetTypes::Type_ComboBox)
            {
                tgui::ComboBox::Ptr portsComboPtr = widgetPtr;
                portsComboPtr->removeAllItems();
                std::vector<std::string> validPorts = ScanPorts();
                for(std::string &validportitem : validPorts)
                {
                    portsComboPtr->addItem(validportitem);
                }
            }
        }
    }
}




