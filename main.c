#include <stdio.h>
#include "list.h"

int main(void) {
  list_t *checklist = list_alloc();

  for(int i = 0; i < 5; i++)
  {
   list_add_to_back(checklist, i + 10);
  }

  printf("Original List:\n"); 
  list_print(checklist);

  printf("\n\nLength of list is %d", list_length(checklist));

  printf("\n\nAdding 25 to the back:\n");
  list_add_to_back(checklist, 25); 
  list_print(checklist);

  printf("\n\nLength of list is %d", list_length(checklist));

  printf("\n\nAdding 3 to the front:\n");
  list_add_to_front(checklist, 3);
  list_print(checklist);

  printf("\n\nLength of list is %d", list_length(checklist));

  printf("\n\nAdding 73 at index 3:\n");
  list_add_at_index(checklist, 73, 3);
  list_print(checklist);

  printf("\n\nLength of list is %d", list_length(checklist));

  printf("\n\nRemoving element from the back:\n");
  list_remove_from_back(checklist);
  list_print(checklist);

  printf("\n\nLength of list is %d\n", list_length(checklist));

  printf("Removing element from the front:\n");
  list_remove_from_front(checklist);
  list_print(checklist);

  printf("\n\nLength of list is %d", list_length(checklist));

  printf("\n\nChecking if 29 is in the list: %s\n", list_is_in(checklist, 29) ? "true" : "false");

  printf("\n%d was found at index 5\n", list_get_elem_at(checklist, 5));

  printf("\n 3 was found at index %d", list_get_index_of(checklist, 3));

list_print(checklist);

return 0;

}