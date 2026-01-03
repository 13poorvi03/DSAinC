// structures is user defined data type 

// declaration 
// struct employee{
// int emp_id;
// char name;
// float salary;
// };

#include<stdio.h>
int main(){
struct pokemon{    //user defined data type
    int hp;         // this all are a properties of pokemon 
    int speed;      //in this we store same data of pokemeon
    int attack;     // in this we can use differt type of data type
    char tier;   // S,A,B,C,D
};
struct pokemon pikachu;
printf("enter the pikachu attack : ");
scanf("%d",&pikachu.attack);
// pikachu.attack=60;
pikachu.speed=100;
pikachu.tier ='A';
  printf("%d\n",pikachu.attack);

  //intialization 
struct pokemon charizard;
    charizard.attack= 130;
    charizard.hp=80;
    charizard.speed=90;
    charizard.tier='S';
  printf("%c\n",charizard.tier);

return 0;
}