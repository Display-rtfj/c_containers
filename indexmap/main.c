#include "vector.h"
#include <stdio.h>

//ToDo
// void	vector_push_batch(t_vector *this, size_t argc, ...)
// {
// 	size_t	index;
// 	void	**list;

// 	list = ((void**)(&argc));
// 	index = 0;
// 	while (index < argc)
// 	{
// 		++list;
// 		vector_push_back((uintptr_t)*list, this);
// 		++index;
// 	}
// }


// int main() {
// 	t_vector	objects;
// 	// t_vector	*pointers;
// 	// void		*element;

// 	(void)element;
// 	pointers = new_vector(sizeof(void*));
// 	objects = init_vector(sizeof(t_vector));
// 	pointers = init_vector(sizeof(void*));

// 	pointers.push(&pointers, malloc(sizeof(t_vector)));
// 	element = objects.push(&objects, &(t_vector){0});

// 	vector_push_back(&pointers, malloc(sizeof(t_vector)));
// 	element = vector_push_back(&objects, &(t_vector){0});

// 	// element = pointers.at(&pointers, 5) && element != pointers.end(&pointers);
// 	// element = vector_at(&pointers, 5) && element != vector_end(&pointers);
// 	vector_destroy(&objects);
// }

typedef struct s_command {
	int		id;
	char	*name;
}	t_command;


// int main() {
// 	t_vector	all;
// 	t_command	*command;

// 	all = init_vector(sizeof(t_command));

// 	command = vector_push_back(&all, &(t_command){1, "command_one"});
// 	command = vector_push_back(&all, &(t_command){1, "command_one"});
// 	command = vector_push_back(&all, &(t_command){1, "command_one"});
// 	command = vector_push_back(&all, &(t_command){1, "command_one"});
// 	command = vector_push_back(&all, &(t_command){1, "command_one"});
// 	command = vector_push_back(&all, &(t_command){1, "command_one"});
// 	command = vector_push_back(&all, &(t_command){1, "command_one"});

// 	// element = pointers.at(&pointers, 5) && element != pointers.end(&pointers);
// 	// element = vector_at(&pointers, 5) && element != vector_end(&pointers);
// 	vector_destroy(&all);
// }