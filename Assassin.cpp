#include <iostream>
#include "Assassin.hpp"
#include "Player.hpp"

namespace coup{
    
    Assassin::Assassin(Game game, string name){
        this->name = name;
        this->game = game;
        this->coins = 0;
        this->role = "Assassin";
    }
    bool Assassin::coup(Player player){
        return false;
    }
}