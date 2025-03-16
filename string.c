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

void	str_add()
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

t_string	*new_string()
{

}

t_string	string(void)
{
	static const t_string	this = {
		.dup = str_dup,
		.chain = str_combine,
		.add = str_add,
		.equals = str_equals,
		.contains = str_contains,
		.for_each = str_foreach,
		.print = str_print,
		.destroy = str_destroy
	};

	return (this);
}

int main(void)
{
	t_string	name;
	t_string	*abed;

	string().add(&name, "lastname");
	string().chain(abed, 3, "abed", "middlename", "lastname");
	if (string().contains(abed, "last"))
		string().print(abed);
}