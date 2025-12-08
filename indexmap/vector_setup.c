#include "vector.h"

void	vector_destroy(t_vector *this)
{
	free(this->data);
	free(this);
}

void	delete_vector(t_vector *this)
{
	vector_destroy(this);
	free(this);
}

void	vector_expand(t_vector *this)
{
	this->capacity *= 2;
	this->data = realloc(this->data, this->element_size * this->capacity);
}

t_vector	init_vector(size_t size)
{
	return ((t_vector) {
		.data = malloc(size * VECTOR_CAPACITY),
		.size = 0,
		.capacity = VECTOR_CAPACITY,
		.element_size = size,

		.push = vector_push_back,
		.get_index = vector_get_index,
		.insert = vector_insert,
		.remove_at = vector_remove_index,
		.remove_element = vector_remove_element,
		.find = vector_search,
		.find_with = vector_search_with,
		.at = vector_at,
		.for_each = vector_for_each,
		.destroy = vector_destroy,
		.end = vector_end,
		// .push_batch = vector_push_batch,
	});
}

t_vector	*new_vector(size_t size)
{
	t_vector	*new;

	new = malloc(sizeof(t_vector));
	*new = init_vector(size);
	return (new);
}

t_mixvector	*new_mixvector(size_t size)
{
	t_mixvector	*new;

	new = new_vector(size);
	new->remove_at = vector_mix_remove_index;
	new->remove_element = vector_mix_remove_element;
	return (new);
}
