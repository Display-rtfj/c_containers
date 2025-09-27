#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define VECTOR_CAPACITY 50
# define V (void*)

typedef struct s_vector t_vector;
typedef struct s_uvector t_uvector;
typedef struct s_pvector t_pvector;
typedef struct s_upvector t_upvector;
typedef unsigned long long t_ull;

struct s_vector {
	intptr_t	*data;
	size_t		size;
	size_t		capacity;

	void		(*push)();
	void		(*push_batch)(t_vector*, size_t, ...);
	void		(*insert)(t_vector*, intptr_t, size_t);
	void		(*for_each)(t_vector*, void*(*)());
	void		(*destroy)(t_vector*);
	intptr_t	(*remove_at)(t_vector*, size_t);
	intptr_t	(*remove_element)(t_vector*, intptr_t);
	intptr_t	(*find)(t_vector*, intptr_t);
	intptr_t	(*find_with)(t_vector*, intptr_t, void*(*)());
	intptr_t	(*at)(t_vector*, size_t);
	intptr_t	*(*end)(t_vector*);
} ;

struct s_uvector {
	intptr_t	*data;
	size_t		size;
	size_t		capacity;

	void		(*push)();
	void		(*push_batch)(t_vector*, size_t, ...);
	void		(*insert)(t_vector*, intptr_t, size_t);
	void		(*for_each)(t_vector*, void*(*)());
	void		(*destroy)(t_vector*);
	intptr_t	(*remove_at)(t_vector*, size_t);
	intptr_t	(*remove_element)(t_vector*, intptr_t);
	intptr_t	(*find)(t_vector*, intptr_t);
	intptr_t	(*find_with)(t_vector*, intptr_t, void*(*)());
	intptr_t	(*at)(t_vector*, size_t);
	intptr_t	*(*end)(t_vector*);
} ;

struct s_pvector {
	intptr_t	*data;
	size_t		size;
	size_t		capacity;

	void	(*push)();
	void	(*push_batch)(t_vector*, size_t, ...);
	void	(*insert)(t_vector*, intptr_t, size_t);
	void	(*for_each)(t_vector*, void*(*)());
	void	(*destroy)(t_vector*);
	void	*(*remove_at)(t_vector*, size_t);
	void	*(*remove_element)(t_vector*, intptr_t);
	void	*(*find)(t_vector*, intptr_t);
	void	*(*find_with)(t_vector*, intptr_t, void*(*)());
	void	*(*at)(t_vector*, size_t);
	void	**(*end)(t_vector*);
} ;

struct s_upvector {
	intptr_t	*data;
	size_t		size;
	size_t		capacity;

	void	(*push)();
	void	(*push_batch)(t_vector*, size_t, ...);
	void	(*insert)(t_vector*, intptr_t, size_t);
	void	(*for_each)(t_vector*, void*(*)());
	void	(*destroy)(t_vector*);
	void	*(*remove_at)(t_vector*, size_t);
	void	*(*remove_element)(t_vector*, void*);
	void	*(*find)(t_vector*, void*);
	void	*(*find_with)(t_vector*, void*, void*(*)());
	void	*(*at)(t_vector*, size_t);
	void	*(*end)(t_vector*);
} ;

void		vector_push_back(t_vector*, uintptr_t);
void		vector_push_batch(t_vector*, size_t, ...);
void		vector_insert(t_vector*, void*, size_t);
intptr_t	vector_remove_index(t_vector*, size_t);
intptr_t	vector_remove_element(t_vector*, intptr_t);
// void	*vector_find(void*, t_vector*);					// todo
// void	*vector_find_with(void*, void*(*)(), t_vector);	// todo
intptr_t	vector_safe_access(t_vector*, size_t);
void		vector_for_each(t_vector*, void*(*)());
void		vector_destroy(t_vector*);

#endif

// typedef union {
// 	void	*voidp;
// 	int		intv;
// 	int		*intp;
// 	char	charv;
// 	char	*charp;
// 	long	longv;
// 	long	*longp;
// } u_any;
