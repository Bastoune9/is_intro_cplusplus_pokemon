#ifndef INTROCPPPOKE_POKEMONS_H
#define INTROCPPPOKE_POKEMONS_H

#include <iostream>
#include <string>

using std::string;

class Pokemon {
private:
    int id;
    string name;
    double hitPoint;
    double attackValue;
    double defenseValue;
    int generation;
    static int numberOfPokemons;

public:
    Pokemon() = delete;
    // Constructeur
    Pokemon(int id, string name, double hitPoint, double attackValue, double defenseValue, int generation);
    // Recopie
    Pokemon(const Pokemon& anotherPokemon);
    // Méthode affichage
    void displayInfo() const;
    // Fonctions de getter
    [[nodiscard]] double getAttackValue() const;
    [[nodiscard]] double getDefenseValue() const;
    [[nodiscard]] string getName() const;
    [[nodiscard]] int getId() const;
    // Fonction d'attaque d'un autre Pokemon
    void attack(Pokemon& anotherPokemon) const;
    static int getNumberOfPokemons();

    // Destructeur
    ~Pokemon();


};

#endif //INTROCPPPOKE_POKEMONS_H