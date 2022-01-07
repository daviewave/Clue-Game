#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "items.h"
#include "rooms.h"
#include "characters.h"

static int get_user_input();
static int accept_user_input_and_execute();


struct Answer{
  struct Room* room;
  struct Item* item;
  struct Avatar* avatar;
};

struct Answer* choose_random_answer(struct Room* gameboard[3][3])
{
  srand(time(NULL));
  int room_row, room_column, item_row, item_column, avatar_row, avatar_column;
  room_row = rand() % 3;
  room_column = rand() % 3;
  item_row = rand() % 3;
  item_column = rand() % 3;
  avatar_row = rand() % 3;
  avatar_column = rand() % 3;

  if(gameboard[avatar_row][avatar_column]->avatar == NULL)
  {
    do{
      avatar_row = rand() % 3;
      avatar_column = rand() % 3;

    }while(gameboard[avatar_row][avatar_column]->avatar == NULL);
  }

  struct Answer *ptr = (struct Answer *) malloc(sizeof(struct Answer));
  ptr->room = gameboard[room_row][room_row];
  ptr->item = gameboard[item_row][item_column]->item_list->last;
  ptr->avatar = gameboard[avatar_row][avatar_column]->avatar;

  return ptr;
  free(ptr);
}

void list_commands()
{
  char* commands[] = {"\n\n\n1. Enter: 'help' and a list of all executable commends will appear\n\n",
                        "2. Enter: 'list' and a list list of all the rooms, all the items, and all the avatars will appear\n\n", 
                        "3. Enter: 'look' and you will be told the room you are currently in, all the items in your current room, all the avatars in the room, each room you are able to move into from your current room\n\n",
                        "4. Enter: 'go DIRECTION' where 'DIRECTION' is either north, south, east, or west. \n\n", 
                        "5. Enter: 'take ITEM' to add an item to your inventory where 'ITEM' is the name of the item you want to pick up. \n\n", 
                        "6. Enter: 'drop ITEM' to remove an item out of your inventory where 'ITEM' is the name of the item you want to remove.\n\n", 
                        "7. Enter 'clue' to attempt a guess at the correct combination of Room, Item, and Avatar and win the game. Be careful, you only have incorrect guesses or you lose.\n\n", 
                      };
  for(int i = 0; i < 7; i++)
  {
    printf("%s", commands[i]);
  }

}



static struct Room* game_board[3][3];
static char input[30];

int main(void) 
{
  create_gameboard(game_board);  // randomly sets the location of each room on the gameboard
  add_itemsTo_gameboard(game_board); //randomly adds each item to each room on the game board
  add_avatarsTo_board(game_board);
  choose_random_answer(game_board);
  static struct Avatar* user;
  user = create_avatar("Player", create_linkedlist("dummy", "dummy"));
  
  int guesses = 0;
  do
  {
    (get_user_input() && accept_user_input_and_execute());
    
    if(strcmp(input, "clue") == 0)
    {
      guesses++;
    }
  }while(guesses < 10);
  printf("Game Over\n You lose");
  return 0;
}

void print_gameboard(struct Room* gameboard[3][3])
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(gameboard[i][j] == NULL)
      {
        printf("NULL");
      }
      printf("\n\n[%s]", gameboard[i][j]->description);
      printf("\nItems in %s are:\n %s", gameboard[i][j]->description, gameboard[i][j]->item_list->last->name);
      if(gameboard[i][j]->avatar != NULL)
      {
        printf("\nAvatars in %s are:\n %s", gameboard[i][j]->description, gameboard[i][j]->avatar->name);
      }
      printf("     ");
    }
    printf("\n");
  }
}



static int get_user_input()
{
  printf("\n\n\nEnter Verb: \n");
  return fgets(input, sizeof(input), stdin) != NULL;
}

static int accept_user_input_and_execute()
{
  static struct Avatar* user;
  static struct Item* item;
  int guesses = 0;

  char* verbs = strtok(input, " \n"); 
  char* nouns =  strtok(NULL, " \n"); 

  if(verbs != NULL)
  {
    if(strcmp(verbs, "help") == 0)
    {
      list_commands(); //Lists all the possible commands
    }
    else if(strcmp(verbs, "list") == 0)
    {
      print_gameboard(game_board);
    }
    else if(strcmp(verbs, "look") == 0)
    {
      look(user->avatar_room);
    }
    else if(strcmp(verbs, "go") == 0)
    {
      if(strcmp(nouns, "north"))
      {
        move_avatar(user, user->avatar_room->north);
      }
      if(strcmp(nouns, "south"))
      {
        move_avatar(user, user->avatar_room->south);
      }
      if(strcmp(nouns, "east"))
      {
        move_avatar(user, user->avatar_room->east);
      }
      if(strcmp(nouns, "west"))
      {
        move_avatar(user, user->avatar_room->west);
      }
      else
      {
        printf("You did not enter a valid direction after 'go'");
      }
    }
    else if(strcmp(verbs, "take") == 0)
    {
      add_item(item, user->inventory);
    }
    else if(strcmp(verbs, "drop") == 0)
    {
      drop_item(item->name, user->inventory, user->avatar_room->item_list);
    }
    else if(strcmp(verbs, "clue") == 0)
    {
      guesses++;
      struct Answer* answer = choose_random_answer(game_board);
      if(strcmp(nouns, answer->room->description) == 0)
      {
        printf("enter your item guess\n");
        nouns = strtok(NULL, " \n"); 
        if(strcmp(nouns, answer->item->name) == 0)
        {
          printf("enter your item guess\n");
          nouns = strtok(NULL, " \n"); 
          if(strcmp(nouns, answer->item->name) == 0)
          {
            printf("You Win!\n Game Over");
            return 0;
          }
        }
      }
    }
    else
    {
      printf("Not a valid command. If you need a list of all commands enter 'Help'");
    }
  }
  return 1;
}

