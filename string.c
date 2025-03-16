#include "string.h"

char	*ft_strdup(t_string *this)
{
	int		i;
	char	*copy;

	copy = ft_calloc(sizeof(char), (this->length + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (this->string[i] != '\0')
	{
		copy[i] = this->string[i];
		i++;
	}
	return (copy);
}