#include "vector.h"
#include <stdio.h>

void	vector_expand(t_vector *this)
{
	size_t	index;
	void	**new_array;

	this->capacity *= 2;
	new_array = malloc(sizeof(void*) * this->capacity);
	index = 0;
	while (index < this->size)
	{
		new_array[index] = this->content[index];
		++index;
	}
	free(this->content);
	this->content = new_array;
}

void	vector_push_back(t_vector *this, void *element)
{
	if (this->size >= this->capacity)
		vector_expand(this);
	this->content[this->size] = element;
	this->size++;
}

void	vector_push_batch(t_vector *this, size_t argc, ...)
{
	size_t	index;
	void	**list;

	list = (void**)(&argc);
	index = 0;
	while (index < argc)
	{
		++list;
		vector_push_back(this, *list);
		++index;
	}
}

void	*vector_remove_index(t_vector *this, size_t find)
{
	size_t	index;
	void	*element;

	if (find >= this->size)
		return (NULL);
	element = this->content[find];
	this->size--;
	index = find;
	while (index < this->size)
	{
		this->content[index] = this->content[index + 1];
		++index;
	}
	return (element);
}

void	*vector_safe_access(t_vector *this, size_t find)
{
	if (find >= this->size)
		return (NULL);
	return ((void*)&(this->content[find]));
}

void	*vector_remove_element(t_vector *this, void *find)
{
	size_t	index;
	void	*element;

	index = 0;
	while (index < this->size && this->content[index] != find)
		++index;
	if (index >= this->size)
		return (NULL);
	element = this->content[index];
	vector_remove_index(this, index);
	return (element);
}

void	vector_for_each(t_vector *this, void *(*function)())
{
	size_t index;

	index = 0;
	while (index < this->size)
	{
		function(&(this->content[index]), index);
		index++;
	}
}

void	vector_destroy(t_vector *this)
{
	free(this->content);
	free(this);
}

void	vector_insert(t_vector *this, void *element, size_t position)
{
	size_t	index;

	if (position >= this->size)
	{
		vector_push_back(this, element);
		return ;
	}
	if (this->size >= this->capacity)
		vector_expand(this);
	index = this->size;
	while (index > position)
	{
		this->content[index] = this->content[index - 1];
		--index;
	}
	this->content[position] = element;
	this->size++;
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
		.push_batch = vector_push_batch,
		.insert = vector_insert,
		.remove_at = vector_remove_index,
		.remove_element = vector_remove_element,
		.at = vector_safe_access,
		.for_each = vector_for_each,
		.destroy = vector_destroy
	};
	return (new_vector);
}

t_vector	init_vector(void)
{
	return ((t_vector) {
		.content = malloc(sizeof(void*) * VECTOR_CAPACITY),
		.size = 0,
		.capacity = VECTOR_CAPACITY
	});
}

typedef struct s_obj {
	char	*name;
} t_obj;

void	printVectorNumber(int *number)
{
	printf("%i, ", *number);
}

void	printVectorName(t_obj **person)
{
	printf("%s, ", (*person)->name);
}

t_obj	*new_obj(char *name)
{
	t_obj	*new = malloc(sizeof(t_obj));

	new->name = name;
	return (new);
}

void	free_obj(void **obj)
{
	free(*obj);
}

t_vector	vector(void)
{
	static	const t_vector	this = {
		.push = vector_push_back,
		.push_batch = vector_push_batch,
		.insert = vector_insert,
		.remove_at = vector_remove_index,
		.remove_element = vector_remove_element,
		.at = vector_safe_access,
		.for_each = vector_for_each,
		.destroy = vector_destroy
	};

	return (this);
}

int main(void)
{
	t_vector	*numbers = new_vector();
	t_vector	*persons = new_vector();
	t_vector	digits = init_vector();
	t_vector	integers = init_vector();


	// vector().push(numbers, V 5);
	// vector().push(numbers, V 7);
	// vector().push(numbers, V 8);
	// vector().push(numbers, V 9);
	{
		vector().push_batch(numbers, 4, V 5, V 7, V 8, V 9);
		vector().for_each(numbers, V printVectorNumber);
		printf("\n");
		vector().remove_at(numbers, 2);
		vector().for_each(numbers, V printVectorNumber);
		printf("\n");
		vector().destroy(numbers);
	}

	// vector_push(numbers, V 15);
	// vector_push(numbers, V 17);
	// vector_push(numbers, V 18);
	// vector_push(numbers, V 19);
	{
		vector_push_batch(&digits, 4, V 15, V 17, V 18, V 19);
		vector_for_each(&digits, V printVectorNumber);
		printf("\n");
		vector_remove_index(&digits, 2);
		vector_for_each(&digits, V printVectorNumber);
		printf("\n");
	}

	// numbers->push(numbers, V 5);
	// numbers->push(numbers, V 7);
	// numbers->push(numbers, V 8);
	// numbers->push(numbers, V 9);
	{
		numbers->push_batch(numbers, 4, V 5, V 7, V 8, V 9);
		numbers->for_each(numbers, V printVectorNumber);
		printf("\n");
		numbers->remove_at(numbers, 2);
		numbers->for_each(numbers, V printVectorNumber);
		printf("\n");
		numbers->destroy(numbers);
	}

	// persons->push(persons, new_obj("amanda"));
	// persons->push(persons, new_obj("jose"));
	// persons->push(persons, new_obj("rodrigo"));
	// persons->push(persons, new_obj("otavio"));
	// persons->push(persons, new_obj("murilo"));
	{
		persons->push_batch(persons, 5, new_obj("amanda"), new_obj("jose"), new_obj("rodrigo"), new_obj("otavio"), new_obj("murilo"));
		persons->for_each(persons, V printVectorName);
		printf("\n");
		free(persons->remove_at(persons, 3));
		persons->for_each(persons, V printVectorName);
		persons->for_each(persons, V free_obj);
		persons->destroy(persons);
	}
	return (0);
}