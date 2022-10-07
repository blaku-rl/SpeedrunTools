#include "DaciaSpringElectricChallengeAutoSplitterComponent.h"

DaciaSpringElectricChallengeAutoSplitterComponent::DaciaSpringElectricChallengeAutoSplitterComponent(NetcodePlugin* plugin)
    : AutoSplitterComponent(plugin),
    completed(false)
{

}

void DaciaSpringElectricChallengeAutoSplitterComponent::onEnable()
{
    this->completed = false;
}

void DaciaSpringElectricChallengeAutoSplitterComponent::update(const std::string& eventName, bool post, void* params)
{
    int level = this->kismetModel.getIntValue("Level");
    if (eventName == "Function TAGame.Car_TA.SetVehicleInput" && post)
    {
        int boostCount = this->kismetModel.getIntValue("BoostCount");
        if (this->segment == 0 && level == 1)
        {
            this->start();
        }
        else if (this->segment < 20 && this->segment == level - 1)
        {
            this->split();
        }
        else if (this->segment == 20 && level == 0 && boostCount == 15)
        {
            this->split();
            this->completed = true;
        }
        else if (this->segment > 0 && level == 0 && !this->completed)
        {
            this->reset();
        }
    }
    if (eventName == "Function TAGame.GameEvent_TA.PlayerResetTraining" && post)
    {
        if (this->segment > 0 && level == 0) 
        {
            this->reset();
            this->completed = false;
        }
    }
    if (eventName == "Function TAGame.GameEvent_Soccar_TA.Destroyed" && post)
    {
        this->reset();
        this->completed = false;
    }
}

std::string DaciaSpringElectricChallengeAutoSplitterComponent::getStartDescription()
{
    return "The timer will start when you select a difficulty.";
}

std::string DaciaSpringElectricChallengeAutoSplitterComponent::getSplitDescription()
{
    return "The timer will split when you reach the next level, and on completion of the map (20 splits total).";
}

std::string DaciaSpringElectricChallengeAutoSplitterComponent::getResetDescription()
{
    return "The timer will reset when you use the in game reset feature, or leave the map.";
}

std::string DaciaSpringElectricChallengeAutoSplitterComponent::getDebugText()
{
    std::stringstream ss;
    ss << "Dacia Spring Electric Challenge Auto Splitter (Debug)" << std::endl;
    ss << "completed = " << this->completed << std::endl;
    return ss.str();
}
