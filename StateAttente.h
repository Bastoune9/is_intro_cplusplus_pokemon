#ifndef INTROCPPPOKE_STATEATTENTE_H
#define INTROCPPPOKE_STATEATTENTE_H

#include "GameState.h"
#include "Game.h"

class StateAttente : public GameState {
private:
    Game* game;

public:
    explicit StateAttente(Game* game);

    void enter() override;
    void exit() override;
    void handleEvent() override;
    bool checkEndCondition() override;
};

#endif //INTROCPPPOKE_STATEATTENTE_H
