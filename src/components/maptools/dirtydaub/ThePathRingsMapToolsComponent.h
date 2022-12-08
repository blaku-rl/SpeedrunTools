#pragma once

#include "../MapToolsComponent.h"

class ThePathRingsMapToolsComponent : public MapToolsComponent
{
public:
    explicit ThePathRingsMapToolsComponent(NetcodePlugin* plugin);

protected:
    void resetMap() override;
    void checkpoint(int checkpoint) override;
};
