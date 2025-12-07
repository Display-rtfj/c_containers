#include "vector.h"

void	*vector_push_back(t_vector *this, void *element)
{
	void	*end;

	if (this->size >= this->capacity)
		vector_expand(this);

	end = vector_end(this);
	memcpy(end, element, this->element_size);
	this->size++;
	return (end);
}

void	vector_remove_index(t_vector *this, size_t find)
{
	if (find >= this->size)
		return ;

	memcpy(
		this->data + find * this->element_size,
		this->data + (find + 1) * this->element_size,
		(this->size - find - 1) * this->element_size
	);
	this->size--;
	return ;
}

void	vector_remove_element(t_vector *this, void *find)
{
	void	*element;
	void	*end;

	element = vector_search(this, find);
	end = vector_end(this);
	if (element == end)
		return ;	

	memcpy(
		element,
		element + this->element_size,
		end - (element + this->element_size)
	);
	this->size--;
}

void	vector_mix_remove_index(t_vector *this, size_t index)
{
	void	*found;
	void	*end;

	found = vector_at(this, index);
	end = vector_end(this);
	if (found == end)
		return ;

	memcpy(
		found,
		end - this->element_size,
		this->element_size
	);
	this->size--;
}

void	vector_mix_remove_element(t_vector *this, void *element)
{
	void	*found;
	void	*end;

	found = vector_search(this, element);
	end = vector_end(this);
	if (found == end)
		return ;

	memcpy(
		found,
		end - this->element_size,
		this->element_size
	);
	this->size--;
}

void	vector_insert(t_vector *this, void *element, size_t position)
{
	void	*found;

	if (position >= this->size)
	{
		vector_push_back(this, element);
		return ;
	}

	found = vector_at(this, position);
	vector_push_back(this, found);
	memcpy(found, element, this->element_size);
	this->size++;
}

void	vector_for_each(t_vector *this, void *(*function)(void*, size_t))
{
	void	*it;
	void	*end;
	size_t	index;

	it = this->data;
	end = vector_end(this);
	while (it < end)
	{
		function(it, index);
		it += this->element_size;
		index++;
	}
}
