#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>

# define VECTOR_CAPACITY 50
# define V (void*)

typedef struct s_vector t_vector;
typedef struct s_ivector t_ivector;
typedef unsigned long long t_ull;

typedef union {
	void	*voidp;
	int		intv;
	int		*intp;
	char	charv;
	char	*charp;
	long	longv;
	long	*longp;
} u_any;

// u_any	ternary(int condition, u_any a, u_any b)
// {
// 	if (condition)
// 		return (a);
// 	return (b);
// }

struct s_vector {
	void	**content;
	uintptr_t	*content2;
	size_t	size;
	size_t	capacity;

	void	(*push)(uintptr_t, t_vector*);
	void	(*push_batch)(t_vector*, size_t, ...);
	void	(*insert)(void*, size_t, t_vector*);
	void	*(*remove_at)(size_t, t_vector*);
	void	*(*remove_element)(void*, t_vector*);
	void	*(*find)(void*, t_vector*);
	void	*(*find_with)(void*, void*(*)(), t_vector);
	void	*(*at)(size_t, t_vector*);
	void	(*for_each)(void*(*)(), t_vector*);
	void	(*destroy)(t_vector*);
} ;

void	vector_push_back(uintptr_t, t_vector*);
void	vector_push_batch(t_vector*, size_t, ...);
void	vector_insert(void*, size_t, t_vector*);
void	*vector_remove_index(size_t, t_vector*);
void	*vector_remove_element(void*, t_vector*);
// void	*vector_find(void*, t_vector*);					// todo
// void	*vector_find_with(void*, void*(*)(), t_vector);	// todo
void	*vector_safe_access(size_t, t_vector*);
void	vector_for_each(void*(*)(), t_vector*);
void	vector_destroy(t_vector*);

// struct s_ivector {
// 	void	(*push)(t_vector*, void*);
// 	void	(*push_batch)(t_vector*, size_t, ...);
// 	void	(*insert)(t_vector*, void*, size_t);
// 	void	*(*remove_at)(t_vector *, size_t);
// 	void	*(*remove_element)(t_vector *, void*);
// 	void	*(*at)(t_vector *, size_t);
// 	void	(*for_each)(t_vector *, void *(*)());
// 	void	(*destroy)(t_vector*);
// } ;


#endif