// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
 
list_t *list_alloc()
{ 
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list -> head = NULL;
  return list;
  //return NULL; 
}

node_t *node_alloc(elem value)
{
  node_t* node = malloc(sizeof(node_t));
  node ->next = NULL; 
  node -> value = value;
  return node;
}

void list_free(list_t *l)
{  
  free(l);
  return;
}

void node_free(node_t *node)
{  
  free(node);
  return;
}

void list_print(list_t *l)
{
  node_t *current = l -> head;
  if(current == NULL)
  {
    printf("empty");
  }
  while(current != NULL)
  {
    printf("%d", current->value); 
    current = current -> next;
  }
   
}

int list_length(list_t *l)
{
  node_t *current = l->head;
  int count = 0; 
  while(current != NULL)
  {
    count++; 
    current = current->next;
  }
   //printf("%d", count);
  return count;
}

void list_add_to_back(list_t *l, elem value)
{
   node_t *newNode = node_alloc(value);
   node_t *current = l->head;
   if(l->head == NULL)
   {
     l->head = newNode;
   }
   else
   {
     while(current->next != NULL)
     {
       current = current->next;
     }
     current->next = newNode;
   }
}

void list_add_to_front(list_t *l, elem value) {
  node_t* newNode = node_alloc(value);
  if(l -> head == NULL)
  {
    newNode->next = l->head;
    l -> head = newNode;
    newNode->next = NULL;
  }
  else
  {
    newNode->next = l->head;
    l->head = newNode;
  }
}

void list_add_at_index(list_t *l, elem value, int index)
{
  int i = 0; 
  node_t* newNode = node_alloc(value);
  node_t *temp = node_alloc(value);
  node_t *current = l->head;

  if(index == 0)
  {
    temp->next = l->head; 
    newNode->next = temp->next; 
    l->head = newNode;
  }
  else
  {
    while(i < index - 1)
    {
      current = current->next;
      i++;
    }
    newNode->next = temp; 
    temp->next = current->next;
    newNode->next = temp->next;
    current->next = newNode;
  }
}

elem list_remove_from_back(list_t *l)
{ 
  elem value; 
  node_t *current = l->head;
  int i = 0; 
  if(l->head == NULL)
  {
    printf("list is empty");
  }
  else
  {
    while(i < (list_length(l)-2))
    {
      current = current->next;
      i++; 
    }
    value = current->next->value;
    node_free(current->next);
    current->next = NULL;
  }
  return value; 
}
elem list_remove_from_front(list_t *l)
{
   elem value; 
   if(l->head == NULL)
   {
     printf("list is empty");
   }
   else
   {
     node_t *current = l->head;
     value = current->value;
     l->head = l->head->next;
     node_free(current);
   }
   return value;
}

elem list_remove_at_index(list_t *l, int index)
{ 
  int i = 0;
  elem value;
  if(l->head == NULL)
  {
    printf("list is empty");
  }
  else if(index == 0)
  {
    list_remove_from_front(l);
  }
  else if(index == (list_length(l) - 1))
  {
    list_remove_from_back(l);
  }
  else if(index >= list_length(l))
  {
    printf("index is out of range");
    return -1;
  }
  else
  {
    node_t *current = l->head;
    node_t *temp = node_alloc(value);
    while(current != NULL && i != index - 1)
    {
      current = current->next;
      i++;
    }
    value = current->next->value;
    temp = current->next->next;
    node_free(current->next);
    current->next = temp;
  }
  return value;
}

bool list_is_in(list_t *l, elem value)
{
  node_t *current = l->head;
  while(current != NULL)
  {
    if(value == current->value)
    {
      return true;
    }
    current = current->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index)
{
  int i = 0; 
  elem value;
  if(l->head == NULL)
  {
    printf("list is empty");
  }
  else if(index >= list_length(l))
  {
    printf("index out of range");
    return -1; 
  }
  else
  {
    node_t *current = l->head; 
    while(current != NULL && i != index - 1)
    {
      current = current->next;
      i++;
    }
    value = current->next->value;
  }
  return value;
}

int list_get_index_of(list_t *l, elem value)
{
  int i = 0;
  node_t *current = l->head;
  if(l->head == NULL)
  {
    printf("list is empty");
  }
  while(i < list_length(l))
  {
    if(value == current->value)
    {
      return i;
    }
    current = current->next;
    i++;
  }
  printf("element not found");
  return -1; 
}