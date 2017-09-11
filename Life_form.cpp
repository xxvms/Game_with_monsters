//
// Created by tombr on 11/09/2017.
//

#include "Life_form.h"

Life_form::Life_form(int moves, double life, double attackX){}

double Life_form::read_power() {
    return life;
}

// function that generates random value in range 1- Max attack value that represetn strenght of an attack
double Life_form::attack() {
    double attack_strenght = random_value_generator(1.0, attackX);
    return attack_strenght;
}

// Function that the only job is to generate random values for my other functions - attack and defence
template <class T>
T Life_form::random_value_generator(T min_Value, T max_Value)  {
    std::default_random_engine random_value(random_dev());
    std::uniform_real_distribution<T> values(min_Value, max_Value);
    double values_to_return =  values(random_value);
    return values_to_return;
}

// Function that responds to the attack by lowering life by amount of attack and chance of avoiding attack all together
double Life_form::defense(double Monster_attack) {

    double percent = (Monster_attack / 100);



    return life - Monster_attack;
}
