#include "KaizoEgyptianTombMapToolsComponent.h"
#include "KaizoEgyptianTombAutoSplitterComponent.h"

KaizoEgyptianTombMapToolsComponent::KaizoEgyptianTombMapToolsComponent(NetcodePlugin* plugin)
    : MapToolsComponent(plugin, std::make_shared<KaizoEgyptianTombAutoSplitterComponent>(plugin),
        "Kaizo Egyptian Tomb", "kaizotomb", 0)
{

}

void KaizoEgyptianTombMapToolsComponent::resetMap()
{
    this->plugin->gameWrapper->ExecuteUnrealCommand("servertravel ?");
}

void KaizoEgyptianTombMapToolsComponent::checkpoint(int checkpoint)
{

}