#include "EversaxDribbleChallengeAutoSplitterComponent.h"

EversaxDribbleChallengeAutoSplitterComponent::EversaxDribbleChallengeAutoSplitterComponent(NetcodePlugin* plugin)
    : AutoSplitterComponent(plugin),
    resetRoomTrigger(Vector(-8982.06f, -20267.86f, 17.66f), Vector(500.0f, 500.0f, 500.0f), Rotator(0, 0, 0)),
    finalTrigger(Vector(-7522.784180f, 85834.585938f, 44318.929688f), Vector(1477.80017f, 175.39833f, 984.351868f), Rotator(0,0,0))
{

}

void EversaxDribbleChallengeAutoSplitterComponent::onEnable()
{
}

void EversaxDribbleChallengeAutoSplitterComponent::update(const std::string& eventName, bool post, void* params)
{
    auto server = this->plugin->gameWrapper->GetGameEventAsServer();
    if (server.IsNull()) return;
    auto ball = server.GetBall();
    if (ball.IsNull()) return;
    auto car = server.GetGameCar();
    if (car.IsNull()) return;
    int level = this->kismetModel.getIntValue("Level");
    bool skipped = this->kismetModel.getBoolValue("Skipped");
    if (eventName == "Function TAGame.Car_TA.SetVehicleInput" && post)
    {
        if (skipped)
        {
            if (this->segment > 0) this->reset();
            return;
        }

        if (this->resetRoomTrigger.contains(car.GetLocation()) && this->segment > 0)
        {
            this->reset();
        }

        if (this->segment == 0 && level == 1)
        {
            this->start();
        }
        else if (this->segment < 20 && this->segment == level - 1)
        {
            this->split();
        }
        else if (this->segment == 20 && level == 0 && this->finalTrigger.contains(ball.GetLocation()))
        {
            this->split();;
        }
    }
    if (eventName == "Function TAGame.GameEvent_TA.PlayerResetTraining" && post)
    {
        if (this->segment > 0 && level == 0)
        {
            this->reset();
        }
    }
    if (eventName == "Function TAGame.GameEvent_Soccar_TA.Destroyed" && post)
    {
        this->reset();
    }
}

std::string EversaxDribbleChallengeAutoSplitterComponent::getStartDescription()
{
    return "The timer will start when you drive into the white start block.";
}

std::string EversaxDribbleChallengeAutoSplitterComponent::getSplitDescription()
{
    return "The timer will split when you reach the next level, and on completion of the map (20 splits total).";
}

std::string EversaxDribbleChallengeAutoSplitterComponent::getResetDescription()
{
    return "The timer will reset when you use the in game reset feature, or leave the map.";
}

std::string EversaxDribbleChallengeAutoSplitterComponent::getDebugText()
{
    std::stringstream ss;
    ss << "Eversax Dribble Challenge Auto Splitter (Debug)" << std::endl;
    return ss.str();
}
