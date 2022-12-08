#pragma once

#include "../AutoSplitterComponent.h"

class ThePathRingsAutoSplitterComponent : public AutoSplitterComponent
{
private:
    int level;

public:
    explicit ThePathRingsAutoSplitterComponent(NetcodePlugin* plugin);

protected:
    void onEnable() override;
    void update(const std::string& eventName, bool post, void* params) override;

    std::string getStartDescription() override;
    std::string getSplitDescription() override;
    std::string getResetDescription() override;
    std::string getDebugText() override;
};
