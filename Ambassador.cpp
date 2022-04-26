#include <iostream>
#include "Ambassador.hpp"
#include "Player.hpp"

namespace coup{

    Ambassador::Ambassador(Game game, string name){
        this->name = name;
        this->game = game;
        this->coins = 0;
        this->role = "Ambassador";
    }
    bool Ambassador::transfer(Player from_player, Player to_player){
        return false;
    }
    bool Ambassador::block(Player player){
        return false;
    }
}