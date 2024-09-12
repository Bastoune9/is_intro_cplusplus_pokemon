#ifndef INTROCPPPOKE_POKEBALL_H
#define INTROCPPPOKE_POKEBALL_H

#include "setOfPokemons.h"

class Pokeball : public SetOfPokemon {
public:
    // Constructeur pour initialiser une pokeball
    Pokeball();
    // Fonctions d'ajout d'un poke à la pokeball
    void addPokemon(Pokemon* pokemon);  // Pokemon spécifique
    void addRandomPokemon();  // Pokemon aléatoire
    // Fonctions de récupération d'un pokemon de la pokeball
    [[nodiscard]] Pokemon* getPokemonByIndex(int index) override;
    [[nodiscard]] Pokemon* getPokemonByName(const std::string& name) override;
    // Affichage des pokemons de la pokeball
    void displayPokeballContent() ;
};

#endif //INTROCPPPOKE_POKEBALL_H
