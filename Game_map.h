//
// Created by tombr on 29/08/2017.
//

#ifndef GAME_GAME_MAP_H
#define GAME_GAME_MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Cmove_direction.h"
#include "rang.hpp"



class Game_map{
private:
    std::vector<std::string> map;
    std::vector<std::string> victory;

public:

    // default constructor printing map
    Game_map();

    // variables that will be used to find location of the player on map
    struct  Coordinates  { size_t x, y; };

    // function that allow to find location of the player on the map, variable i allows to find row and result refers to column
    Coordinates find_player();

    // function that provides coordinates for new move
    Coordinates next_position(Coordinates from, Cmove_direction direction);

    // function to validate move
    bool is_valid_move(Game_map::Coordinates to);

    // function to check for victory
    bool is_victory(Game_map::Coordinates to);

    // executing user move after move has been verified and its valid
    void set_position(Coordinates c, char new_value);

    void move_player(Cmove_direction direction, int steps, bool* end_game);

    // function to print map
    void print_base();
    void print_victory(bool* eng_game);

};

#endif //GAME_GAME_MAP_H
