#include <iostream>
#include "Contessa.hpp"
#include "Player.hpp"

namespace coup{
    
    Contessa::Contessa(Game game, string name){
        this->name = name;
        this->game = game;
        this->coins = 0;
        this->role = "Contessa";
    }
    bool Contessa::block(Player player){
        return false;
    }
}