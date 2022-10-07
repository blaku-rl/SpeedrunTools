#pragma once

#include "../MapToolsComponent.h"

class DaciaSpringElectricChallengeMapToolsComponent : public MapToolsComponent
{
public:
    explicit DaciaSpringElectricChallengeMapToolsComponent(NetcodePlugin* plugin);

protected:
    void resetMap() override;
    void checkpoint(int checkpoint) override;
};
