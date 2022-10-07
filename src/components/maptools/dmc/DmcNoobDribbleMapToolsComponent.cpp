#include "DmcNoobDribbleMapToolsComponent.h"
#include "DmcNoobDribbleAutoSplitterComponent.h"

DmcNoobDribbleMapToolsComponent::DmcNoobDribbleMapToolsComponent(NetcodePlugin* plugin)
    : MapToolsComponent(plugin, std::make_shared<DmcNoobDribbleAutoSplitterComponent>(plugin),
        "Noob Dribble", "noobdribble", 0)
{

}

void DmcNoobDribbleMapToolsComponent::resetMap()
{
    this->plugin->gameWrapper->ExecuteUnrealCommand("servertravel ?");
}

void DmcNoobDribbleMapToolsComponent::checkpoint(int checkpoint)
{
    
}
