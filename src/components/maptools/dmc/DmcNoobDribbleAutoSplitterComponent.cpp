#include "DmcNoobDribbleAutoSplitterComponent.h"

DmcNoobDribbleAutoSplitterComponent::DmcNoobDribbleAutoSplitterComponent(NetcodePlugin* plugin)
    : AutoSplitterComponent(plugin),
    casual(),
    level()
{
}

void DmcNoobDribbleAutoSplitterComponent::onEnable()
{
    this->casual = this->kismetModel.getBoolValue("Casual");
    this->level = this->kismetModel.getIntValue("Level");
}

void DmcNoobDribbleAutoSplitterComponent::update(const std::string& eventName, bool post, void* params)
{
    if (eventName == "Function TAGame.Car_TA.SetVehicleInput" && post)
    {
        bool previousCasual = this->casual;
        this->casual = this->kismetModel.getBoolValue("Casual");

        int previousLevel = this->level;
        this->level = this->kismetModel.getIntValue("Level");

        bool finished = this->kismetModel.getBoolValue("gameover");

        if (this->segment == 0)
        {
            if (!this->casual && previousCasual)
            {
                this->start();
            }
        }
        else if (1 <= this->segment && this->segment <= 25)
        {
            if (this->level == (previousLevel + 1) && this->level == (this->segment + 1))
            {
                this->split();
            }
        }
        else if (this->segment == 26 && finished)
        {
            this->split();
        }
    }
    if (eventName == "Function TAGame.GameEvent_Soccar_TA.Destroyed" && post)
    {
        this->reset();
    }
}

std::string DmcNoobDribbleAutoSplitterComponent::getStartDescription()
{
    return "The timer will start when map timer starts.";
}

std::string DmcNoobDribbleAutoSplitterComponent::getSplitDescription()
{
    return "The timer will split after completing each level (26 splits in total).";
}

std::string DmcNoobDribbleAutoSplitterComponent::getResetDescription()
{
    return "The timer will reset after leaving the map.";
}

std::string DmcNoobDribbleAutoSplitterComponent::getDebugText()
{
    std::stringstream ss;
    ss << "Dmc Noob Dribble Auto Splitter (Debug)" << std::endl;
    ss << "casual = " << this->casual << std::endl;
    ss << "level = " << this->level << std::endl;
    return ss.str();
}
