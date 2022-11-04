#pragma once

#include "../MapToolsComponent.h"

class CanyonDribbleMapToolsComponent : public MapToolsComponent
{
public:
    explicit CanyonDribbleMapToolsComponent(NetcodePlugin* plugin);

protected:
    void resetMap() override;
    void checkpoint(int checkpoint) override;
};
