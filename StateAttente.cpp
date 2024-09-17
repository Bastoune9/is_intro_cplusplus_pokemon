#include "StateAttente.h"
#include "StateInit.h"
#include <iostream>

StateAttente::StateAttente(Game* game) : game(game) {}

void StateAttente::enter() {
    std::cout << "Bienvenue dans Pokemon. Appuyez sur Entrée pour commencer..." << std::endl;
    std::cin.ignore();  // Attendre que l'utilisateur appuie sur Entrée
    game->changeState(std::make_shared<StateInit>(game));
}

void StateAttente::exit() {
    std::cout << "Démarrage du jeu..." << std::endl;
}

void StateAttente::handleEvent() {
    // Pas d'événement dans cet état
}

bool StateAttente::checkEndCondition() {
    return false;  // Pas de condition de fin ici
}
