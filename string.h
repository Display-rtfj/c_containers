#ifndef STRING_H
# define STRING_H

# include <unistd.h>
# include <stdlib.h>

# define VECTOR_CAPACITY 50
# define V (void*)

typedef struct s_string t_string;

struct s_string {
	char	*string;
	size_t	length;

	void	(*dup)(t_string*);
	void	(*combine)(t_string*, size_t, ...);
	void	(*join)(t_string *, char*);
	void	(*equals)(t_string *, void*);
	void	(*contains)(t_string *, size_t);
	void	(*for_each)(t_string *, void *(*)());
	void	(*print)(t_string *);
	void	(*destroy)(t_string*);
} ;

#endif