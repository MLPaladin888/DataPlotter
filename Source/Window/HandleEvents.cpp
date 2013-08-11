#include "Window/HandleEvents.h"

void HandleEvents(boost::shared_ptr<sf::RenderWindow> window)
{
    sf::Event SFMLEvent;
    while(window->pollEvent(SFMLEvent))\
    {
        if(SFMLEvent.type == sf::Event::Closed)
        {
            window->close();
        }
    }
}
