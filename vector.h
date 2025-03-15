#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>

# define VECTOR_CAPACITY 50
# define V (void*)

typedef struct s_vector t_vector;

typedef	struct s_vtask
{
	void	*(*function)();
	void	*arg1;
	void	*arg2;
	void	*arg3;
} t_vtask;


struct s_vector {
	void	**content;
	size_t	size;
	size_t	capacity;

	void	(*push)(t_vector*, void*);
	void	*(*remove_at)(t_vector *, size_t);
	void	*(*remove_element)(t_vector *, void*);
	void	*(*at)(t_vector *, size_t);
	void	(*for_each)(t_vector *, t_vtask);
	void	(*destroy)(t_vector*);
} ;

#endif