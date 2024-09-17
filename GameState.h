#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
public:
    virtual ~GameState() = default;
    // Déclaration des méthodes polymorphismes communes aux classes des différents états
    // Méthode appelée pour entrer dans un état
    virtual void enter() = 0;

    // Méthode appelée pour quitter un état
    virtual void exit() = 0;

    // Méthode pour gérer les événements dans un état
    virtual void handleEvent() = 0;

    // Méthode pour vérifier si le joueur a perdu
    virtual bool checkEndCondition() = 0;
};

#endif // GAMESTATE_H