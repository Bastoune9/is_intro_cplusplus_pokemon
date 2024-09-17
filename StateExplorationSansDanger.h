#ifndef INTROCPPPOKE_STATEEXPLORATIONSANSDANGER_H
#define INTROCPPPOKE_STATEEXPLORATIONSANSDANGER_H

#include "GameState.h"
#include "Game.h"

class StateExplorationSansDanger : public GameState {
private:
    Game* game;

public:
    explicit StateExplorationSansDanger(Game* game);

    void enter() override;
    void exit() override;
    void handleEvent() override;
    bool checkEndCondition() override;
};

#endif //INTROCPPPOKE_STATEEXPLORATIONSANSDANGER_H
