#include <iostream>
#include "Game_map.h"
#include "Cmove_direction.h"
#include "rang.hpp"

int menu(std::string &choice) {
    if (choice == "up") return 1;
    if (choice == "down") return 2;
    if (choice == "right") return 3;
    if (choice == "left") return 4;
}


int steps(){
    int steps = 0;
    std::cout << "Please provide number of steps min 1 - max 5: ";
    std::cin >> steps;
    if (steps > 0 && steps < 6)
    {

        return steps;
    } else return 5;

};

bool game_over = true;
bool* pGame_over = &game_over;

int main() {

    Game_map first;

    first.print_base();
    first.find_player();

    do {
        std::cout << "Please provide direction (up/down/right/left): ";
        std::string choice;
        std::cin >> choice;

        switch (menu(choice)) {

            case 1:{
                std::cout << "Going Up " << '\n';
                Cmove_direction direction_up;
                direction_up = static_cast<Cmove_direction>(0);
                auto steps_to_take = steps();
                first.move_player(direction_up, steps_to_take, pGame_over);
                break;
            }

            case 2:{
                std::cout << "Going Down" << '\n';
                Cmove_direction direction_down;
                direction_down= static_cast<Cmove_direction>(1);
                auto steps_to_take = steps();
                first.move_player(direction_down, steps_to_take, pGame_over);
                break;
            }

            case 3:{
                std::cout << "Going Right" << '\n';
                Cmove_direction direction_right;
                direction_right = static_cast<Cmove_direction>(2);
                auto steps_to_take = steps();
                first.move_player(direction_right, steps_to_take, pGame_over);
                break;
            }

            case 4:{
                std::cout << "Going Left" << '\n';
                Cmove_direction direction_left;
                direction_left = static_cast<Cmove_direction>(3);
                auto steps_to_take = steps();
                first.move_player(direction_left, steps_to_take, pGame_over);
                break;
            }

            default:
                std::cout << "Not going :( select valid choice!" << '\n';
                break;
        }
    } while (*pGame_over); //!first.print_victory() == 1);

    return 0;
}



