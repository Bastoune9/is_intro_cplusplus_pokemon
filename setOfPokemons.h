#ifndef INTROCPPPOKE_SETOFPOKEMONS_H
#define INTROCPPPOKE_SETOFPOKEMONS_H


#include <string>
#include <vector>
#include <iostream>
#include "pokemon.h"

class SetOfPokemon {
protected:
    static std::vector<Pokemon*> arrayOfPokemon;

public:
    // Constructeur abstrait
    virtual ~SetOfPokemon() = 0;  // Classe abstraite

    // Méthodes abstraites pour récupérer un Pokémon
    [[nodiscard]] virtual Pokemon* getPokemonByIndex(int index) const = 0;
    [[nodiscard]] virtual Pokemon* getPokemonByName(const std::string& name) const = 0;
    // Méthode concrète d'affichage de la liste des Pokémon
    static void displayPokemonList();
};

// Implémentation du destructeur abstrait
inline SetOfPokemon::~SetOfPokemon() {}

#endif //INTROCPPPOKE_SETOFPOKEMONS_H
