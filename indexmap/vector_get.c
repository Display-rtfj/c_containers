#include "vector.h"

inline void	*vector_end(t_vector *this)
{
	return (this->data + this->size * this->element_size);
}

inline void	*vector_at(t_vector *this, size_t find)
{
	if (find >= this->size)
		return (NULL);
	return (this->data + find * this->element_size);
}

void	*vector_search(t_vector *this, void *find)
{
	void	*it;
	void	*end;

	it = this->data;
	end = vector_end(this);
	while (it < end)
	{
		if (find == it || !memcmp(it, find, this->element_size))
			return (it);
		it += this->element_size;
	}
	return (NULL);
}

int	vector_get_index(t_vector *this, void *find)
{
	void	*it;
	void	*end;

	it = this->data;
	end = vector_end(this);
	while (it < end)
	{
		if (find == it || !memcmp(it, find, this->element_size))
			return ((it - this->data) / this->element_size);
		it += this->element_size;
	}
	return (-1);
}

void	*vector_search_with(t_vector *this, void *find, void *(*comparator)())
{
	void	*it;
	void	*end;

	it = this->data;
	end = vector_end(this);
	while (it < end)
	{
		if (comparator(it, find))
			return (it);
		it += this->element_size;
	}
	return (NULL);
}
