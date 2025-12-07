#ifndef INDEXMAP_H
# define INDEXMAP_H

# include "vector.h"
# include <stdbool.h>

typedef struct s_indexmap	t_indexmap;

struct s_indexmap {
	t_vector	keys;
	t_vector	values;
	bool 		(*compare)(void*, int);
};

#endif