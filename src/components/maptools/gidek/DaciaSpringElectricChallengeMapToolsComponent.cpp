#include "DaciaSpringElectricChallengeMapToolsComponent.h"
#include "DaciaSpringElectricChallengeAutoSplitterComponent.h"

DaciaSpringElectricChallengeMapToolsComponent::DaciaSpringElectricChallengeMapToolsComponent(NetcodePlugin* plugin)
    : MapToolsComponent(plugin, std::make_shared<DaciaSpringElectricChallengeAutoSplitterComponent>(plugin),
        "Dacia Spring Electric Challenge", "daciaspring", 0)
{

}

void DaciaSpringElectricChallengeMapToolsComponent::resetMap()
{
    this->plugin->gameWrapper->ExecuteUnrealCommand("servertravel ?");
}

void DaciaSpringElectricChallengeMapToolsComponent::checkpoint(int checkpoint)
{
}