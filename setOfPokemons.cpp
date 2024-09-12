#include "setOfPokemons.h"

std::vector<Pokemon*> SetOfPokemon::arrayOfPokemon;

// Méthode d'affichage de la liste des Pokémon
void SetOfPokemon::displayPokemonList() {
    std::cout << "Liste des Pokémon :" << std::endl;
    for (Pokemon * pokemon : arrayOfPokemon) {
        pokemon->displayInfo();
    }
}
