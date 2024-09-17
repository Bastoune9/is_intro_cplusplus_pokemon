#include "StateExplorationSansDanger.h"
#include "StateExploration.h"
#include "pokedex.h"

StateExplorationSansDanger::StateExplorationSansDanger(Game* game) : game(game) {}

void StateExplorationSansDanger::enter() {
    handleEvent();
}

void StateExplorationSansDanger::exit() {
    std::cout << "Vous possédez un Pokemon, vous pouvez désormais rencontrer des dresseurs. \n" << std::endl;
}

void StateExplorationSansDanger::handleEvent() {
    std::cout << "Vous partez capturer votre premier Pokemon." << std::endl;
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

    // Si le joueur a au moins un Pokémon, on passe à l'état d'exploration classique
    if (!game->getJoueur().getPokeball().isEmpty()) {
        game->changeState(std::make_shared<StateExploration>(game));
    }
}

bool StateExplorationSansDanger::checkEndCondition() {
    return false;  // Pas de condition de fin ici
}
