#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include "TGUI/TGUI.hpp"
#include "Gui/PollCallbacks.h"

namespace dp
{
    class Gui : public tgui::Gui
    {
    public:
        Gui(sf::RenderWindow &window);

        const tgui::ChildWindow::Ptr CreateChildWindow(float width, float height, const std::string &name);
        void PollCallbacks();
        void bindToWidget(const std::string containerName, const std::string widgetName, std::function<void()> func, unsigned int trigger);
        tgui::Widget::Ptr getFromChild(const std::string &child, const std::string &widget);
    };
}

#endif // GUI_H_INCLUDED
