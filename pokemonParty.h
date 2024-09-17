#ifndef INTROCPPPOKE_POKEMONPARTY_H
#define INTROCPPPOKE_POKEMONPARTY_H

#include "pokedex.h"
#include "pokeball.h"
#include "setOfPokemons.h"

class PokemonParty : public SetOfPokemon {
public:
    // Constructeur à partir d'une pokeball
    explicit PokemonParty(Pokeball& pokeball);
    // Constructeur avec nombre de Pokémon aléatoires (pour les équipes des dresseurs adverses)
    PokemonParty(int numberOfPokemons, Pokedex& pokedex);
    void displayParty() const;
    Pokemon *getPokemonByIndex(int index) override;
    Pokemon *getPokemonByName(const string &name) override;
    // Méthode pour obtenir la liste des Pokémon
    std::vector<Pokemon*>& getArrayOfPokemon();
    [[nodiscard]] int getSize() const;
};

#endif //INTROCPPPOKE_POKEMONPARTY_H

