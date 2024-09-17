#include "StateInit.h"
#include "StateExplorationSansDanger.h"
#include <iostream>

StateInit::StateInit(Game* game) : game(game) {}

void StateInit::enter() {
    std::cout << "Joueur créé !" << std::endl;
    game->changeState(std::make_shared<StateExplorationSansDanger>(game));
}

void StateInit::exit() {
    std::cout  << std::endl;
}

void StateInit::handleEvent() {
    // Pas d'événement dans cet état
}

bool StateInit::checkEndCondition() {
    return false;  // Pas de condition de fin ici
}
