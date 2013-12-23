#include "Gui/Gui.h"

dp::Gui::Gui(sf::RenderWindow &window) : tgui::Gui(window) {}

const tgui::ChildWindow::Ptr dp::Gui::CreateChildWindow(float width, float height, const std::string &name)
{
    tgui::ChildWindow::Ptr childWindow(*this, name);
    childWindow->load("Images/Widgets/White.conf");
    childWindow->setSize(width,height);
    childWindow->setTitle(name);
    return this->get(name);
}

void dp::Gui::bindToWidget(const std::string containerName, const std::string widgetName, std::function<void()> func, unsigned int trigger)
{
    tgui::Container::Ptr parent = this->get(containerName);
    if(!parent)
    {
        std::cout << "Unknown Parent/Container\n";
        return;
    }

    tgui::Widget::Ptr widget = parent->get(widgetName);
    if(!widget)
    {
        std::cout << "Unknown Widget\n";
        return;
    }
    widget->bindCallback(func, trigger);



}

tgui::Widget::Ptr dp::Gui::getFromChild(const std::string &child, const std::string &widget)
{
    tgui::Widget::Ptr childWidget = this->get(child);
    tgui::WidgetTypes childType = childWidget->getWidgetType();
    if( (childType != tgui::WidgetTypes::Type_ChildWindow) && (childType != tgui::WidgetTypes::Type_Panel) )
    {
        std::cout << "childType is not a container\n";
        return nullptr;
    }
    else
    {
        tgui::Container::Ptr childWidgetAsContainer = childWidget;
        tgui::Widget::Ptr returnWidget = childWidgetAsContainer->get(widget);
        return returnWidget;
    }
}
