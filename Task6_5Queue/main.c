#include <stdio.h>
#include <string.h>
#include "queue.h"


int main(void)
{
	struct studentqueue q = { NULL, NULL };

	int go_on = 1;
	char buffer[100];
	while(go_on) {
		printf("Enter name of the student (\"-\" will end reading): ");
		scanf("%99s", buffer);
		if (strcmp(buffer, "-")) {
			go_on = enqueue(&q, buffer);
        } else {
			go_on = 0;
        }
	}

	while(dequeue(&q, buffer, 100)) {
	    printf("Fetching %s from queue\n", buffer);
	}

	return 0;
}
