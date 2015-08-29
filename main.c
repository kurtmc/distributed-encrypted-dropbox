#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <string.h>

struct Node {
	char *data;
	int data_size;
};

struct Node *new_node()
{
	struct Node *n = (struct Node*) malloc(sizeof(*n));
	n->data_size = 0;
	n->data = NULL;
	return n;	
}

void free_node(struct Node *n)
{
	if (n->data != NULL)
		free(n->data);

	free(n);
}

void append_data(struct Node *n, char *d)
{
	int old_size = n->data_size;
	int new_size = old_size + strlen(d); 

	n->data = (char *) realloc(n->data, new_size + 1); /* + 1 for NULL termination charater */


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

int main(void)
{
	struct Node *n;
	n = new_node();

	print_node(n);

	append_data(n, "a");
	print_node(n);
	append_data(n, "b");
	print_node(n);

	free_node(n);
	
	return 0;
}
