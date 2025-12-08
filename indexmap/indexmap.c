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

	index = this->keys.get_index(&this->keys, key);
	if (index > -1)
	{
		memcpy(this->values.at(&this->values, index), value, this->values.element_size);
	}
	else
	{
		this->keys.push(&this->keys, key);
		this->values.push(&this->values, value);
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

// bool	indexmap_remove(t_indexmap *this, void *key)
// {
// 	t_idxmap_pair	*pair;
// 	size_t			i;

// 	i = 0;
// 	while (i < this->data.size)
// 	{
// 		pair = this->data.at(&this->data, i);
// 		if (pair->key == key)
// 		{
// 			this->data.remove_at(&this->data, i);
// 			return (true);
// 		}
// 		i++;
// 	}
// 	return (false);
// }

void	*indexmap_get(t_indexmap *this, void *key)
{
	int	index;

	index = this->keys.get_index(&this->keys, key);
	return (this->values.at(&this->values, index));
}

void	*indexmap_end(t_indexmap *this)
{
	return (this->values.end(&this->values));
}

int main() {
	t_indexmap	my_map;
	int			key;
	char		**value;

	key = 42;
	my_map = init_indexmap(sizeof(int), sizeof(char*));
	indexmap_set(&my_map, &key, &(char*){"The answer"});
	indexmap_set(&my_map, &(int){69}, &(char*){"hehehe"});

	value = indexmap_get(&my_map, &(int){42});
	if (value != indexmap_end(&my_map)) {
		write(1, "Value found: ", 13);
		printf("%s\n", *value);
	}
	else
		printf("Key not found\n");

	return (0);
}