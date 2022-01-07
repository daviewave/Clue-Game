#include "rooms.h"
#include "items.h"

#define MAX 3
#define DUMMY_NAME "dummy"


struct Room * create_room(char* name, int place_on_gameboard, char *room_description, struct Item* list)
{
  struct Room *room_ptr;
  room_ptr = (struct Room *) malloc(sizeof(struct Room));

  room_ptr->name = name;
  room_ptr->description = room_description;
  room_ptr->place_on_gameboard = place_on_gameboard;
  room_ptr->item_list = list;
  room_ptr->avatar = NULL;
  room_ptr->north = NULL;
  room_ptr->south = NULL;
  room_ptr->east = NULL;
  room_ptr->west = NULL;

  
  return room_ptr;
  free(room_ptr);
}

void set_north(struct Room *current, struct Room *north_of_current)
{
  current->north = north_of_current;
  north_of_current->south = current;
}

void set_south(struct Room *current, struct Room *south_of_current)
{
  current->south = south_of_current;
  south_of_current->north = current;
}

void set_east(struct Room *current, struct Room *east_of_current)
{
  current->east = east_of_current;
  east_of_current->west = current;
}

void set_west(struct Room *current, struct Room *west_of_current)
{
  current->west = west_of_current;
  west_of_current->east = current;
}

