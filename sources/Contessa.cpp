#include "Contessa.hpp"
#include "Player.hpp"

namespace coup
{
    bool Contessa::block(Player &player)
    {
        if (player.role() != "Assassin" || player.get_action().at(0) != "specialcoup")
        {
            throw "Illegal Block!";
        }
        if (player.get_action().at(0) == "specialcoup")
        { // We can only block special assasin coup
            string target_string = player.get_action().at(1);
            int target_id = stoi(target_string);
            Player *target = this->game->get_player((size_t)target_id);
            target->is_alive = true;
            //this->game->players();
            return 1;
        }
        return 0;
    }
}