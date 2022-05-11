#include "Assassin.hpp"
#include "Player.hpp"

namespace coup
{
    bool Assassin::coup(Player &target)
    {
        if (this->game->turn() != this->name)
        {
            throw "This is not your turn!";
        }
        if (this->coins() < A_COUP_COST)
        {
            throw "Not Enough Coins For Coup!";
        }
        if (!target.is_alive)
        {
            throw "Target Is Already Dead!";
        }
        if (this->coins() >= COUP_COINS)
        {
            Player::coup(target);
            return true;
        }
        this->coins_num -= A_COUP_COST;
        target.is_alive=false;
        this->get_action().clear();
        this->last_action.push_back("specialcoup");
        this->last_action.push_back(to_string(target.get_id()));
        this->game->_turn++;
        return true;
    }
}