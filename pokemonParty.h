#ifndef INTROCPPPOKE_POKEMONPARTY_H
#define INTROCPPPOKE_POKEMONPARTY_H

#include "pokeball.h"
#include "setOfPokemons.h"

class PokemonParty : public SetOfPokemon {
public:
    explicit PokemonParty(Pokeball& pokeball);
    void displayParty() const;
    Pokemon *getPokemonByIndex(int index) override;
    Pokemon *getPokemonByName(const string &name) override;
};

#endif //INTROCPPPOKE_POKEMONPARTY_H

