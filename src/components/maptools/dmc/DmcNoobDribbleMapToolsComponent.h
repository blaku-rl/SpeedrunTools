#pragma once

#include "../MapToolsComponent.h"

class DmcNoobDribbleMapToolsComponent : public MapToolsComponent
{
public:
    explicit DmcNoobDribbleMapToolsComponent(NetcodePlugin* plugin);

protected:
    void resetMap() override;
    void checkpoint(int checkpoint) override;
};
