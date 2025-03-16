#include "string.h"

t_string	*str_dup(t_string *this)
{
	int			i;
	t_string	*copy;

	copy = malloc(sizeof(t_string));
	copy->string = ft_calloc(sizeof(char), (this->length + 1));
	if (!copy->string)
		return (NULL);
	i = 0;
	while (this->string[i] != '\0')
	{
		copy->string[i] = this->string[i];
		i++;
	}
	copy->length = this->length;
	return (copy);
}

void	str_combine()
{

}

void	str_join()
{

}

void	str_equals()
{

}

void	str_contains()
{

}

void	str_foreach()
{

}

void	str_print()
{

}

void	str_destroy()
{
	
}