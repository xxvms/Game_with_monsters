//
// Created by tombr on 09/09/2017.
//

#ifndef GAME_WITH_MONSTERS_PLAYER_H
#define GAME_WITH_MONSTERS_PLAYER_H

#include <random>


class Player {
private:
    int moves;
    double life;
    double attackX;
    std::random_device random_dev;

public:
    Player(int moves, double life, double attackX);

    double read_power();
    double attack();
    double defense(double Monster_attack);

    template <class T>
    T random_value_generator(T min_value, T max_Value);
};


#endif //GAME_WITH_MONSTERS_PLAYER_H
