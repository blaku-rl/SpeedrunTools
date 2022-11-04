#include "CanyonDribbleAutoSplitterComponent.h"

CanyonDribbleAutoSplitterComponent::CanyonDribbleAutoSplitterComponent(NetcodePlugin* plugin)
    : AutoSplitterComponent(plugin),
    startBox(Vector(-11774.86f, -189284.09f, 3947.01f), Vector(500.0f, 500.0f, 500.0f), Rotator(0, 0, 0))
{

}

void CanyonDribbleAutoSplitterComponent::onEnable()
{
}

void CanyonDribbleAutoSplitterComponent::update(const std::string& eventName, bool post, void* params)
{
    auto server = this->plugin->gameWrapper->GetGameEventAsServer();
    if (server.IsNull()) return;
    auto car = server.GetGameCar();
    if (car.IsNull()) return;
    int level = this->kismetModel.getIntValue("Level");
    bool modeChosen = this->kismetModel.getBoolValue("ModeChosen");
    if (eventName == "Function TAGame.Car_TA.SetVehicleInput" && post)
    {
        if (this->segment == 0 && startBox.contains(car.GetLocation()))
        {
            this->start();
        }
        else if (this->segment < 16 && this->segment != 0 && this->segment == level)
        {
            this->split();
        }
        else if (this->segment == 16 && !modeChosen)
        {
            this->split();
        }
    }
    if (eventName == "Function TAGame.GameEvent_Soccar_TA.Destroyed" && post)
    {
        this->reset();
    }
}

std::string CanyonDribbleAutoSplitterComponent::getStartDescription()
{
    return "The timer will start when you drive into the white start box.";
}

std::string CanyonDribbleAutoSplitterComponent::getSplitDescription()
{
    return "The timer will split when you reach the next level, and on completion of the map (16 splits total).";
}

std::string CanyonDribbleAutoSplitterComponent::getResetDescription()
{
    return "The timer will reset when you reset or leave the map.";
}

std::string CanyonDribbleAutoSplitterComponent::getDebugText()
{
    std::stringstream ss;
    ss << "Canyon Dribbling Challenge Auto Splitter (Debug)" << std::endl;
    return ss.str();
}
