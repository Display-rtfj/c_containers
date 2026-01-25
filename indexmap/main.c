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
	void	(*add)(t_command, t_command);
}	t_command;

int command_compare(void *first, void *second) {
	t_command	*cmd;

	cmd = first;
	return (cmd->id == ((t_command*)second)->id);
}

int main() {
	t_vector	all;
	t_vector	numbers;
	t_command	*command;
	t_command	a, b;;
	t_test		test;

	all = init_vector(sizeof(t_command));
	numbers = init_vector(sizeof(int));

	int	add = 5;
	vector_push_back(&numbers, &add);
	vector_push_back(&numbers, &(int){0});
	a.add(a, b);
	// vector_find_with(&all, &(t_command){.id = 42}, command_compare);
	command = vector_push_back(&all, &(t_command){.id = 42, .name = "The answer"});
	command = vector_push_back(&all, &(t_command){.id = 42, .name = "The answer"});
	command = vector_push_back(&all, &(t_command){.id = 42, .name = "The answer"});
	command = vector_push_back(&all, &(t_command){.id = 42, .name = "The answer"});
	command = vector_push_back(&all, &(t_command){.id = 42, .name = "The answer"});
	command = vector_push_back(&all, &(t_command){.id = 42, .name = "The answer"});
	command = vector_push_back(&all, &(t_command){.id = 42, .name = "The answer"});
	command = vector_push_back(&all, &(t_command){.id = 42, .name = "The answer"});

	command->name = "Updated answer";
	vector_push_back(&all, &(t_command){.id = 69, .name = "hehehe"});
	// element = pointers.at(&pointers, 5) && element != pointers.end(&pointers);
	// element = vector_at(&pointers, 5) && element != vector_end(&pointers);
	vector_destroy(&all);
}