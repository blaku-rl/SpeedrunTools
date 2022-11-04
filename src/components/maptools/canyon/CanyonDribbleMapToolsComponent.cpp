#include "CanyonDribbleMapToolsComponent.h"
#include "CanyonDribbleAutoSplitterComponent.h"

CanyonDribbleMapToolsComponent::CanyonDribbleMapToolsComponent(NetcodePlugin* plugin)
    : MapToolsComponent(plugin, std::make_shared<CanyonDribbleAutoSplitterComponent>(plugin),
        "Canyon Dribbling Challenge", "canyondribble", 0)
{

}

void CanyonDribbleMapToolsComponent::resetMap()
{
    this->plugin->gameWrapper->ExecuteUnrealCommand("servertravel ?");
}

void CanyonDribbleMapToolsComponent::checkpoint(int checkpoint)
{
}