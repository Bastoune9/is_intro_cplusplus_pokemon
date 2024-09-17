#include "Game.h"
#include "StateAttente.h"  // État initial

// Gère la transition entre les états et les interactions avec le joueur

Game::Game(const std::string& playerName) : joueur(playerName), trainerBattlesWon(0) {
    currentState = std::make_shared<StateAttente>(this);
}

// Méthode permettant de changer l'état du jeu
void Game::changeState(std::shared_ptr<GameState> newState) {
    currentState->exit();
    currentState = newState;
    currentState->enter();
}

// Pour lancer le jeu
void Game::start() {
    currentState->enter();
}

Player& Game::getJoueur() {
    return joueur;
}

const std::shared_ptr<GameState> &Game::getCurrentState() const {
    return currentState;
}

// Retourne le nombre de combats de dresseurs gagnés
int Game::getTrainerBattlesWon() const {
    return trainerBattlesWon;
}

// Incrémente le nombre de combats de dresseurs gagnés
void Game::incrementTrainerBattlesWon() {
    trainerBattlesWon++;
}
