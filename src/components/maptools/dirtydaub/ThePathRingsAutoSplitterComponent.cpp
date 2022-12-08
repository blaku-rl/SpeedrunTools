#include "ThePathRingsAutoSplitterComponent.h"

ThePathRingsAutoSplitterComponent::ThePathRingsAutoSplitterComponent(NetcodePlugin* plugin)
    : AutoSplitterComponent(plugin),
    level()
{
}

void ThePathRingsAutoSplitterComponent::onEnable()
{
    this->level = this->kismetModel.getIntValue("Level");
}

void ThePathRingsAutoSplitterComponent::update(const std::string& eventName, bool post, void* params)
{
    this->level = this->kismetModel.getIntValue("Level");
    int rings = this->kismetModel.getIntValue("RingsPassed");

    if (eventName == "Function TAGame.Car_TA.SetVehicleInput" && post)
    {
        if (this->segment == 0 && this->level == 201 && rings == 1) 
        {
            this->start();
        }
        else if (this->segment > 0 && this->level == this->segment + 201)
        {
            this->split();
        }
    }
    if (eventName == "Function TAGame.GameEvent_Soccar_TA.Destroyed" && post)
    {
        this->reset();
    }
}

std::string ThePathRingsAutoSplitterComponent::getStartDescription()
{
    return "The timer will start when you collect the first ring.";
}

std::string ThePathRingsAutoSplitterComponent::getSplitDescription()
{
    return "The timer will split once you complete each level (10 splits in total).";
}

std::string ThePathRingsAutoSplitterComponent::getResetDescription()
{
    return "The timer will reset after leaving the map.";
}

std::string ThePathRingsAutoSplitterComponent::getDebugText()
{
    std::stringstream ss;
    ss << "The Path Rings Auto Splitter (Debug)" << std::endl;
    ss << "Level " << this->level << std::endl;
    return ss.str();
}
