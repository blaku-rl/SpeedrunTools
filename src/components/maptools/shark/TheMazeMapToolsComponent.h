#pragma once

#include "../MapToolsComponent.h"

class TheMazeMapToolsComponent : public MapToolsComponent
{
public:
    explicit TheMazeMapToolsComponent(NetcodePlugin* plugin);

protected:
    void resetMap() override;
    void checkpoint(int checkpoint) override;
};