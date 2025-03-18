#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>

# define VECTOR_CAPACITY 50
# define V (void*)

typedef struct s_vector t_vector;
typedef struct s_ivector t_ivector;

struct s_vector {
	void	**content;
	size_t	size;
	size_t	capacity;

	void	(*push)(void*, t_vector*);
	void	(*push_batch)(t_vector*, size_t, ...);
	void	(*insert)(void*, size_t, t_vector*);
	void	*(*remove_at)(size_t, t_vector*);
	void	*(*remove_element)(void*, t_vector*);
	void	*(*find)(void*, t_vector*); // todo
	void	*(*find_with)(void*, void*(*)(), t_vector*); // todo
	void	*(*at)(size_t, t_vector*);
	void	(*for_each)(void*(*)(), t_vector*);
	void	(*destroy)(t_vector*);
	void	(*print)(t_vector*);
} ;

struct s_ivector {
	void	(*push)(t_vector*, void*);
	void	(*push_batch)(t_vector*, size_t, ...);
	void	(*insert)(t_vector*, void*, size_t);
	void	*(*remove_at)(t_vector *, size_t);
	void	*(*remove_element)(t_vector *, void*);
	void	*(*at)(t_vector *, size_t);
	void	(*for_each)(t_vector *, void *(*)());
	void	(*destroy)(t_vector*);
} ;

#endif