#include "indexmap.h"
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

int	vector_test(void){
	t_vector	*arr;
	t_vector	*strings;
	t_vector	*name;

	arr = new_vector(sizeof(int));
	strings = new_vector(sizeof(char*));
	name = new_vector(sizeof(char));

	name->push_batch(name, "rubens", 6);
	printf("name: %s\n", (char*)name->data);
	name->push_batch(name, " teles.", 7);
	printf("name: %s\n", (char*)name->data);
	name->push_batch(name, " freire", 7);
	printf("name: %s\n", (char*)name->data);
	name->remove_element(name, ".");
	*(char*)name->end(name) = 0;
	printf("name: %s\n", (char*)name->data);

	strings->push_batch(strings, (char*[]){"Hello", "World", "!"},  3);

	for (size_t i = 0; i < strings->size; i++) {
		printf("%s\n", *(char**)strings->at(strings, i));
	}

	arr->push_batch(arr, (int[]){10, 20, 30, 40, 50}, 5);
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

int main(void) {
	// t_strmap	*map;
	t_command	*temp;
	t_indexmap	*processes;

	// map = new_strmap(sizeof(t_command));
	// map->set(map, "nginx", &(t_command){.name = "nginx"});

	processes = new_strmap(sizeof(t_command));

	processes->set(processes, "nginx", &(t_command){.name = "nginx"});
	temp = processes->get(processes, "nginx");

	if (temp) {
		printf("temp name %s\n", temp->name);
	}
	else {
		printf("notfound\n");
	}

	// delete_indexmap((void*)map);
	delete_indexmap(processes);
	
}
