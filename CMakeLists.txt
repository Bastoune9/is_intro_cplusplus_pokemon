cmake_minimum_required(VERSION 3.26)
project(introCPPPoke)

set(CMAKE_CXX_STANDARD 17)

add_executable(introCPPPoke main.cpp
        pokemon.cpp
        setOfPokemons.cpp
        pokedex.cpp
        pokeball.cpp
        pokemonParty.cpp
        Game.cpp
        Player.cpp
        StateAttente.cpp
        StateInit.cpp
        StateExplorationSansDanger.cpp
        StateExploration.cpp
        StateCombatDresseur.cpp)

