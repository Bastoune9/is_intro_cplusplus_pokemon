#include "pokemon.h"
#include <iostream>
#include <utility>

int Pokemon::numberOfPokemons = 0;

// Constructeur
Pokemon::Pokemon(int id, string name, double hitPoint, double attackValue, double defenseValue, int generation)
    : id(id), name(std::move(name)), hitPoint(hitPoint), attackValue(attackValue), defenseValue(defenseValue), generation(generation) {
    numberOfPokemons++;
}

// Constructeur de recopie
Pokemon::Pokemon(const Pokemon &anotherPokemon) : id(anotherPokemon.id), name(anotherPokemon.name), hitPoint(anotherPokemon.hitPoint), attackValue(anotherPokemon.attackValue), defenseValue(anotherPokemon.defenseValue), generation(anotherPokemon.generation) {
    numberOfPokemons++;
}

// Destructeur
Pokemon::~Pokemon() {
    numberOfPokemons--;
}

// Affiche toutes les infos du Pokemon
void Pokemon::displayInfo() const {
    std::cout << "ID : " << id << " / " << name << std::endl;
}

// Affiche les stats du Pokemon
void Pokemon::displayStats() const {
    std::cout << "HP : " << hitPoint << " / ATK : " << attackValue << " / DEF : " << defenseValue << std::endl;
}

// Affiche toutes les infos du Pokemon
void Pokemon::displayAllInfo() const {
    displayInfo();
    displayStats();
    std::cout << std::endl;  // Saut de ligne
}

// Getters
double Pokemon::getHitPoint() const {
    return hitPoint;
}

string Pokemon::getName() const {
    return name;
}

int Pokemon::getId() const {
    return id;
}

//void Pokemon::displayNumberOfPokemons() {
//    std::cout << "Nombre de Pokemons en mémoire : " << numberOfPokemons << std::endl;
//}

// Fonction d'attaque d'un autre pokemonProgram
void Pokemon::attack(Pokemon &anotherPokemon) {
    std::cout << name << " attaque " << anotherPokemon.name << " !" << std::endl;
    if (attackValue > anotherPokemon.defenseValue) {
        // Calcul des dégâts
        double damage = (attackValue - anotherPokemon.defenseValue);
        anotherPokemon.hitPoint -= damage;
        std::cout << anotherPokemon.name << " subit " << damage << " points de dégâts !" << std::endl;
        // Vérifier si le Pokemon est KO
        if (anotherPokemon.hitPoint <= 0) {
            anotherPokemon.hitPoint = 0;
            std::cout << anotherPokemon.name << " est K.O. !" << std::endl;
        } else {
            std::cout << anotherPokemon.name << " a maintenant " << anotherPokemon.hitPoint << " points de vie !" << std::endl;
        }
    } else {
        std::cout << anotherPokemon.name << " a résisté à l'attaque !" << std::endl;
        hitPoint -= 20;  // Dégâts de fatigue pour éviter un SoftLock si deux Pokemons défensifs s'affrontent
        std::cout << name << " s'inflige 20 points de dégâts de fatigue ..." << std::endl;
        std::cout << name << " a maintenant " << hitPoint << " points de vie !" << std::endl;
    }
}
