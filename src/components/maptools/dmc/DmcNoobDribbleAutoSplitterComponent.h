#pragma once

#include "../AutoSplitterComponent.h"
#include "../../../services/LiveSplitClient.h"

class DmcNoobDribbleAutoSplitterComponent : public AutoSplitterComponent
{
private:
    bool casual;
    int level;

public:
    explicit DmcNoobDribbleAutoSplitterComponent(NetcodePlugin* plugin);

protected:
    void onEnable() override;
    void update(const std::string& eventName, bool post, void* params) override;

    std::string getStartDescription() override;
    std::string getSplitDescription() override;
    std::string getResetDescription() override;
    std::string getDebugText() override;
};
