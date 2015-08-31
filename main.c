#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "server.h"

int main(void)
{
	struct Node *n1;
	struct Node *n2;
	n1 = new_node(1);
	n2 = new_node(2);

	append_data(n2, 1, "This is n1's secret data");
	append_data(n1, 2, "This is n2's secret data");

	register_node(n1);
	register_node(n2);

	printf("n1's data: %s\n", server_get_data(n1));
	printf("n2's data: %s\n", server_get_data(n2));

	free_node(n1);
	free_node(n2);
	free_server();
	
	return 0;
}
