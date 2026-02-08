#include "vector.h"
#include <stdio.h>

typedef struct s_command {
	int		id;
	char	*name;
	void	(*add)(void*, void*);
}	t_command;

int command_compare(void *first, void *second) {
	t_command	*cmd;

	cmd = first;
	return (cmd->id == ((t_command*)second)->id);
}

void	print_vector(int *number, size_t index) {
	*number += 5;
	printf("number %i, index: %zu\n", *number, index);
}

#define REF(x) (typeof(x)[]){x}

int main(void) {
	t_vector	*arr;
	t_vector	*strings;
	t_vector	*name;

	arr = new_vector(sizeof(int));
	strings = new_vector(sizeof(char*));
	name = new_vector(sizeof(char));

	name->push_batch(name, 6, "rubens");
	printf("name: %s\n", (char*)name->data);
	name->push_batch(name, 7, " teles.");
	printf("name: %s\n", (char*)name->data);
	name->push_batch(name, 7, " freire");
	printf("name: %s\n", (char*)name->data);
	name->remove_element(name, ".");
	*(char*)name->end(name) = 0;
	printf("name: %s\n", (char*)name->data);

	strings->push_batch(strings, 3, (char*[]){"Hello", "World", "!"});

	for (size_t i = 0; i < strings->size; i++) {
		printf("%s\n", *(char**)strings->at(strings, i));
	}

	arr->push_batch(arr, 5, (int[]){10, 20, 30, 40, 50});
	printf("index of 30: %d\n", arr->get_index(arr, (int[]){30}));
	arr->for_each(arr, (void*)print_vector);
	arr->remove_at(arr, 2);
	arr->insert(arr, (int[]){25}, 2);
	// arr->for_each(arr, (void*)print_vector);
	arr->remove_element(arr, (int[]){40});
	arr->for_each(arr, (void*)print_vector);
	arr->for_each(arr, (void*)print_vector);
	arr->for_each(arr, (void*)print_vector);
	printf("size: %zu\n", arr->size);
	printf("index of 40: %d\n", arr->get_index(arr, (int[]){40}));
	printf("index of 30: %d\n", arr->get_index(arr, (int[]){30}));
	printf("index of 10: %d\n", arr->get_index(arr, (int[]){10}));

	delete_vector(arr);
	delete_vector(strings);
	delete_vector(name);
	return (0);
}
