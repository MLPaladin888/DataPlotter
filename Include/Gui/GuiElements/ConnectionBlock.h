#ifndef CONNECTIONBLOCK_H_INCLUDED
#define CONNECTIONBLOCK_H_INCLUDED

#include "Gui/GuiElements/GuiElement.h"

class ConnectionBlock : public GuiElement
{
public:
    ConnectionBlock(dp::Gui &gui, const std::string &name);

private:
    tgui::ChildWindow::Ptr popupWindow;
};



#endif // CONNECTIONBLOCK_H_INCLUDED
