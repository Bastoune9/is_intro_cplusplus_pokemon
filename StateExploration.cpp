#include "StateExploration.h"
#include "StateCombatDresseur.h"
#include "pokemon.h"
#include "pokedex.h"
#include <cstdlib>
#include <iostream>

StateExploration::StateExploration(Game* game) : game(game) {}

void StateExploration::enter() {
    std::cout << "Vous partez explorer avec vos Pokémon." << std::endl;
    handleEvent();
}

void StateExploration::exit() {
//    std::cout << "Vous quittez l'exploration." << std::endl;
}

void StateExploration::handleEvent() {
    int randomEvent = std::rand() % 100;
    if (randomEvent < 80) {
        // Rencontre avec un Pokémon sauvage
        Pokedex* pokedex = Pokedex::getInstance("../Ressources/pokedex.csv");
        Pokemon* randomPokemon = pokedex->getRandomPokemon();
        std::cout << "Un " << randomPokemon->getName() << " sauvage apparaît !" << std::endl;
        randomPokemon->displayStats();
        std::cout << "Voulez-vous essayer de capturer ce Pokemon (0) ou le laisser s'enfuir (1) ? ";
        bool response = false;
        std::cin >> response;

        // Capturer le Pokémon
        if (response) {
            std::cout << "Vous laissez " << randomPokemon->getName() << " s'enfuir.\n" << std::endl;
        } else {
            if (std::rand() % 2 == 0) {  // 0 ou 1, donc 50% de chances
                game->getJoueur().getPokeball().addPokemon(randomPokemon);
                std::cout << randomPokemon->getName() << " a été capturé !\n" << std::endl;
            } else
                std::cout << "La capture a échoué, " << randomPokemon->getName() << " s'est enfui !\n" << std::endl;
        }

    } else {
        // Combat de dresseur
        std::cout << "Un dresseur vous défie en duel !" << std::endl;
        game->changeState(std::make_shared<StateCombatDresseur>(game));
    }
}

bool StateExploration::checkEndCondition() {
    return false;  // Pas de condition de fin ici
}