void create_gameboard(struct Room* gameboard[3][3])
{
  srand(time(NULL));

  int choose_spot;
  int saver1 = -1, saver2 = -1, saver3 = -1, saver4 = -1, saver5 = -1, saver6 = -1, saver7 = -1, saver8 = -1;

  
  struct Room *room1 = create_room("You are now in the kitchen. There is an oven with a microwave above it, a toaster on the counter, and a large stove for cooking." ,0, "Kitchen", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Room *room2 = create_room("You are in the garage. There are 3 expensive cars and lots of tools" ,1,"Garage", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Room *room3 = create_room("You are in the living room. The couches are black and are super comfy. There is a flatscreen TV with a fireplace underneath" , 2, "Living Room", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Room *room4 = create_room("You are in the office. There are several computers, a gaming consonle, and a desk with what appears to be recently used", 3, "Office", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Room *room5 = create_room( "You are in the basement. It is very dark and the lights are broken. There appears to be a workbench in the corner of the room and a lawnmower in the middle.", 4, "Basement", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Room *room6 = create_room( "You are in the bedroom. There is one king size bed, a large bedset with a big mirrior in the center, and 2 dressers for storing clothes.", 5, "Bedroom", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Room *room7 = create_room("You are in the Dining Room. there is is a long  table that appears to be set with plates and forks, but no knives.", 6, "Dining Room", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Room *room8 = create_room( "You are in the attic. It is very musty and smells gross. There are many antiques around the room and a pictures are all over the wall", 7, "Attic", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Room *room9 = create_room( "You are in the laundry room. The room is small. There is a washing and drying machine and all the chemicals needed for cleaning and a tower of baskets for clean clothes.", 8, "Laundry Room", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  
  struct Room* all_rooms[9] = { room1, room2, room3, room4, room5, room6, room7, room8, room9 };

  
  for(int i = 0; i<9; i++)
  {
    do{
      choose_spot = rand() % 9;

    }while(choose_spot == saver1 || choose_spot == saver2 || choose_spot == saver3 || choose_spot == saver4 || choose_spot == saver5 || choose_spot == saver6 || choose_spot == saver7 || choose_spot == saver8);
    
    if(i == 0)
    {
      saver1 = choose_spot;
    }
    if(i == 1)
    {
      saver2 = choose_spot;
    }
    if(i == 2)
    {
      saver3 = choose_spot;
    }
    if(i == 3)
    {
      saver4 = choose_spot;
    }
    if(i == 4)
    {
      saver5 = choose_spot;
    }
    if(i == 5)
    {
      saver6 = choose_spot;
    }
    if(i == 6)
    {
      saver7 = choose_spot;
    }
    if(i == 7)
    {
      saver8 = choose_spot;
    }

    switch(i)
    {          
      case 0:
        for(int x = 0; x < 9; x++)
        {
          if(all_rooms[x]->place_on_gameboard == choose_spot)
          {
            gameboard[0][0] = all_rooms[x];
            break;
          }
        }
        break;

      case 1:
        for(int x = 0; x < 9; x++)
        {
          if(all_rooms[x]->place_on_gameboard == choose_spot)
          {
            gameboard[0][1] = all_rooms[x];
            break;
          }
        }
        break;
          
      case 2:
        for(int x = 0; x < 9; x++)
        {
          if(all_rooms[x]->place_on_gameboard == choose_spot)
          {
            gameboard[0][2] = all_rooms[x];
            break;
          }
        }
        break;
     
      case 3:
        for(int x = 0; x < 9; x++)
        {
          if(all_rooms[x]->place_on_gameboard == choose_spot)
          {
            gameboard[1][0] = all_rooms[x];
            break;            
          }
        }
        break;
            
      case 4:
        for(int x = 0; x < 9; x++)
        {
          if(all_rooms[x]->place_on_gameboard == choose_spot)
          {
            gameboard[1][1] = all_rooms[x];
            break;
          }
        }
        break;
           
      case 5:
        for(int x = 0; x < 9; x++)
        {
          if(all_rooms[x]->place_on_gameboard == choose_spot)
          {
            gameboard[1][2] = all_rooms[x];
            break;
          }
        }
        break;

      case 6:
        for(int x = 0; x < 9; x++)
        {
          if(all_rooms[x]->place_on_gameboard == choose_spot)
          {
            gameboard[2][0] = all_rooms[x];
            break;
          }
        }
        break;
   
      case 7:
        for(int x = 0; x < 9; x++)
        {
          if(all_rooms[x]->place_on_gameboard == choose_spot)
          {
            gameboard[2][1] = all_rooms[x];
            break;
          }
        }
        break;
            
      case 8:
        for(int x = 0; x < 9; x++)
        {
          if(all_rooms[x]->place_on_gameboard == choose_spot)
          {
            gameboard[2][2] = all_rooms[x];
            break;
          }
        }
        break;
        
      default:
        break;
    } 
  }
  connect_rooms(gameboard);
}
 
// void print_gameboard(struct Room* gameboard[3][3])
// {
//   for(int i = 0; i < 3; i++)
//   {
//     for(int j = 0; j < 3; j++)
//     {
//       if(gameboard[i][j] == NULL)
//       {
//         printf("NULL");
//       }
//       printf("[%s]", gameboard[i][j]->description);
//       printf("%s", gameboard[i][j]->item_list->last->name);
//       if(gameboard[i][j]->avatar != NULL)
//       {
//         printf("%s", gameboard[i][j]->avatar->name);
//       }
//       printf("     ");
//     }
//     printf("\n");
//   }
// }

struct Room* connect_rooms(struct Room* gameboard[3][3])
{
  struct Room *room_ptr;
  for(int i = 0; i < MAX; i++)
  {
    for(int j = 0; j < MAX; j++)
    {
      if(i - 1 < 0)
      {
        if(j - 1 < 0)
        {
          room_ptr = gameboard[0][0];
          room_ptr->north = NULL;
          set_south(room_ptr,  gameboard[1][0]);
          set_east(room_ptr, gameboard[0][1]);
          room_ptr->west = NULL;
        }
        else if(j + 1 > 2)
        {
          room_ptr = gameboard[0][2];
          room_ptr->north = NULL;
          set_south(room_ptr, gameboard[1][2]);
          room_ptr->east = NULL;
          set_west(room_ptr, gameboard[0][1]);
        }
        else
        {
          room_ptr = gameboard[0][1];
          room_ptr->north = NULL;
          set_south(room_ptr, gameboard[1][1]);
          set_east(room_ptr, gameboard[0][2]);
          set_west(room_ptr, gameboard[0][0]);
        }
      }
      else if(i + 1 > 2)
      {
        if(j - 1 < 0)
        {
          room_ptr = gameboard[2][0];
          set_north(room_ptr, gameboard[1][0]);
          room_ptr->south = NULL;
          set_east(room_ptr, gameboard[2][1]);
          room_ptr->south = NULL;
        }
        else if(j + 1 > 2)
        {
          room_ptr = gameboard[2][2];
          set_north(room_ptr, gameboard[1][2]);
          room_ptr->south = NULL;
          room_ptr->east = NULL;
          set_west(room_ptr, gameboard[2][1]);
        }
        else
        {
          room_ptr = gameboard[2][1];
          set_north(room_ptr, gameboard[1][1]);
          room_ptr->south = NULL;
          set_east(room_ptr, gameboard[2][2]);
          set_west(room_ptr, gameboard[2][0]);
        }
      }
      else  //Neither north nor south are out of array bounds
      {
        if(i == 1 && j == 0)
        {
          room_ptr = gameboard[1][0];
          set_north(room_ptr, gameboard[0][0]);
          set_south(room_ptr, gameboard[2][0]);
          set_east(room_ptr, gameboard[1][1]);
          room_ptr->west = NULL;
        }
        else if(i == 1 && j == 1)
        {
          room_ptr = gameboard[1][1];
          set_north(room_ptr, gameboard[0][1]);
          set_south(room_ptr, gameboard[2][1]);
          set_east(room_ptr, gameboard[1][2]);
          set_west(room_ptr, gameboard[1][0]);
        }
        else
        {
          room_ptr = gameboard[1][2];
          set_north(room_ptr, gameboard[0][2]);
          set_south(room_ptr, gameboard[2][2]);
          room_ptr->east = NULL;
          set_west(room_ptr, gameboard[1][1]);
        }
      }
    }
  }
  return room_ptr;
}
