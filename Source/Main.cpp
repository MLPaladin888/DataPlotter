#include <stdio.h>
#include "Environment/Environment.h"
#include "Gui/GuiElements/ConnectionBlock.h"



int main(int argc, char **argv)
{
    Environment environment( sf::VideoMode(1024,768) );

    ConnectionBlock aConnectionBlock(environment.gui, "Connection Block A");
    std::function<std::vector<std::string>(void)> PtrScanPortsFunc;
    PtrScanPortsFunc = std::bind(&Environment::ScanPorts, &environment);
    environment.gui.bindToWidget("Connection Block A-popupWindow", "ButtonScanPorts", PtrScanPortsFunc, tgui::Button::LeftMouseClicked);

    tgui::ComboBox::Ptr comboPorts = environment.gui.getFromChild("Connection Block A-popupWindow", "ComboPort");
    comboPorts->addItem("Doot");


    while(environment.window->isOpen())
    {
        environment.HandleEvents();
        environment.PollCallbacks();

        environment.window->clear(sf::Color::Cyan);
        environment.gui.draw();
        environment.window->display();
    }


    return 0;
}
