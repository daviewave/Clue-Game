#include "items.h"


struct Item * create_item(char *item_name, char *item_description)
{
  struct Item *item_ptr = (struct Item *) malloc(sizeof(struct Item));
  
  item_ptr->name = item_name;
  item_ptr->description = item_description;
  item_ptr->next = NULL;
  item_ptr->head = NULL;
  item_ptr->last = NULL;

  return item_ptr;
  free(item_ptr);
}

struct Item* create_linkedlist(char* dummy, char* head_of_LL)
{
  struct Item *item_list_ptr = (struct Item *) malloc(sizeof(struct Item));
  
  item_list_ptr->name = dummy;
  item_list_ptr->description = head_of_LL;
  item_list_ptr->next = NULL;
  item_list_ptr->head = item_list_ptr;
  item_list_ptr->last = item_list_ptr;
  item_list_ptr->last->next = NULL;


  return item_list_ptr;
  free(item_list_ptr);
}


struct Item* add_item(struct Item *item_to_add, struct Item* list_to_add)
{
  struct Item* head_item = list_to_add;
  
  if(head_item->head == NULL)
  {
    return create_linkedlist(item_to_add->name, item_to_add->description);
  }
  
  if(item_to_add == NULL)
  {
    printf("Failed to add to list");
    return NULL;
  }
  head_item->last->next = item_to_add;
  item_to_add->next = NULL;
  head_item->last = item_to_add;
    
  
  return list_to_add;
}

struct Item* drop_item(char* name, struct Item *list, struct Item *list_to_drop)
{
  struct Item *head_ptr = list->head;
  struct Item *previous_item = NULL;
  bool found = false;

  if(strcmp(head_ptr->name, name))
  {
    head_ptr->next = previous_item;
    head_ptr->next = NULL;
    add_item(head_ptr, list_to_drop);

    head_ptr = previous_item;
    return head_ptr;
  }
  
  while(head_ptr != NULL)
  {
    if(strcmp(head_ptr->name, name) == 0)
    {
      found = true;
      break;
    }
    else
    {
      previous_item = head_ptr;
      head_ptr = head_ptr->next;
    }
  }

  if(found == false)
  {
    printf("Item not where you searched for it");
    return NULL;
  }
  else
  {
    previous_item->next = head_ptr->next;
    head_ptr->next = NULL;
    add_item(head_ptr, list_to_drop);
    head_ptr = previous_item; 
    return head_ptr;
  }
}



    




//   item_to_drop = current_list->head;
//   if(item_to_drop != NULL)
//   {
//     current_list->head = item_to_drop->next;
//     if(current_list->head == NULL)
//     {
//       current_list->tail = NULL;
//     }
//   }
//   return item_to_drop;
// }

// struct Item* swap_item(struct Item* current_location, struct Item* drop_location)
// {
//   struct Item* searched = search_list(current_location->name, current_location);
//   bool found = false;
  
//   if(searched == NULL)
//   {
//     printf("This item is is not in your accessible from where your player currently is\n");
//     return NULL;
//   }

//   do{
//     if(strcmp(current_location->name, current_location->name) == 0)
//     {
//       found = true;
//       current_location->next = NULL;
//       do{
//         if(drop_location->next == NULL)
//         {
//           drop_location->next = current_location;
//           //current_location->previous = drop_location;
//           current_location->next = NULL;
//         }
//         drop_location = drop_location->next;

//       }while(drop_location->next != NULL);
//     }
//     current_location = current_location->next;
//   }while(found == false);
//   return NULL;
// }

void add_itemsTo_gameboard(struct Room* gameboard[3][3])
{ 
  srand(time(NULL));
  int choose_spot;
  
  int saver1 = -1, saver2 = -1, saver3 = -1, saver4 = -1, saver5 = -1, saver6 = -1, saver7 = -1, saver8 = -1;
  
  struct Room *room_ptr;
  
  struct Item* item1 = create_item("key", "a dull bronze key");
  struct Item* item2 = create_item("rope", "a long brown rope");
  struct Item* item3 = create_item("gun", "a small platnum pistol");
  struct Item* item4 = create_item("bat", "a heavy long baseball bat");
  struct Item* item5 = create_item("axe", "a sharp rusty axe");
  struct Item* item6 = create_item("trophy", "a big shiny gold trophy");
  struct Item* item7 = create_item("knife", "a small sharp pocket knife");
  struct Item* item8 = create_item("candle", "a small green candle with little wax left");
  struct Item* item9 = create_item("screwdriver", "a yellow and black philips-head screwdriver");
  
  struct Item* items[] = { item1, item2, item3, item4, item5, item6, item7, item8, item9 };

  for(int i = 0; i < 9; i++)
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
          room_ptr = gameboard[0][0];
          room_ptr->item_list = add_item(items[choose_spot], room_ptr->item_list);
          break;

      case 1:
          
          room_ptr = gameboard[0][1];
          room_ptr->item_list = add_item(items[choose_spot], room_ptr->item_list);
          break;
          
      case 2:
          room_ptr = gameboard[0][2];
          room_ptr->item_list = add_item(items[choose_spot], room_ptr->item_list);
          break;
     
      case 3:
          room_ptr = gameboard[1][0];
          room_ptr->item_list = add_item(items[choose_spot], room_ptr->item_list);
          break;
            
      case 4:
          room_ptr = gameboard[1][1];
          room_ptr->item_list = add_item(items[choose_spot], room_ptr->item_list);
          break;
           
      case 5:
          room_ptr = gameboard[1][2];
          room_ptr->item_list = add_item(items[choose_spot], room_ptr->item_list);
          break;

      case 6:
          room_ptr = gameboard[2][0];
          room_ptr->item_list = add_item(items[choose_spot], room_ptr->item_list);
          break;
   
      case 7:
          room_ptr = gameboard[2][1];
          room_ptr->item_list = add_item(items[choose_spot], room_ptr->item_list);
          break;
            
      case 8:
          room_ptr = gameboard[2][2];
          room_ptr->item_list = add_item(items[choose_spot], room_ptr->item_list);
          break;
        
      default:
          break;
    }
  }
}

char * item_name(struct Item *item_pointer)
{
  return item_pointer->name;
} 

char * item_description(struct Item *item_pointer)
{
  return item_pointer->description;
} 

struct Item * item_next(struct Item *item_pointer)
{
  return item_pointer->next;
}


