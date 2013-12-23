#include "Gui/GuiElements/ConnectionBlock.h"

ConnectionBlock::ConnectionBlock(dp::Gui &gui, const std::string &name)
    : popupWindow(gui, (name + "-popupWindow") )  // construct popupWindow and add it to GUI pool
{
    popupWindow->load("widgets/White.conf");
    if(!popupWindow->loadWidgetsFromFile("Forms/ConnectionBlockPopup.txt"))
    {
        std::cout << "Some error loading widgets from file\n";
    }
    popupWindow->setSize(800,600);
    popupWindow->setTitle(name);
}




