#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "characters.h"

#ifndef ROOM_HEAD
#define ROOM_HEAD


struct Room{
  char *name;
  char *description;             
  int place_on_gameboard; 
  struct Item* item_list;
  struct Avatar *avatar;
  struct Room *north;           
  struct Room *south;
  struct Room *east;             
  struct Room *west;
};

struct Room * create_room(char* name, int place_on_gameboard, char *room_description, struct Item* list);

void set_north(struct Room *current, struct Room *north_current);

void set_south(struct Room *current, struct Room *south_current);

void set_east(struct Room *current, struct Room *east_current);

void set_west(struct Room *current, struct Room *west_current);

void create_gameboard(struct Room* gameboard[3][3]);

void print_gameboard(struct Room* array[3][3]);

struct Room* connect_rooms(struct Room* gameboard[3][3]);





#endif