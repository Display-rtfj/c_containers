
#ifndef BINARY_NODE_H
# define BINARY_NODE_H

# include <stdlib.h>

typedef struct s_bnode {
	void			*content;
	struct s_bnode	*left;
	struct s_bnode	*right;
	struct s_bnode	*parent;
} t_bnode;

t_bnode	*new_bnode(void*);

#endif