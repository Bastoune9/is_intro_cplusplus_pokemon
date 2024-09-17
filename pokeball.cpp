#include "pokeball.h"
//#include "pokedex.h"
//#include <vector>

// Constructeur de pokeball, initialement vide
Pokeball::Pokeball() {}

// Ajoute un pokemon spécifique à la pokeball
void Pokeball::addPokemon(Pokemon *pokemon) {
    arrayOfPokemon.push_back(pokemon);
    // std::cout << pokemon->getName() << " a été ajouté à la Pokeball !" << std::endl;
}

// Ajoute un pokemon aléatoire à la pokeball
//void Pokeball::addRandomPokemon() {
//    Pokedex* pokedex = Pokedex::getInstance("");
//    Pokemon *pokemon = pokedex->getRandomPokemon();
//    arrayOfPokemon.push_back(pokemon);
//    std::cout << pokemon->getName() << " a été ajouté à la Pokeball !" << std::endl;
//}

// Récupération des pokemons de la pokeball
Pokemon* Pokeball::getPokemonByIndex(int index) {
    for (int i=0;i<arrayOfPokemon.size();i++){
        if (arrayOfPokemon.at(i)->getId() == index) {
            Pokemon * copie=arrayOfPokemon.at(i);
            this->arrayOfPokemon.erase(arrayOfPokemon.begin()+i);
            return copie;
        }
    }
    throw std::invalid_argument("Aucun Pokémon trouvé avec cet ID dans la Pokeball");
}

Pokemon* Pokeball::getPokemonByName(const std::string &name) {
    for (int i=0;i<arrayOfPokemon.size();i++){
        if (arrayOfPokemon.at(i)->getName() == name) {
            Pokemon * copie=arrayOfPokemon.at(i);
            this->arrayOfPokemon.erase(arrayOfPokemon.begin()+i);
            return copie;
        }
    }
    throw std::invalid_argument("Aucun Pokémon trouvé avec cet ID dans la Pokeball");
}

// Affichage du contenu de la Pokeball
void Pokeball::displayPokeballContent() {
    for (const auto& pokemon : arrayOfPokemon) {
        pokemon->displayAllInfo();
    }
}

bool Pokeball::isEmpty() const {
    return arrayOfPokemon.empty();
}

