#include "indexmap.h"

void	*indexmap_set(t_indexmap *this, void *key, void *value)
{
	int		index;
	void	*ret;

	index = vector_get_index(&this->keys, key);
	if (index > -1) {
		ret = vector_at(&this->values, index);
		memcpy(ret, value, this->values.element_size);
	}
	else
	{
		vector_push_back(&this->keys, key);
		ret = vector_push_back(&this->values, value);
	}
	return (ret);
}

void	*indexmap_emplace(t_indexmap *this, void *key)
{
	vector_push_back(&this->keys, key);
	return (vector_emplace(&this->values));
}

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

int main()  {
	t_indexmap	processes;
	t_indexmap	strct_map;
	t_process	*value;

	processes = init_indexmap(sizeof(char*), sizeof(t_process));

	processes.set(&processes, "nginx", &(t_process){});
	processes.set(&processes, "frontend", &(t_process){
		.a = 1,
		.b = 2048,
		.c = 'R',
		.d = NULL
	});
	processes.set(&processes, "backend", &(t_process){});
	processes.set(&processes, "database", &(t_process){});

	value = processes.get(&processes, "frontend");
	printf("frontend %i, %li, %c, %p\n", value->a, value->b, value->c, value->d);
	value = processes.get(&processes, "nginx");
	printf("nginx %i, %li, %c, %p\n", value->a, value->b, value->c, value->d);


	destroy_indexmap(&processes);
	return (0);
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


// void	indexmap_evoque_each(t_indexmap *this, size_t offset, void *arg, ...) {
// 	size_t			i;
// 	void			*value;
// 	t_offset_func	method;
// 	va_list			original;
// 	va_list			arg_list;

// 	va_start(original, arg);
// 	i = 0;
// 	while (i < this->keys.size) {
// 		va_copy(arg_list, original);
// 		value = vector_at(&this->values, i);

// 		memcpy(&method, (char *)value + offset, sizeof(void *));
// 		method(value, arg_list);

// 		va_end(arg_list);
// 		i++;
// 	}
// 	va_end(original);
// }

// t_pair indexmap_end(t_indexmap *this)
// {
// 	return ((t_pair){
// 		vector_end(&this->keys),
// 		vector_end(&this->values)
// 	});
// }