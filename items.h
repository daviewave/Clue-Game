#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "rooms.h"

#ifndef ITEM_HEAD
#define ITEM_HEAD

struct Item{
  char *name;               //Name of the item 
  char *description;        //Description of the item
  struct Item *next;
  struct Item *head;
  struct Item *last;
};







struct Item* create_linkedlist(char* dummy, char* head_of_LL);

struct Item* drop_item(char* name, struct Item *list, struct Item *list_to_drop);



//Creates an item while dynamically allocating space for all of the struct req's
struct Item * create_item(char *item_name, char *item_description);

struct Item* add_item(struct Item *item_to_add, struct Item* list_to_add);

struct Item* search_list(char* name, struct Item *head_item, struct Item *list_to_drop);

void add_itemsTo_gameboard(struct Room* gameboard[3][3]);

char * item_name(struct Item *item_pointer);

char * item_description(struct Item *item_pointer); 

struct Item * item_next(struct Item *item_pointer);

#endif