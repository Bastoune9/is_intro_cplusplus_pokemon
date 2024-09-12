#include "pokemonParty.h"
#include <iostream>

// Constructeur à partir d'une pokeball
PokemonParty::PokemonParty(Pokeball& pokeball) {
    int maxPokemon = 6;
    int minPokemon = 1;
    int numPokemon = 0;
    std::string input;
    // Affichage du contenu de la Pokeball associée
    std::cout << "Pokemons utilisables : " << std::endl;
    pokeball.displayPokeballContent();

    // Choix du nombre de pokemons à transférer
    while (numPokemon < minPokemon || numPokemon > maxPokemon) {
        std::cout << "Combien de Pokemon souhaitez-vous ajouter à votre équipe ? (entre 1 et 6) : ";
        std::cin >> numPokemon;
        // En cas de saisie invalide :
        if (std::cin.fail() || numPokemon < minPokemon || numPokemon > maxPokemon) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // On ignore la saisie
            std::cout << "Entrée invalide, veuillez entrer un nombre entre 1 et 6." << std::endl;
        } else {
            break;
        }
    }
    // Choix des Pokemons à transférer (par leur nom ou par leur index de pokedex)
    for (int i = 0; i < numPokemon; i++) {
        std::cout << "Veuillez entrer le nom ou l'index du Pokemon à transférer : ";
        std::cin >> input;
        try {
            Pokemon* chosenPokemon = nullptr;
            // Vérifier si l'entrée est un entier (index) ou un nom
            if (std::isdigit(input[0])) {
                int index = std::stoi(input);
                chosenPokemon = pokeball.getPokemonByIndex(index);
            } else {
                chosenPokemon = pokeball.getPokemonByName(input);
            }
            // Transférer le Pokémon dans la PokemonParty
            arrayOfPokemon.push_back(chosenPokemon);
            std::cout << chosenPokemon->getName() << " a été transféré dans la PokemonParty !" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erreur : " << e.what() << std::endl;
            --i;  // Réessayer si une erreur s'est produite
        }
    }
    // Affichage de la PokemonParty après sélection
    std::cout << "Votre PokemonParty a été constituée avec succès !" << std::endl;
    displayParty();
}

// Affichage de la PokemonParty
void PokemonParty::displayParty() const {
    std::cout << "Contenu de la PokemonParty :" << std::endl;
    for (const Pokemon* pokemon : arrayOfPokemon) {
        pokemon->displayInfo();
    }
}

// Récupération par index
Pokemon* PokemonParty::getPokemonByIndex(int index) {
    for (Pokemon* pokemon : arrayOfPokemon) {
        if (pokemon->getId() == index) {
            return pokemon;
        }
    }
    throw std::invalid_argument("Aucun Pokémon trouvé avec cet ID dans la PokemonParty.");
}

// Récupération par nom
Pokemon* PokemonParty::getPokemonByName(const std::string& name) {
    for (Pokemon* pokemon : arrayOfPokemon) {
        if (pokemon->getName() == name) {
            return pokemon;
        }
    }
    throw std::invalid_argument("Aucun Pokémon trouvé avec ce nom dans la PokemonParty.");
}
