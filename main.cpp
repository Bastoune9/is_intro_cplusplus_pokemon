#include <iostream>
#include "pokedex.h"
#include "pokeball.h"
#include "pokemonParty.h"
#include <vector>

int main() {
    std::srand(static_cast<unsigned>(time(nullptr))); // NOLINT(*-msc51-cpp)
    Pokedex* pokedex = Pokedex::getInstance("../Ressources/pokedex.csv");
    Pokemon::displayNumberOfPokemons();
    // Créer une pokeball
    Pokeball pokeball;
    try {
        pokeball.addPokemon(pokedex->getPokemonByName("Azumarill"));
        pokeball.addPokemon(pokedex->getPokemonByName("Heliolisk"));
        pokeball.addPokemon(pokedex->getPokemonByIndex(333));
        pokeball.addPokemon(pokedex->getPokemonByIndex(150));
        pokeball.addRandomPokemon();
        pokeball.addRandomPokemon();
        pokeball.addRandomPokemon();
        pokeball.addRandomPokemon();
        pokeball.addRandomPokemon();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    // Créer une PokemonParty en utilisant une Pokeball
    try {
        PokemonParty party(pokeball);  // Demande de choisir les Pokémon
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Afficher le contenu restant de la Pokeball
    std::cout << "Contenu restant de la Pokeball :" << std::endl;
    pokeball.displayPokeballContent();

    Pokemon::displayNumberOfPokemons();
    return 0;
}

