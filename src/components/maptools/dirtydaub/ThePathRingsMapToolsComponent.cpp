#include "ThePathRingsMapToolsComponent.h"
#include "ThePathRingsAutoSplitterComponent.h"

ThePathRingsMapToolsComponent::ThePathRingsMapToolsComponent(NetcodePlugin* plugin)
    : MapToolsComponent(plugin, std::make_shared<ThePathRingsAutoSplitterComponent>(plugin),
        "The Path Rings", "pathrings", 0)
{

}

void ThePathRingsMapToolsComponent::resetMap()
{
    this->plugin->gameWrapper->ExecuteUnrealCommand("servertravel ?");
}

void ThePathRingsMapToolsComponent::checkpoint(int checkpoint)
{
}
