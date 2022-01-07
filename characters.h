#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef CH_HEAD
#define CH_HEAD


struct Avatar{
  char *name;             //The name of the avatar       
  struct Item* inventory;       //Points to the array of items of the user (inventory)
  struct Room *avatar_room;     //Points to the avatars current room  
};

//Creates a new avatar that has memory dynamically allocated for all parameters
struct Avatar * create_avatar(char *avatar_name, struct Item *list);

//Moves the avatar from the current room to the user specified next room
void move_avatar(struct Avatar *current, struct Room *next_room);

void add_avatarsTo_board(struct Room* gameboard[3][3]);

struct Avatar *add_user_avatar(struct Room* gameboard[3][3]);

void look(struct Room *current);


#endif