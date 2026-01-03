 

// - Class: A class is a blueprint or template that defines attributes (data) and methods (functions) for creating objects.  

// - Object: An object is an instance of a class that contains actual values for the attributes and can use the methods defined in the class.  
#include <stdio.h>

// Define pokemon first
struct pokemon {
    int hp;
    int attack;
    int speed;
};

// Now legendary_pokemon can use pokemon
struct legendary_pokemon {
    int ability;
    int specialattack;
    struct pokemon pikachu;  // nested struct
};

int main() {
    
    struct legendary_pokemon mewtwo;

    mewtwo.ability = 99;
    mewtwo.specialattack = 150;
    mewtwo.pikachu.hp = 100;
    mewtwo.pikachu.attack = 80;
    mewtwo.pikachu.speed = 120;

    printf("Legendary ability: %d\n", mewtwo.ability);
    printf("Special attack: %d\n", mewtwo.specialattack);
    printf("Pikachu HP: %d\n", mewtwo.pikachu.hp);

    return 0;
}