#include <iostream>
#include "Captain.hpp"
#include "Player.hpp"

namespace coup{
    
    Captain::Captain(Game game, string name){
        this->name = name;
        this->game = game;
        this->coins = 0;
        this->role = "Captain";
    }
    bool Captain::block(Player player){
        return false;
    }
    bool Captain::steal(Player player){
        return false;
    }
}