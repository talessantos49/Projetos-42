/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:36:29 by marvin            #+#    #+#             */
/*   Updated: 2023/03/20 14:48:57 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long int	ft_atoi_push(const char	*str)
{
	long long int	result;
	int				i;
	int				s;

	s = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 7 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] == '-' || str[i +1] == '+'))
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	result = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (s * result);
}

int	check_max_min(char *str)
{
	const long long int	result = ft_atoi_push(str);
	if (result > 2147483647 || result < -2147483648)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	return (1);
}

int	check_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == 32)
		i++;
	if (str[i] == '\0')
		return (1);
	write(1, "Error\n", 7);
	return (0);
}

int	duplicated_args(int argc, char *argv[])
{
	int		i;
	int		k;
	char	*arguments;

	i = 1;
    arguments = (char *)ft_calloc(sizeof(char) * argc, argc);
	while (i < argc && arguments)
	{
		arguments[i] = ft_atoi_push (argv[i]);
		k = i;
		while (k != 0)
		{
			if (arguments[i] == arguments[k - 1])
			{
				write(1, "Error\n", 7);
                free(arguments);
				return (0);
			}
			k--;
		}
		i++;
	}
    free(arguments);
	return (1);
}

void	checkers(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_numbers(argv[i]) == 0)
			exit(0);
		if (check_max_min(argv[i]) == 0)
			exit(0);
		if (duplicated_args(argc, argv) == 0)
			exit(0);
		i++;
	}
}
