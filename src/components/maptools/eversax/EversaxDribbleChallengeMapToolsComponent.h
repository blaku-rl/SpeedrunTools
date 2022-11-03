#pragma once

#include "../MapToolsComponent.h"

class EversaxDribbleChallengeMapToolsComponent : public MapToolsComponent
{
public:
    explicit EversaxDribbleChallengeMapToolsComponent(NetcodePlugin* plugin);

protected:
    void resetMap() override;
    void checkpoint(int checkpoint) override;
};
