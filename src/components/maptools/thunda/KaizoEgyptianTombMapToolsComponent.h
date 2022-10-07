#pragma once

#include "../MapToolsComponent.h"

class KaizoEgyptianTombMapToolsComponent : public MapToolsComponent
{
public:
    explicit KaizoEgyptianTombMapToolsComponent(NetcodePlugin* plugin);

protected:
    void resetMap() override;
    void checkpoint(int checkpoint) override;
};