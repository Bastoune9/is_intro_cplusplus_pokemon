#ifndef INTROCPPPOKE_POKEDEX_H
#define INTROCPPPOKE_POKEDEX_H

#include "pokemon.h"
#include "setOfPokemons.h"
#include <string>
#include <vector>
#include <iostream>

class Pokedex : public SetOfPokemon {
private:
    static Pokedex* instance;
    // Constructeur privé pour le Singleton
    explicit Pokedex(const std::string& filename);

public:
    // Méthode statique pour obtenir l'instance unique (permet de rendre le constructeur privé)
    static Pokedex* getInstance(const std::string& filename);

    // Fonctions de récupération
    Pokemon* getPokemonByIndex(int index) override;
    Pokemon* getPokemonByName(const std::string& name) override;
    Pokemon *getRandomPokemon();
    // Fonction d'ouverture du fichier CSV
    void lireCSV (const std::string& nomFichier);

    // Destructeur
    ~Pokedex() override;


};

#endif //INTROCPPPOKE_POKEDEX_H
