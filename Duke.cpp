#include <iostream>
#include "Duke.hpp"
#include "Player.hpp"

namespace coup{
    
    Duke::Duke(Game game, string name){
        this->name = name;
        this->game = game;
        this->coins = 0;
        this->role = "Duke";
    }
    bool Duke::tax(){
        return false;
    }
    bool Duke::block(Player player){
        return false;
    }
}