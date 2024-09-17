#include <iostream>
#include "Game.h"

int main() {
    std::srand(static_cast<unsigned>(time(nullptr)));  // Initialiser le générateur aléatoire
    std::cout << "Bienvenue dans le Jeu de Pokémon !\n";

    // Demander le nom du joueur
    std::string playerName;
    std::cout << "Entrez votre nom de joueur : ";
    std::getline(std::cin, playerName);

    // Créer une instance du jeu
    Game game(playerName);

    // Démarrer le jeu
    game.start();

    // Boucle principale du jeu
    while (true) {
        game.getCurrentState()->handleEvent();  // Gérer les événements de l'état actuel du jeu

        // Vérifier si le joueur a perdu
        if (game.getCurrentState()->checkEndCondition()) {
            break;
        }
    }
    std::cout << "Merci d'avoir joué !\n";
    return 0;
}

