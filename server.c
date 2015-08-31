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

char *server_get_data(struct Node *n)
{
	for (int i = 0; i < nodes_length; i++) {
		for (int j = 0; j < nodes[i]->data_array_length; j++) {
			if (nodes[i]->data_id[j] == n->id) {
				return nodes[i]->data_array[j];
			}
		}
	}
	return NULL;
}

void free_server() {
	free(nodes);
	nodes_length = 0;
}
