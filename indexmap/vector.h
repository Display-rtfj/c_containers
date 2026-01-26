#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>

# define VECTOR_CAPACITY 50
# define V (void*)

typedef struct s_vector t_vector;
typedef t_vector t_uvector;

struct s_vector {
	void	*data;
	size_t	size;
	size_t	capacity;
	size_t	element_size;

	void	*(*push)(t_vector*, void*);
	void	(*push_batch)(t_vector*, size_t, ...);
	void	(*insert)(t_vector*, void*, size_t);
	void	(*for_each)(t_vector*, void*(*)(void*, size_t));
	void	(*destroy)(t_vector*);
	void	(*remove_at)(t_vector*, size_t);
	void	(*remove_element)(t_vector*, void*);
	void	*(*find)(t_vector*, void*);
	int		(*get_index)(t_vector*, void*);
	void	*(*find_with)(t_vector*, void*, void*(*)());
	void	*(*at)(t_vector*, size_t);
	void	*(*end)(t_vector*);
	void	(*destroy)(t_vector*);
} ;

//vector_setup.c
t_vector	init_vector(size_t size);
t_vector	*new_vector(size_t size);
t_uvector	*new_uvector(size_t size);
void		vector_destroy(t_vector *this);
void		vector_expand(t_vector *this);

//vector_get.c
void		*vector_end(t_vector *this);
void		*vector_at(t_vector *this, size_t find);
void		*vector_search(t_vector *this, void *find);
void		*vector_search_with(t_vector *this, void *find, void *(*comparator)());
int			vector_get_index(t_vector *this, void *find);

//vector_mod.c
void		*vector_push_back(t_vector *this, void *element);
void		vector_insert(t_vector *this, void *element, size_t position);
void		vector_remove_index(t_vector *this, size_t find);
void		vector_mix_remove_index(t_vector *this, size_t index);
void		vector_remove_element(t_vector *this, void *find);
void		vector_mix_remove_element(t_vector *this, void *element);
void		vector_for_each(t_vector *this, void *(*function)(void*, size_t));

#endif
