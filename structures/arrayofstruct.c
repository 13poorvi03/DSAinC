#include<stdio.h>
#include<string.h>
int main(){
   typedef struct pokemon{
    int hp; 
    int speed; 
    int attack;
    char tier;
    char name[15];
   }pokemon;

   pokemon arr[3];
   
   strcpy(arr[0].name,"charizard");
   arr[0].attack = 50;
   arr[0].hp =200;
   arr[0].speed=50;
   arr[0].tier='A';
    

   strcpy(arr[1].name,"pikachu");
   arr[1].attack = 60;
   arr[1].hp =500;
   arr[1].speed=80;
   arr[1].tier='S';
   

   strcpy(arr[2].name,"mintwo");
   arr[2].attack = 30;
   arr[2].hp =100;
   arr[2].speed=40;
   arr[2].tier='B';
   
   
   for(int i=0; i<3; i++){
    printf("%d\n",arr[i].attack);
    printf("%d\n",arr[i].hp);
    printf("%d\n",arr[i].speed);
    printf("%c\n",arr[i].tier);
    printf("%s\n",arr[i].name);
    
   }
    return 0;
}