#include <iostream>
#include "Player.hpp"


namespace coup{
    bool Player::income(){
        return false;
    }
    bool Player::foreign_aid(){
        return false;
    }
    bool Player::coup(Player){
        return false;
    }
    int Player::get_coins(){
        return 0;
    }
    string Player::get_role(){
        return this->role;
    }
}