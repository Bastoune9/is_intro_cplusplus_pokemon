#include "StateCombatDresseur.h"
#include "StateAttente.h"
#include "StateExploration.h"
#include "StateExplorationSansDanger.h"
#include "pokeball.h"
#include "pokemonParty.h"
#include "pokedex.h"
#include <iostream>

StateCombatDresseur::StateCombatDresseur(Game* game) : game(game) {}

void StateCombatDresseur::enter() {
    // Créer la PokemonParty du joueur
    Pokeball& pokeball = game->getJoueur().getPokeball();
    PokemonParty playerParty(pokeball);
    int size = playerParty.getSize();

    // Créer la PokemonParty de l'adversaire
    Pokedex* pokedex = Pokedex::getInstance("../Ressources/pokedex.csv");
    PokemonParty opponentParty(size, *pokedex);

    // Simuler le combat
    bool playerWins = simulateBattle(playerParty, opponentParty);

    if (playerWins) {
        game->incrementPokemonsBeaten();
        // On renvoie le joueur en exploration en fonction du nombre de pokemons qu'il lui reste
        if (!game->getJoueur().getPokeball().isEmpty()) {
            game->changeState(std::make_shared<StateExploration>(game));
        } else {
            game->changeState(std::make_shared<StateExplorationSansDanger>(game));
        }
    } else {
        std::cout << "\nGAME OVER" << std::endl;
    }
}

bool StateCombatDresseur::simulateBattle(PokemonParty& playerParty, PokemonParty& opponentParty) {
    // Référence aux Pokémon de chaque partie
    std::vector<Pokemon*>& playerPokemons = playerParty.getArrayOfPokemon();
    std::vector<Pokemon*>& opponentPokemons = opponentParty.getArrayOfPokemon();

    size_t playerIndex = 0;
    size_t opponentIndex = 0;
    while (playerIndex < playerPokemons.size() && opponentIndex < opponentPokemons.size()) {
        Pokemon* playerPokemon = playerPokemons[playerIndex];
        Pokemon* opponentPokemon = opponentPokemons[opponentIndex];

        std::cout << "\nTour de combat : " << std::endl;
        std::cout << "Le Pokémon du joueur : " << playerPokemon->getName() << std::endl;
        playerPokemon->displayStats();
        std::cout << "Le Pokémon de l'adversaire : " << opponentPokemon->getName() << std::endl;
        opponentPokemon->displayStats();

        // Joueur attaque ou remplace son Pokémon
        bool playerAction = false; // false = attaque, true = remplacer
        std::cout << "\nVoulez-vous attaquer (0) ou remplacer votre Pokémon (1) ? ";
        std::cin >> playerAction;

        if (playerAction) {
            // Remplacer le Pokémon
            if (playerIndex + 1 < playerPokemons.size()) {
                ++playerIndex;
                playerPokemon = playerPokemons[playerIndex];
                std::cout << "Le joueur a remplacé son Pokémon par : " << playerPokemon->getName() << std::endl;
            } else {
                std::cout << "Le joueur n'a plus de Pokémon à remplacer." << std::endl;
            }

        } else {
            // Le joueur attaque
            playerPokemon->attack(*opponentPokemon);
            // Vérifier si le Pokémon adverse est KO
            if (opponentPokemon->getHitPoint() <= 0) {
                game->incrementPokemonsBeaten();
                std::cout << "Vous gagnez un point de combat !" << std::endl;
                ++opponentIndex;
                if (opponentIndex < opponentPokemons.size()) {
                    opponentPokemon = opponentPokemons[opponentIndex];
                    std::cout << "L'adversaire envoie un nouveau Pokémon : " << opponentPokemon->getName() << std::endl;
                }
            } else { // Vérifier si le Pokemon attaquant est tombé KO de fatigue
                if (playerPokemon->getHitPoint() <= 0) {
                    std::cout << playerPokemon->getName() << " tombe K.O. de fatigue." << std::endl;
                    ++playerIndex;
                    if (playerIndex < playerPokemons.size()) {
                        playerPokemon = playerPokemons[playerIndex];
                        std::cout << "Le joueur envoie un nouveau Pokémon : " << playerPokemon->getName() << std::endl;
                    } else {  // Plus de Pokemon
                        std::cout << "Le joueur a perdu tous ses Pokémon. L'adversaire gagne." << std::endl;
                        return false;
                    }
                }
            }
        }
        // L'adversaire attaque à tous les tours
        if (opponentIndex < opponentPokemons.size()) {
            opponentPokemon->attack(*playerPokemon);
            // Vérifier si le Pokémon du joueur est KO
            if (playerPokemon->getHitPoint() <= 0) {
                ++playerIndex;
                if (playerIndex < playerPokemons.size()) {
                    playerPokemon = playerPokemons[playerIndex];
                    std::cout << "Le joueur envoie un nouveau Pokémon : " << playerPokemon->getName() << std::endl;
                }
            } else {
                // Vérifier si le Pokémon adverse attaquant est KO de fatigue
                if (opponentPokemon->getHitPoint() <= 0) {
                    game->incrementPokemonsBeaten();
                    std::cout << "Vous gagnez un point de combat !" << std::endl;
                    ++opponentIndex;
                    if (opponentIndex < opponentPokemons.size()) {
                        opponentPokemon = opponentPokemons[opponentIndex];
                        std::cout << "L'adversaire envoie un nouveau Pokémon : " << opponentPokemon->getName()<< std::endl;
                    } else {  // Plus de Pokemon
                        std::cout << "L'adversaire a perdu tous ses Pokémon. Le joueur gagne." << std::endl;
                        return true;
                    }
                }
            }
        }
        // Vérifier si un joueur a perdu tous ses Pokémon
        if (playerIndex >= playerPokemons.size()) {
            std::cout << "Le joueur a perdu tous ses Pokémon. L'adversaire gagne le combat ...\n" << std::endl;
            return false;
        }
        if (opponentIndex >= opponentPokemons.size()) {
            std::cout << "L'adversaire a perdu tous ses Pokémon. Le joueur gagne le combat !\n" << std::endl;
            return true;
        }
    }
    return false; // En cas de fin de la boucle sans vainqueur clair
}


void StateCombatDresseur::exit() {}

void StateCombatDresseur::handleEvent() {
    // Aucun événement spécifique
}

bool StateCombatDresseur::checkEndCondition() {
        std::cout << "Score final :  " << game->getPokemonsBeaten() << " points de combat !" << std::endl;
        return true;
}
