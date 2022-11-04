#pragma once

#include "../AutoSplitterComponent.h"
#include "../../../models/collision/Rect3d.h"

class CanyonDribbleAutoSplitterComponent : public AutoSplitterComponent
{
private:
    Rect3d startBox;

public:
    explicit CanyonDribbleAutoSplitterComponent(NetcodePlugin* plugin);

protected:
    void onEnable() override;
    void update(const std::string& eventName, bool post, void* params) override;

    std::string getStartDescription() override;
    std::string getSplitDescription() override;
    std::string getResetDescription() override;
    std::string getDebugText() override;
};