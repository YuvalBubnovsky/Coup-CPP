#include "Game.hpp"
#include "Player.hpp"

namespace coup
{

    Game::Game()
    {
        this->game_on = false;
        this->player_count = 0;
        this->_turn = 0;
        this->sequence = -1;
    }

    Game::~Game() {}


    bool Game::add_player(Player *player)
    {
        this->players_list.push_back(player->get_name());
        this->player_count = players_list.size();
        int num = this->get_sequence();
        this->set_sequence(num++);
        return 1;
    }

    bool Game::remove_player(Player *player)
    {
        player->set_life(false);
        // TODO: fix/update player removal
       // this->players_list.erase(this->players_list.begin(),this->players_list.begin()+(player->get_id()%this->players_list.size()));
        this->player_count=this->players_list.size();
        return 1;
    }

    bool Game::set_sequence(int num)
    {
        this->sequence = num;
        return 1;
    }

    int Game::get_sequence()
    {
        return this->sequence;
    }

    string Game::turn()
    {
        return this->players_list.at(this->_turn%this->player_count);
    }
    vector<string> Game::players()
    {
        return this->players_list;
    }
    string Game::winner()
    {
        if(this->game_on==false){
            throw "Game Hasn't Started Yet!";
        }
        if(this->player_count!=1){
            throw "Game Didn't Finish Yet!";
        } else{
            return this->players_list.at(0);
        }
    }

}