#include "KaizoEgyptianTombAutoSplitterComponent.h"

KaizoEgyptianTombAutoSplitterComponent::KaizoEgyptianTombAutoSplitterComponent(NetcodePlugin* plugin)
    : AutoSplitterComponent(plugin)
{
}

void KaizoEgyptianTombAutoSplitterComponent::onEnable()
{

}

void KaizoEgyptianTombAutoSplitterComponent::update(const std::string& eventName, bool post, void* params)
{
    if (eventName == "Function TAGame.Car_TA.SetVehicleInput" && post)
    {
        auto car = this->plugin->gameWrapper->GetLocalCar();
        if (!car) return;
        bool cp1 = this->kismetModel.getBoolValue("CP1");
        bool cp2 = this->kismetModel.getBoolValue("CP2");
        bool cp3 = this->kismetModel.getBoolValue("CP3");
        bool cp4 = this->kismetModel.getBoolValue("CP4");
        bool cp5 = this->kismetModel.getBoolValue("CP5");

        if (this->segment == 0 && car.GetLocation().Y >= 5460.0f)
        {
            this->start();
        }
        else if (this->segment == 1 && cp1)
        {
            this->split();
        }
        else if (this->segment == 2 && cp2)
        {
            this->split();
        }
        else if (this->segment == 3 && cp3)
        {
            this->split();
        }
        else if (this->segment == 4 && cp4)
        {
            this->split();
        }
        else if (this->segment == 5 && cp5)
        {
            this->split();
        }
        else if (this->segment == 6 && car.GetLocation().Z > 4016.0f)
        {
            this->split();
        }
    }
    if (eventName == "Function TAGame.GameEvent_Soccar_TA.Destroyed" && post)
    {
        this->reset();
    }
}

std::string KaizoEgyptianTombAutoSplitterComponent::getStartDescription()
{
    return "The timer will start when you cross the barrier at the start.";
}

std::string KaizoEgyptianTombAutoSplitterComponent::getSplitDescription()
{
    return "The timer will split after each checkpoint and once you reach the end (6 splits in total).";
}

std::string KaizoEgyptianTombAutoSplitterComponent::getResetDescription()
{
    return "The timer will reset after leaving the map.";
}

std::string KaizoEgyptianTombAutoSplitterComponent::getDebugText()
{
    std::stringstream ss;
    ss << "Kaizo Leth's Egyptian Tomb Auto Splitter (Debug)" << std::endl;
    return ss.str();
}
