#ifndef NODE_H
#define NODE_H

struct Node {
	char *data;
	int data_size;
	int *addresses;
	int addess_length;
};

struct Node *new_node();

void free_node(struct Node *n);

void append_data(struct Node *n, char *d);

void print_node(struct Node *n);

void add_address(struct Node *n, int address);

int get_address(struct Node *n, int i);

#endif
