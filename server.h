#ifndef SERVER_H
#define SERVER_H

#include "node.h"

void register_node(struct Node *n);

char *server_get_data(struct Node *n);

void free_server(void);

#endif
