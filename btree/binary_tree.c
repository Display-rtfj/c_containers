#include "binary_tree.h"

t_btree	btree_init(void)
{
	return ((t_btree) {
		.root = NULL,
		.size = 0,

		.compare = NULL,
		.insert = btree_insert,
		// .remove = btree_remove,
		// .search = btree_search,
		// .clear = btree_clear,
		// .destroy = btree_destroy,
	});
}

t_btree	*new_btree(t_btside (*compare)(const void*, const void*))
{
	t_btree	*new;
	t_btree	new = {
		
	};

	new = malloc(sizeof(t_btree));
	if (!new) return (NULL);

	*new = btree_init();
	new->compare = compare;
	return (new);
}

void	test(t_btree this) {
	printf("btree: %p\n", this);
	// if (this)
	// 	printf("root: %p, size: %zu\n", this->root, this->size);
}

void	btree_insert(t_btree* this, void *content) {
	t_bnode	*node;
	t_bnode	*iterator;
	t_bnode	**insert;

	if (!this || !content)
		printf("Error: btree_insert: btree: %p, content: %p\n", this, content);

	node = new_bnode(content);
	this->size++;
	if (!this->root) {
		this->root = node;
		return ;
	}

	iterator = this->root;
	while (true) {
		insert = (this->compare(content, iterator->content) < 0) ? &(iterator->left) : &(iterator->right);
		if (*insert == NULL) {
			node->parent = iterator;
			*insert = node;
			break ;
		}
		iterator = *insert;
	}
}

int main(void) {
	int a;
	int b;
	int c;
	int d;

	return 0;
}