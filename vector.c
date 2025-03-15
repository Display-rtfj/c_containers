#include "vector.h"
#include <stdio.h>

void	vector_expand(t_vector *vector)
{
	size_t	index;
	void	**new_array;

	vector->capacity *= 2;
	new_array = malloc(sizeof(void*) * vector->capacity);
	index = 0;
	while (index < vector->size)
	{
		new_array[index] = vector->content[index];
		++index;
	}
	free(vector->content);
	vector->content = new_array;
}

void	vector_push_back(t_vector *vector, void *element)
{
	if (vector->size >= vector->capacity)
		vector_expand(vector);
	vector->content[vector->size] = element;
	vector->size++;
}

void	*vector_remove_index(t_vector *vector, size_t find)
{
	size_t	index;
	void	*element;

	if (find >= vector->size)
		return (NULL);
	element = vector->content[find];
	vector->size--;
	index = find;
	while (index < vector->size)
	{
		vector->content[index] = vector->content[index + 1];
		++index;
	}
	return (element);
}

void	*vector_safe_access(t_vector *vector, size_t find)
{
	if (find >= vector->size)
		return (NULL);
	return ((void*)&(vector->content[find]));
}

void	*vector_remove_element(t_vector *vector, void *find)
{
	size_t	index;
	void	*element;

	index = 0;
	while (index < vector->size && vector->content[index] != find)
		++index;
	if (index >= vector->size)
		return (NULL);
	element = vector->content[index];
	vector_remove_index(vector, index);
	return (element);
}

void	vector_for_each(t_vector *vector, void *(*function)())
{
	size_t index;

	index = 0;
	while (index < vector->size)
	{
		function(&(vector->content[index]), index);
		index++;
	}
}

void	vector_destroy(t_vector *vector)
{
	free(vector->content);
	free(vector);
}

t_vector	*new_vector(void)
{
	t_vector	*new_vector;

	new_vector = malloc(sizeof(t_vector));
	*new_vector = (t_vector) {
		.content = malloc(sizeof(void*) * VECTOR_CAPACITY),
		.size = 0,
		.capacity = VECTOR_CAPACITY,
		.push = vector_push_back,
		.remove_at = vector_remove_index,
		.remove_element = vector_remove_element,
		.at = vector_safe_access,
		.for_each = vector_for_each,
		.destroy = vector_destroy
	};
	return (new_vector);
}

// typedef struct s_obj {
// 	char	*name;
// } t_obj;

// void	printVectorNumber(int *number)
// {
// 	printf("%i, ", *number);
// }

// void	printVectorName(t_obj **person)
// {
// 	printf("%s, ", (*person)->name);
// }

// t_obj	*new_obj(char *name)
// {
// 	t_obj	*new = malloc(sizeof(t_obj));

// 	new->name = name;
// 	return (new);
// }

// void	free_obj(void **obj)
// {
// 	free(*obj);
// }

// int main(void)
// {
// 	t_vector	*numbers = new_vector();
// 	t_vector	*persons = new_vector();

// 	numbers->push(numbers, V 5);
// 	numbers->push(numbers, V 7);
// 	numbers->push(numbers, V 8);
// 	numbers->push(numbers, V 9);
// 	numbers->for_each(numbers, (t_vtask){V printVectorNumber});
// 	printf("\n");
// 	numbers->remove_at(numbers, 2);
// 	numbers->for_each(numbers, (t_vtask){V printVectorNumber});
// 	printf("\n");

// 	numbers->destroy(numbers);

// 	persons->push(persons, new_obj("amanda"));
// 	persons->push(persons, new_obj("jose"));
// 	persons->push(persons, new_obj("rodrigo"));
// 	persons->push(persons, new_obj("otavio"));
// 	persons->push(persons, new_obj("murilo"));
// 	persons->for_each(persons, (t_vtask){V printVectorName});
// 	printf("\n");
// 	free(persons->remove_at(persons, 3));
// 	persons->for_each(persons, (t_vtask){V printVectorName});
// 	persons->for_each(persons, (t_vtask){V free_obj});
// 	persons->destroy(persons);
// 	return (0);
// }