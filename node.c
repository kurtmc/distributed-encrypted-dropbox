#include "node.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Node *new_node()
{
	struct Node *n = (struct Node*) malloc(sizeof(*n));
	n->data_size = 0;
	n->data = NULL;
	n->addresses = NULL;
	n->addess_length = 0;
	return n;	
}

void free_node(struct Node *n)
{
	if (n->data != NULL)
		free(n->data);
	if (n->addresses != NULL)
		free(n->addresses);

	free(n);
}

void append_data(struct Node *n, char *d)
{
	int old_size = n->data_size;
	int new_size = old_size + strlen(d); 

	n->data = realloc(n->data, new_size + 1); /* + 1 for NULL termination charater */


	int d_length = strlen(d) + 1;
	for (int i = 0; i < d_length; i++) {
		n->data[old_size + i] = d[i];
	}

	n->data_size = new_size;
}

void print_node(struct Node *n)
{
	printf("Node\n");
	printf("data size: %d\n", n->data_size);
	printf("data: %s\n", n->data);
}

void add_address(struct Node *n, int address)
{
	n->addess_length++;
	n->addresses = realloc(n->addresses, n->addess_length);
	n->addresses[n->addess_length - 1] = address;
}

int get_address(struct Node *n, int i)
{
	if (i >= n->addess_length)
		return -1;

	return n->addresses[i];
}
