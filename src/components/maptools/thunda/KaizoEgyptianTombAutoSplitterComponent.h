#pragma once

#include "../AutoSplitterComponent.h"
#include <map>

class KaizoEgyptianTombAutoSplitterComponent : public AutoSplitterComponent
{
public:
    explicit KaizoEgyptianTombAutoSplitterComponent(NetcodePlugin* plugin);

protected:
    void onEnable() override;
    void update(const std::string& eventName, bool post, void* params) override;

    std::string getStartDescription() override;
    std::string getSplitDescription() override;
    std::string getResetDescription() override;
    std::string getDebugText() override;
};