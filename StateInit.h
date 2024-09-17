#ifndef INTROCPPPOKE_STATEINIT_H
#define INTROCPPPOKE_STATEINIT_H

#include "GameState.h"
#include "Game.h"

class StateInit : public GameState {
private:
    Game* game;

public:
    explicit StateInit(Game* game);

    void enter() override;
    void exit() override;
    void handleEvent() override;
    bool checkEndCondition() override;
};

#endif //INTROCPPPOKE_STATEINIT_H
