//
// Created by tombr on 29/08/2017.
//

#include "Game_map.h"

Game_map::Game_map()  {
    map = {
            "=======================================================================================================",
            "|   X ###         ~~ ~~                                ###########                                    |  ===========================================",
            "|                  ~     ###########    ###########                                    ####           |  ||Player stats:     || Monster stats:    ||",
            "|    ######             ###########   #############        #        #######        #########          |  || Life:            || Life:             ||",
            "|   ########             ###########    ###########        ###         #######        ######          |  || Steps:           || Steps:            ||",
            "|   ####                    #####         #######        ######          #######                      |  || Power:           || Power:            ||",
            "|                   #####                   ###                            ########     #######       |  || Type:            || Type:             ||",
            "|      ####         ######    ~~~~~~                ########    ######        ######       ######     |  ===========================================",
            "|   #########    #######       ~~~~      ########             ##########                      #####   |",
            "|   #########       #######  ~~~     #########            ########           ~~~~~            ######  |",
            "|     #####         #######                          #####               ###   ~~~~~~~                |",
            "|                   ############        ########              ########              ##########        |",
            "|########             #############    ######                 ########       #####                    |",
            "|########                             ####       ######          #########           ######           |",
            "|                ######               ###      ######             #######               ######        |",
            "|   #########            ########            #############                                            |",
            "|   #########             ########                  #####    #############                #####       |",
            "|   #########                 ######                       #######                   #####            |",
            "|                    #######   #########          ######                #########                     |",
            "|############                                 ############              #####       @                 |",
            "|############                 ##############                ######                       #####        |",
            "|              ~~~   ~~~      #            #                #    #                                    |",
            "|               ~~~~~~        #            #                #    #            ~~~~~   ~~~~            |",
            "|            ~~~~~   ~~~      ##############                #    #              ~~~~~~                |",
            "|                                                           ######                                    |",
            "=======================================================================================================",
    };

    victory = {
            "=========================================================================================================",
            "*           Congratulations the mighty warrior you have managed to escape from the dungeons!            *",
            "=========================================================================================================",

    };
}

rang::fg get_color_for(char c){
    switch (c){
        case 'X':
            return rang::fg::red;
        case '*':
            return rang::fg::green;
        case '#':
            return rang::fg::green;
        case '@':
            return rang::fg::magenta;
        case '.':
            return rang::fg::magenta;
        case '=':
            return rang::fg::green;
        case '|':
            return rang::fg::green;
        case '~':
            return rang::fg::blue;
        default:
            return rang::fg::reset;
    }
}


void Game_map::print_base(){
    for (auto& line : map){
        for(auto& c : line) {
            std::cout << rang::style::dim << rang::bg::black << rang::fgB::green << rang::style::reset << get_color_for(c) << c <<
                      rang::style::reset;
        }
        std::cout << '\n';
    }
}

void Game_map::print_victory(bool* eng_game){
    std::cout << victory.size() << '\n';
    for (auto& line : victory){
        for (auto& c: line){
            std::cout << rang::style::blink << rang::bg::green << rang::fgB::black << rang::style::reset << get_color_for(c) << c <<
                      rang::style::reset;
        }
        std::cout << '\n';
        *eng_game = false;

    }
}

// function that allow to find location of the player on the map, variable i allows to find row and result refers to column
Game_map::Coordinates Game_map::find_player() { // keep an eye on return type it have Game_map:: !!!!!
    const char player = '@';
    size_t x = 0;
    size_t y = 0;
    for (const auto& row : map) {
        const auto result = std::find(row.cbegin(), row.cend(), player);
        if (result < std::end(row))
        {
            y = (result - row.cbegin());
            return {x, y}; // x is column and y is row
        }
        x++;
    }
}
// function that provides coordinates for new move

Game_map::Coordinates Game_map::next_position(Coordinates from, Move_direction direction) {

    // using coord to perform one search to get value for x & y, this is better then:
    // size_t x = find_way().x; size_t y = find_way().y; in this line I am preforming search twice
    auto x = from.x;
    auto y = from.y;

    switch (direction){

        case Move_direction::up :
            return {x - 1,y};
            //break;
        case Move_direction::down :
            return {x + 1, y};
            //break;
        case Move_direction::right :
            return {x, y + 1};
            //break;
        case Move_direction::left :
            return {x, y - 1};
            //break;
    }
}

bool Game_map::is_valid_move(const Game_map::Coordinates to) {
    return map[to.x][to.y] == ' ' || map[to.x][to.y] == '.';
}
bool Game_map::is_victory(const Game_map::Coordinates to){

    return map[to.x][to.y] == 'X';
}
void Game_map::set_position(Coordinates c, char new_Value){
    map[c.x][c.y] = new_Value;
}
void  Game_map::move_player(Move_direction direction, int steps,bool* end_game){
    Game_map::Coordinates current = find_player();
    while (steps-- > 0){
        Coordinates new_Position = next_position(current, direction);
        if (is_victory(new_Position))
            return print_victory(end_game);
        else if(!is_valid_move(new_Position))
            return;
        set_position(current, '.');
        set_position(new_Position, '@');
        current = new_Position;
        print_base();
    }
}


