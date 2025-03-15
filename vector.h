#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>

# define VECTOR_CAPACITY 50
# define V (void*)

typedef struct s_vector t_vector;

struct s_vector {
	void	**content;
	size_t	size;
	size_t	capacity;

	void	(*push)(t_vector*, void*);
	void	(*insert)(t_vector*, void*, size_t);
	void	*(*remove_at)(t_vector *, size_t);
	void	*(*remove_element)(t_vector *, void*);
	void	*(*at)(t_vector *, size_t);
	void	(*for_each)(t_vector *, void *(*)());
	void	(*destroy)(t_vector*);
} ;

#endif