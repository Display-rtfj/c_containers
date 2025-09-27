#include "binary_node.h"

t_bnode	bnode_init(void* content)
{
	return ((t_bnode) {
		.content = content,
		.left = NULL,
		.right = NULL,
		.parent = NULL,
	});
}

t_bnode	*new_bnode(void* content)
{
	t_bnode	*new;

	new = malloc(sizeof(t_bnode));
	if (!new) return (NULL);

	*new = bnode_init(content);
	return (new);
}
