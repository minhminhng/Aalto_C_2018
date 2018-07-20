#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "zoo.h"



int init_animal(struct animal *as, const char *p_id, const char *p_name, const char *p_species,	unsigned char p_age, struct date p_entrydate)
{
	// Check validity of ID
	if (strlen(p_id) > 6){
		// free(newdate);
		return 0;
	}
	as -> name = malloc(sizeof(char) * (strlen(p_name) + 1));
	if (as -> name == NULL){
		free(as);
		return 0;
	}
	
	as -> species = malloc(sizeof(char) * (strlen(p_species) + 1));
	if (as -> species == NULL) {
		free(as);
		return 0;
	}
	
	strcpy(as -> id, p_id);
	strcpy(as -> name, p_name);
	strcpy(as -> species, p_species);
	as -> age = p_age;
	as -> entrydate = p_entrydate;
	
	return 1;
}

/* Add a new animal to a dynamic array.
 * (Resize the array as needed). All content of the new structure is copied.
 * 
 * Parameters:
 * array: start of an dynamic array (may be NULL, if array is empty)
 * length: current length of the array (number of entries)
 * newanimal: new animal to be added, all fields need to be copied.
 * 
 * Returns: pointer to the array after adding the new item
 */
struct animal *add_record(struct animal *array, unsigned int size, struct animal newanimal)
{
	struct animal *newarray = realloc(array, sizeof(struct animal) * (size + 1));
	
	// Check the validity 
	if (newarray == NULL){
		printf("Failed");
		free(array);
		return NULL;
	}
	
	init_animal(&newarray[size], newanimal.id, newanimal.name, 
			newanimal.species, newanimal.age, newanimal.entrydate);
	
	return newarray;
}

int main()
{
    /* Feel free to modify
     * for example function for printing the current array content is useful */

    struct animal a1;
    struct date a1date = {1, 1, 1924};
    if (init_animal(&a1, "123456", "Winnie-the-Pooh", "Bear", 94, a1date )) {
        printf("Initialization succeeded\n");
    } else {
        printf("Initialization failed\n");
    }
    
    struct animal zoo[] = {
        { "123456", "Winnie-the-Pooh", "Bear", 94, {1,1,1924} },
        { "555666", "Eeyore", "Donkey", 92, {1,1,1926} },
        { "773466", "Piglet", "Very Small Animal", 30, {31, 12, 2015} },
        { "234567", "Roo", "Kangaroo", 5, {31, 12, 2015} }
    };
    
    struct animal *array = NULL;
    unsigned int len = 0;
  
   for (unsigned int i = 0; i < sizeof(zoo) / sizeof(struct animal); i++) {
        struct animal *newarray = add_record(array, len, zoo[i]);
        if (!newarray) {
            exit(EXIT_FAILURE);
        }
        len++;
        array = newarray;
    }

    for (unsigned int i = 0; i < len; i++) {
      printf("%s: %s (%s)\n", array[i].id, array[i].name,
	     array[i].species);
    }
    
    return 0;
}
