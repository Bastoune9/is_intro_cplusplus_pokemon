#include <fstream>
#include <sstream>
#include "pokedex.h"

// Initialisation du pointeur statique
Pokedex* Pokedex::instance = nullptr;

// Constructeur privé
Pokedex::Pokedex(const std::string& filename) {
    Pokedex::lireCSV(filename);  // Charger les Pokémon à partir du fichier CSV
}

// Destructeur
Pokedex::~Pokedex() {
    for (auto& pokemon : arrayOfPokemon) {
        delete pokemon;
    }
}

// Méthode pour obtenir l'instance unique (Singleton)
Pokedex* Pokedex::getInstance(const std::string& filename) {
    if (instance == nullptr) {
        instance = new Pokedex(filename);  // Créer une nouvelle instance si elle n'existe pas
    }
    return instance;
}

// Redéfinition de getPokemonByIndex
Pokemon* Pokedex::getPokemonByIndex(int id) {
    for (const auto& pokemon : arrayOfPokemon) {
        if (pokemon->getId() == id) {
            return pokemon;  // Retourner une copie du Pokémon
        }
    }
    throw std::invalid_argument("Aucun Pokémon avec ce nom trouvé");
}

// Redéfinition de getPokemonByName
Pokemon* Pokedex::getPokemonByName(const std::string& name) {
    for (const auto& pokemon : arrayOfPokemon) {
        if (pokemon->getName() == name) {
            return pokemon;  // Retourner une copie du Pokémon
        }
    }
    throw std::invalid_argument("Aucun Pokémon avec ce nom trouvé");
}

// Renvoie un pokemon aléatoire
Pokemon* Pokedex::getRandomPokemon() {
    int randomIndex = std::rand() % arrayOfPokemon.size(); // NOLINT(*-narrowing-conversions, *-msc50-cpp)
    return arrayOfPokemon[randomIndex];
}


// Fonction de chargement du fichier CSV
void Pokedex::lireCSV (const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {  // Vérifie si le fichier est bien ouvert
        std::cerr << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl;
        return;
    }

    std::string ligne;
    std::getline(fichier, ligne);  // On retire la première ligne
    while (std::getline(fichier, ligne)) { // Lit le fichier ligne par ligne
        std::stringstream ss(ligne);
        std::string cellule;
        std::vector<std::string> donneesLigne;

        while (std::getline(ss, cellule, ',')) {  // Sépare les données de la ligne grâce aux virgules
            donneesLigne.push_back(cellule);
        }
        int id = std::stoi(donneesLigne.at(0));
        std::string name = donneesLigne.at(1);
        int hitPoints = std::stoi(donneesLigne.at(4));
        int attackValue = std::stoi(donneesLigne.at(5));
        int defenseValue = std::stoi(donneesLigne.at(6));
        int generation = std::stoi(donneesLigne.at(11));
        arrayOfPokemon.push_back(new Pokemon(id, name, hitPoints, attackValue, defenseValue, generation));
        // On définit autant de données qu'on veut
    }
    fichier.close();
}
