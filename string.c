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

int	str_contains()
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

t_string	str(void)
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

t_string	hashmap(void)
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
	t_string	functions;


	while (list().next(animals) != list->head)
	{

	}
	list().next(animals);
	animals->next(animals);
	hashmap().add(map, "asdasd", new_string);
	str().add(&name, "lastname");
	str().chain(abed, 3, "abed", "middlename", "lastname");
	if (str().contains(abed, "last"))
		str().print(abed);

	str_add(&name, "lastname");
	str_chain(abed, 3, "abed", "middlename", "lastname");
	if (str_contains(abed, "last"))
		str_print(abed);

	name.add("robert", &name);
	abed->chain(abed, 3, "abed", "middlename", "lastname");
	if (abed->contains("robert", abed))
		abed->print(abed);
	str().clear(abed);
}
