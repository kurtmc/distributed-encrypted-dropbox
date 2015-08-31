#ifndef NODE_H
#define NODE_H

struct Node {
	char **data_array;
	int *data_id;
	int *data_length;
	int data_array_length;
	int id;
};

struct Node *new_node();

void free_node(struct Node *n);

void append_data(struct Node *n, int id, char *data);

void print_node(struct Node *n);

#endif
