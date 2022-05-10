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
        bool set_sequence(int num);
        int get_sequence();
    };
}