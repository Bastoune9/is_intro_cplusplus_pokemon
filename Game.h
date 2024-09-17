#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "Player.h"
#include <memory>

class Game {  // Gère la transition entre les états et les interactions avec le joueur
private:
    std::shared_ptr<GameState> currentState;
    Player joueur;
    int pokemonsBeaten;

public:
    explicit Game(const std::string& playerName);

    // Change d'état
    void changeState(std::shared_ptr<GameState> newState);

    // Méthode pour lancer le jeu
    void start();

    // Retourne l'instance du joueur
    Player& getJoueur();

    // Retourne le nombre de combats de dresseurs gagnés
    [[nodiscard]] int getPokemonsBeaten() const;

    // Incrémente le nombre de combats de dresseurs gagnés
    void incrementPokemonsBeaten();

    [[nodiscard]] const std::shared_ptr<GameState> &getCurrentState() const;
};

#endif // GAME_H