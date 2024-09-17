#ifndef INTROCPPPOKE_STATEEXPLORATION_H
#define INTROCPPPOKE_STATEEXPLORATION_H

#include "GameState.h"
#include "Game.h"

class StateExploration : public GameState {
private:
    Game* game;

public:
    explicit StateExploration(Game* game);

    void enter() override;
    void exit() override;
    void handleEvent() override;
    bool checkEndCondition() override;
};

#endif //INTROCPPPOKE_STATEEXPLORATION_H
