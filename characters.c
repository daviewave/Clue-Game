#include "characters.h"
#include "items.h"

#define DUMMY_NAME "dummy"

struct Avatar * create_avatar(char *avatar_name, struct Item *list)
{ 
  struct Avatar *avatar_ptr;
  avatar_ptr = (struct Avatar *) malloc(sizeof(struct Avatar));

  avatar_ptr->name = avatar_name;
  avatar_ptr->inventory = list;
  avatar_ptr->avatar_room = NULL;

  return avatar_ptr;
  free(avatar_ptr);
}

//Moves the avatar from the current room to the user specified next room
void move_avatar(struct Avatar *current, struct Room *next_room)
{
  current->avatar_room = next_room;
}

void add_avatarsTo_board(struct Room* gameboard[3][3])
{
  srand(time(NULL));
  int choose_spot;
  int saver1 = -1, saver2 = -1, saver3 = -1, saver4 = -1, saver5 = -1;

  struct Avatar *avatar_ptr;
  struct Room *room_ptr;
  
  struct Avatar *avatar1 = create_avatar("Plum", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Avatar *avatar2 = create_avatar("Peacock", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Avatar *avatar3 = create_avatar("Scarlet", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Avatar *avatar4 = create_avatar("Cook", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Avatar *avatar5 = create_avatar("Maid", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  struct Avatar *avatar6 = create_avatar("Butler", create_linkedlist(DUMMY_NAME, DUMMY_NAME));

  struct Avatar* avatars[] = { avatar1, avatar2, avatar3, avatar4, avatar5, avatar6 };

  for(int i = 0; i < 6; i++)
  {
    do{
      choose_spot = rand() % 9;

    }while(choose_spot == saver1 || choose_spot == saver2 || choose_spot == saver3 || choose_spot == saver4 || choose_spot == saver5);
    
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
    // printf("I is: %i\n", i);
    // printf("Rand Num is: %i\n", choose_spot);
    // printf("saver 1: %i\n", saver1);
    switch (choose_spot)
    {          
      case 0:
        avatar_ptr = avatars[i];
        avatar_ptr->avatar_room = gameboard[0][0];
        room_ptr = gameboard[0][0];
        room_ptr->avatar = avatars[i];
        break;

      case 1:
        avatar_ptr = avatars[i];
        avatar_ptr->avatar_room = gameboard[0][1];
        room_ptr = gameboard[0][1];
        room_ptr->avatar = avatars[i];
        break;
          
      case 2:
        avatar_ptr = avatars[i];
        avatar_ptr->avatar_room = gameboard[0][2];
        room_ptr = gameboard[0][2];
        room_ptr->avatar = avatars[i];
        break;
     
      case 3:
        avatar_ptr = avatars[i];
        avatar_ptr->avatar_room = gameboard[1][0];
        room_ptr = gameboard[1][0];
        room_ptr->avatar = avatars[i];
        break;
            
      case 4:
        avatar_ptr = avatars[i];
        avatar_ptr->avatar_room = gameboard[1][1];
        room_ptr = gameboard[1][1];
        room_ptr->avatar = avatars[i];
        break;
           
      case 5:
        avatar_ptr = avatars[i];
        avatar_ptr->avatar_room = gameboard[1][2];
        room_ptr = gameboard[1][2];
        room_ptr->avatar = avatars[i];
        break;

      case 6:
        avatar_ptr = avatars[i];
        avatar_ptr->avatar_room = gameboard[2][0];
        room_ptr = gameboard[2][0];
        room_ptr->avatar = avatars[i];
        break;
   
      case 7:
        avatar_ptr = avatars[i];
        avatar_ptr->avatar_room = gameboard[2][1];
        room_ptr = gameboard[2][1];
        room_ptr->avatar = avatars[i];
        break;
            
      case 8:
        avatar_ptr = avatars[i];
        avatar_ptr->avatar_room = gameboard[2][2];
        room_ptr = gameboard[2][2];
        room_ptr->avatar = avatars[i];
        break;
        
      default:
        break;
    }
  }
}


struct Avatar *add_user_avatar(struct Room* gameboard[3][3])
{ 
  static struct Avatar* user;
  user = create_avatar("Player", create_linkedlist(DUMMY_NAME, DUMMY_NAME));
  user->avatar_room = gameboard[1][1];
  
  printf("\nYour player will start here: %s\n\n", gameboard[1][1]->description);
  printf("%s", gameboard[1][1]->name);
  
  return user;
}

void look(struct Room* current)
{
  printf("Current Room is: %s", current->description);
  do{
    printf("Items in room: %s", current->item_list->name);
    current->item_list = current->item_list->next;

  }while(current->item_list->next != NULL);
  printf("Avatars in room: %s", current->avatar->name);
}