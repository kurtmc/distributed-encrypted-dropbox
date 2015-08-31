#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(void)
{
	struct Node *n1;
	struct Node *n2;
	n1 = new_node();
	n2 = new_node();

	append_data(n1, "This is n1's secret data");
	append_data(n2, "This is n2's secret data");

	int size = 2;
	struct Node **node_array = malloc(size * sizeof(struct Node*));

	node_array[0] = n1;
	node_array[1] = n2;

	free_node(n1);
	free_node(n2);
	free(node_array);
	
	return 0;
}
