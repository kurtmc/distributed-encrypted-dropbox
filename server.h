#ifndef SERVER_H
#define SERVER_H

#include "node.h"

void register_node(struct Node *n);

char *get_data(struct Node *n);

void free_server();

#endif
