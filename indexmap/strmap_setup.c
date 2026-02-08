// #include "indexmap.h"

// void	destroy_strmap(t_indexmap *this)
// {
// 	this->keys.for_each(&this->keys, (void*)free);
// 	this->keys.destroy(&this->keys);
// 	this->values.destroy(&this->values);
// }

// int	vector_string_compare(void *first, void *second, size_t)
// {
// 	return (strcmp(*(void**)first, second));
// }

// void	*strmap_set(t_indexmap *this, char *key, void *value)
// {
// 	void	*copy;

// 	copy = strdup(key);
// 	return (this->set(this, &copy, value));
// }

// void	*strmap_get(t_indexmap *this, char *key)
// {
// 	return (indexmap_get(this, &key));
// }

// bool	strmap_remove(t_indexmap *this, char *key)
// {
// 	int		index;

// 	index = vector_get_index(&this->keys, &key);
// 	if (index < 0)
// 		return (false);
// 	free(vector_at(&this->keys, index));
// 	vector_remove_index(&this->keys, index);
// 	vector_remove_index(&this->values, index);
// 	return (true);
// }

// t_indexmap	init_strmap(size_t value_size)
// {
// 	t_indexmap	map;

// 	map = init_indexmap(sizeof(char *), value_size);
// 	map.keys.compare = vector_string_compare;
// 	map.set = (void*)strmap_set;
// 	map.get = (void*)strmap_get;
// 	map.remove = strmap_remove;
// 	return (map);
// }

// t_indexmap	*new_strmap(size_t key_size, size_t value_size)
// {
// 	t_indexmap	*new;

// 	new = malloc(sizeof(t_indexmap));
// 	*new = init_strmap(value_size);
// 	return (new);
// }