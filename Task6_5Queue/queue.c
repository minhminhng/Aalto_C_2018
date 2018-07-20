#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

int enqueue(struct studentqueue *q, const char *name)
{
	struct studentqueue *current = q;
	//struct studentqueue *newStudent = 
	

	while ((current -> next) != NULL){
		current = current -> next;		
	}	
	
	current -> next = malloc(sizeof(struct studentqueue));
	if (current -> next == NULL){
		return 0;
	}
	current = current -> next;
	current -> name = malloc(sizeof(char) * (strlen(name) + 1));
	if ((current -> name) == NULL){
		free(current -> name);
		free(current);
		return 0;
	}
	strcpy(current -> name, name);
	current -> next = NULL;

	return 1;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{
	struct studentqueue *current = q -> next;
	/* Remember, you queue start with a name of NULL, 
	 * The pointer is changed to the next pointer.
	 */
	
	if (current == NULL){
		return 0;
	}
	
	strncpy(buffer, current -> name, size);
	q -> next = current -> next;
	free(current -> name);
	free(current);
	
	return 1;
}
