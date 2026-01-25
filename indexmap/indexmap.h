#ifndef INDEXMAP_H
# define INDEXMAP_H

# include "vector.h"
# include <stdbool.h>

typedef struct s_indexmap	t_indexmap;

typedef struct s_pair {
	void	*first;
	void	*second;
} t_pair;

struct s_indexmap {
	t_vector	keys;
	t_vector	values;
	bool 		(*compare)(void*, int);
} ;

#endif