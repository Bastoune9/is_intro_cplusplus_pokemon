#include "Player.h"

Player::Player(const std::string& name) : name(name) {}

std::string Player::getName() const {
    return name;
}

Pokeball& Player::getPokeball() {
    return pokeball;
}
