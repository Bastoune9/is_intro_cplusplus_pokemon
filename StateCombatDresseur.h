#ifndef INTROCPPPOKE_STATECOMBATDRESSEUR_H
#define INTROCPPPOKE_STATECOMBATDRESSEUR_H

#include "GameState.h"
#include "Game.h"
#include "pokemonParty.h"

class StateCombatDresseur : public GameState {
private:
    Game* game;
    // Méthode de simulation de combat
    bool simulateBattle(PokemonParty& playerParty, PokemonParty& opponentParty);

public:
    explicit StateCombatDresseur(Game* game);

    void enter() override;
    void exit() override;
    void handleEvent() override;
    bool checkEndCondition() override;
};

#endif //INTROCPPPOKE_STATECOMBATDRESSEUR_H
