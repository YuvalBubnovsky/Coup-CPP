#include <iostream>
#include <vector>
#include "Game.hpp"

namespace coup{

    bool Game::start_game(){
        return false;
    }
    string Game::turn(){
        return " ";
    }
    vector<string> Game::get_list(){
        return this->player_list;
    }
    string Game::winner(){
        return "Yuval";
    }

}