#pragma once

#include "../AutoSplitterComponent.h"

class DaciaSpringElectricChallengeAutoSplitterComponent : public AutoSplitterComponent
{
private:
    bool completed;

public:
    explicit DaciaSpringElectricChallengeAutoSplitterComponent(NetcodePlugin* plugin);

protected:
    void onEnable() override;
    void update(const std::string& eventName, bool post, void* params) override;

    std::string getStartDescription() override;
    std::string getSplitDescription() override;
    std::string getResetDescription() override;
    std::string getDebugText() override;
};