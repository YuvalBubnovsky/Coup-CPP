#include "Captain.hpp"
#include "Player.hpp"

namespace coup
{
    bool Captain::block(Player& player) { 
        if (player.role() != "Captain" || player.get_action().at(0) != "steal")
        {
            throw "Illegal Block!";
        }
        
     }
    bool Captain::steal(Player& player) { 

     }
}