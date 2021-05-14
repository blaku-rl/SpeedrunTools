#include "SpeedJumpRings1MapToolsComponent.h"
#include "../../autosplitter/runs/speedjump/SpeedJumpRings1AutoSplitterComponent.h"

SpeedJumpRings1MapToolsComponent::SpeedJumpRings1MapToolsComponent(BakkesMod::Plugin::BakkesModPlugin *plugin)
        : MapToolsComponent(plugin, std::make_shared<SpeedJumpRings1AutoSplitterComponent>(plugin),
                            "Speed Jump Rings 1", "sjr1", 0)
{

}

void SpeedJumpRings1MapToolsComponent::resetMap()
{
    this->mapToolsModel.resetPlayers();
}

void SpeedJumpRings1MapToolsComponent::checkpoint(int checkpoint)
{

}
