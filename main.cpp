#include <iostream>
#include "pokedex.h"
#include <vector>

int main() {
//    Pokemon electhor(1, "Electhor", 100, 30, 20, 1);  // Constructeur classique
//    Pokemon sulfura(electhor);  // Constructeur de recopie
//    Pokemon machopeur(2, "Machopeur", 40, 30, 10, 1);
//    Pokemon flagadoss(3, "Flagadoss", 110, 15, 50, 1);
//    electhor.displayInfo();
//    machopeur.attack(electhor);
//    electhor.attack(machopeur);
//    electhor.attack(machopeur);

    Pokedex* pokedex = Pokedex::getInstance("../Ressources/pokedex.csv");
    // Afficher la liste des Pokemons
    Pokedex::displayPokemonList();

    // Test de la récupération par index
    try {
        Pokemon* azumarill = pokedex->getPokemonByIndex(184);
        azumarill->displayInfo();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    // Test de la récupération par nom
    try {
        Pokemon* iguolta = pokedex->getPokemonByName("Heliolisk");
        iguolta->displayInfo();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
