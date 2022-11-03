#include "EversaxDribbleChallengeMapToolsComponent.h"
#include "EversaxDribbleChallengeAutoSplitterComponent.h"

EversaxDribbleChallengeMapToolsComponent::EversaxDribbleChallengeMapToolsComponent(NetcodePlugin* plugin)
    : MapToolsComponent(plugin, std::make_shared<EversaxDribbleChallengeAutoSplitterComponent>(plugin),
        "Eversax Dribble Challenge", "eversaxdribble", 0)
{

}

void EversaxDribbleChallengeMapToolsComponent::resetMap()
{
    this->plugin->gameWrapper->ExecuteUnrealCommand("servertravel ?");
}

void EversaxDribbleChallengeMapToolsComponent::checkpoint(int checkpoint)
{
}