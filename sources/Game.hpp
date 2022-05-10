#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"

using std::string;
using std::vector;
using std::to_string;

namespace coup
{
    class Player;
    class Game
    {
    public:
        vector<string> players_list;
        vector<Player*> players_obj_list;
        int player_count;
        int _turn;
        bool game_on;
        int sequence;

        Game();  // Constructor
        ~Game(); // Destructor
        string turn();
        vector<string> players();
        string winner();
        bool add_player(Player *player);
        bool remove_player(Player *player);
        Player* get_player(size_t _id);
        bool set_sequence(int num);
        bool set_player_count(int _count);
        int get_player_count();
        int get_sequence();
    };
}