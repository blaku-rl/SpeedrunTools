#pragma once

#include "CarState.h"
#include "BallState.h"

class GameState
{
public:
    CarState carState;
    BallState ballState;

    GameState();
    explicit GameState(ServerWrapper &server);

    void applyTo(ServerWrapper &server) const;
    bool render();
};
