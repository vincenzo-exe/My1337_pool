#include <unistd.h>

int	get_operation(char op)
{
	char	operators[5];
	int		i;

	operators[0] = '+';
	operators[1] = '-';
	operators[2] = '*';
	operators[3] = '/';
	operators[4] = '%';
	i = 0;
	while (i < 5)
	{
		if (operators[i] == op)
			return (i);
		i++;
	}
	return (-1);
}

int	check_error(int index, int b)
{
	if (index == 3 && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (index == 4 && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}