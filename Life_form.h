//
// Created by tombr on 11/09/2017.
//

#ifndef GAME_WITH_MONSTERS_LIFE_FORM_H
#define GAME_WITH_MONSTERS_LIFE_FORM_H


#include <random>

class Life_form : public Life_form {
private:
    int moves;
    double life;
    double attackX;
    std::random_device random_dev;
public:
    Life_form(int moves, double life, double attackX);

    double read_power();
    double attack();
    double defense(double Monster_attack);

    template <class T>
    T random_value_generator(T min_value, T max_Value);

};


#endif //GAME_WITH_MONSTERS_LIFE_FORM_H
