#include "TheMazeMapToolsComponent.h"
#include "TheMazeAutoSplitterComponent.h"

TheMazeMapToolsComponent::TheMazeMapToolsComponent(NetcodePlugin* plugin)
    : MapToolsComponent(plugin, std::make_shared<TheMazeAutoSplitterComponent>(plugin),
        "The Maze", "themaze", 0)
{

}

void TheMazeMapToolsComponent::resetMap()
{
    
}

void TheMazeMapToolsComponent::checkpoint(int checkpoint)
{

}