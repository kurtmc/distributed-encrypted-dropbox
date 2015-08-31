#include "server.h"
#include "node.h"
#include <stdlib.h>

static struct Node **nodes = NULL;
static int nodes_length = 0;

void register_node(struct Node *n)
{
	nodes_length++;
	nodes = realloc(nodes, nodes_length * sizeof(struct Node*));
	nodes[nodes_length - 1] = n;
}

char *get_data(struct Node *n)
{
	return 0;
}

void free_server() {
	free(nodes);
	nodes_length = 0;
}
