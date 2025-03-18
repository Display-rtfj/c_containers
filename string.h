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

	t_string	*(*dup)(char*);
	void		(*chain)(t_string*, size_t, ...);
	void		(*add)(char*, t_string*);
	void		(*clear)(t_string*);
	int			(*equals)(void*, t_string*);
	int			(*contains)(char*, t_string*);
	void		(*for_each)(void *(*)(), t_string*);
	void		(*print)(t_string*);
	void		(*destroy)(t_string*);
	
} ;

#endif