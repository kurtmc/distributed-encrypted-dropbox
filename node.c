#include "node.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Node *new_node(int id)
{
	struct Node *n = (struct Node*) malloc(sizeof(*n));
	n->data_array = NULL;
	n->data_id = NULL;
	n->data_length = NULL;
	n->data_array_length = 0;
	n->id = id;
	return n;
}

void free_node(struct Node *n)
{
	if (n->data_array != NULL) {
		for (int i = 0; i < n->data_array_length; i++)
			free(n->data_array[i]);
		free(n->data_array);
	}


	if(n->data_id != NULL)
		free(n->data_id);

	if (n->data_length != NULL)
		free(n->data_length);

	if (n != NULL)	
		free(n);
}

/* Returns -1 if no index is found */
int get_index_of_id(struct Node *n, int id)
{
	for (int i = 0; i < n->data_array_length; i++) {
		if (n->data_id[i] == id)
			return i;
	}
	return -1;
}

/* Returns the index for where new memory has been allocated */
int allocate_for_new_data(struct Node *n, int id)
{
	int index = n->data_array_length;
	n->data_array_length++;
	if (n->data_array_length == 1) { /* allocate memory if none has been allocated */
		n->data_array = malloc(1 * sizeof(char*));
		n->data_id = malloc(1 * sizeof(int));
		n->data_length = malloc(1 * sizeof(int));
	} else { /* reallocte if memory already in use */
		n->data_array = realloc(n->data_array, n->data_array_length * sizeof(char*));
		n->data_id = realloc(n->data_id, n->data_array_length * sizeof(int));
		n->data_length = malloc(n->data_array_length * sizeof(int));
	}

	n->data_array[index] = NULL; /* initialise variable */
	n->data_id[index] = id;
	n->data_length[index] = 0;

	return index;
}

void append_data(struct Node *n, int id, char *data)
{
	int index = get_index_of_id(n, id);
	if (index == -1) {
		printf("No id found\n");
		index = allocate_for_new_data(n, id);
	}

	int old_length = n->data_length[index];
	int new_length = old_length + strlen(data);

	if (old_length == 0) {
		new_length++; /* need to increment to include '\0' */
		n->data_array[index] = malloc(new_length * sizeof(char));
	} else {
		n->data_array[index] = realloc(n->data_array[index], new_length * sizeof(char));
	}
	n->data_length[index] = new_length;

	int data_length = strlen(data);
	for (int i = 0; i < data_length	+ 1; i++) {
		n->data_array[index][old_length + i] = data[i];
	}
}

void print_node(struct Node *n)
{
	printf("Node %d\n", n->id);

}
