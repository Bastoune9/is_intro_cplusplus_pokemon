#ifndef INTROCPPPOKE_PLAYER_H
#define INTROCPPPOKE_PLAYER_H

#include <string>
#include "pokeball.h"

class Player {
private:
    std::string name;
    Pokeball pokeball;

public:
    explicit Player(const std::string& name);

    std::string getName() const;
    Pokeball& getPokeball();
};

#endif //INTROCPPPOKE_PLAYER_H
