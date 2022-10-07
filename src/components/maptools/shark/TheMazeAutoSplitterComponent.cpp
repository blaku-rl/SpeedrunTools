#include "TheMazeAutoSplitterComponent.h"

TheMazeAutoSplitterComponent::TheMazeAutoSplitterComponent(NetcodePlugin* plugin)
    : AutoSplitterComponent(plugin)
{
}

void TheMazeAutoSplitterComponent::onEnable()
{

}

void TheMazeAutoSplitterComponent::update(const std::string& eventName, bool post, void* params)
{
    if (eventName == "Function TAGame.Car_TA.SetVehicleInput" && post)
    {
        auto car = this->plugin->gameWrapper->GetLocalCar();
        if (!car) return;
        auto& loc = car.GetLocation();
        
        if (-5375.0f < loc.X && loc.X < -4715.0f && loc.Y < 11840.0f && this->segment == 0)
        {
            this->start();
        }
        if (6425.0f < loc.X && loc.X < 7075.0f && 11840.0f < loc.Y && this->segment == 1)
        {
            this->split();
        }
    }
    if (eventName == "Function TAGame.GameEvent_Soccar_TA.Destroyed" && post)
    {
        this->reset();
    }
    if (eventName == "Function TAGame.GameEvent_TA.PlayerResetTraining" && post)
    {
        this->reset();
    }
}

std::string TheMazeAutoSplitterComponent::getStartDescription()
{
    return "The timer will start when you leave the first room.";
}

std::string TheMazeAutoSplitterComponent::getSplitDescription()
{
    return "The timer will end once you enter the final room box.";
}

std::string TheMazeAutoSplitterComponent::getResetDescription()
{
    return "The timer will reset when pressing reset or leaving the map.";
}

std::string TheMazeAutoSplitterComponent::getDebugText()
{
    std::stringstream ss;
    ss << "The Maze Auto Splitter (Debug)" << std::endl;
    return ss.str();
}
