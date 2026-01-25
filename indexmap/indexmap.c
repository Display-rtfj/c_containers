#include "indexmap.h"

t_indexmap	init_indexmap(size_t key_size, size_t value_size)
{
	return ((t_indexmap) {
		.keys = init_vector(key_size),
		.values = init_vector(value_size),
		.compare = NULL,
	});
}

t_indexmap	*new_indexmap(size_t key_size, size_t value_size)
{
	t_indexmap	*new;

	new = malloc(sizeof(t_indexmap));
	*new = init_indexmap(key_size, value_size);
	return (new);
}

void	indexmap_destroy(t_indexmap *this)
{
	this->keys.destroy(&this->keys);
	this->values.destroy(&this->values);
	free(this);
}

// t_idxmap_pair	*indexmap_get_pair(t_indexmap *this, void *key)
// {
// 	size_t			i;
// 	t_idxmap_pair	*pair;

// 	i = 0;
// 	while (i < this->data.size)
// 	{
// 		pair = this->data.at(&this->data, i);
// 		if (pair->key == key)
// 			return (pair);
// 		i++;
// 	}
// 	return (NULL);
// }

bool	indexmap_set(t_indexmap *this, void *key, void *value)
{
	int	index;

	index = vector_get_index(&this->keys, key);
	if (index > -1)
		memcpy(vector_at(&this->values, index), value, this->values.element_size);
	else
	{
		vector_push_back(&this->keys, key);
		vector_push_back(&this->values, value);
	}
	return (true);
}

// bool	indexmap_has(t_indexmap *this, void *key)
// {
// 	t_idxmap_pair	*pair;
// 	size_t			i;

// 	i = 0;
// 	while (i < this->data.size)
// 	{
// 		pair = this->data.at(&this->data, i);
// 		if (pair->key == key)
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }

bool	indexmap_remove(t_indexmap *this, void *key)
{
	size_t	index;

	index = vector_get_index(&this->keys, key);
	if (index < 0)
		return (false);
	vector_remove_index(&this->keys, index);
	vector_remove_index(&this->values, index);
	return (true);
}

void	*indexmap_get(t_indexmap *this, void *key)
{
	int	index;

	index = vector_get_index(&this->keys, key);
	return (vector_at(&this->values, index));
}

t_pair indexmap_end(t_indexmap *this)
{
	return ((t_pair){
		vector_end(&this->keys),
		vector_end(&this->values)
	});
}

#define ADDR(val) ((void *)&(typeof(val)){val})

int main()  {
	t_indexmap	into_map;
	t_indexmap	strct_map;
	t_test		test;
	int			key;
	char		**value;


	key = 42;

	into_map = init_indexmap(sizeof(int), sizeof(char*));
	indexmap_set(&into_map, &key, ADDR("The answer"));
	indexmap_set(&into_map, ADDR(69), ADDR("hehehe"));

	value = indexmap_get(&into_map, ADDR(42));
	if (value) {
		write(1, "Value found: ", 13);
		printf("%s\n", *value);
	}
	else
		printf("Key not found\n");

	return (0);
}

