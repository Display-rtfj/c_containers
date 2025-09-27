

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include <stdlib.h>
# include <stdbool.h>
# include "binary_node.h"
# include <stdio.h>

typedef struct s_btree t_btree;


typedef enum s_btside {
	BT_LEFT = -1,
	BT_RIGHT = 1
}	t_btside;

typedef struct s_btree {
	t_bnode	*root;
	size_t	size;
	
	t_btside	(*compare)(const void*, const void*);
	void		(*insert)(t_btree*, void*);
	void		(*remove)(t_btree*, void*);
	t_bnode		*(*search)(t_btree*, void*);
	void		(*clear)(t_btree*);
	void		(*destroy)(t_btree*);
} t_btree;

t_btree	btree_init(void);
t_btree	*new_btree(t_btside (*compare)(const void*, const void*));
t_bnode	*btree_search(t_btree*, void*);
void	btree_insert(t_btree*, void*);
void	btree_remove(t_btree*, void*);
void	btree_clear(t_btree*);
void	btree_destroy(t_btree*);

#endif