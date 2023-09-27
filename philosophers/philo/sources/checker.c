/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:26:05 by tasantos          #+#    #+#             */
/*   Updated: 2023/09/27 17:28:46 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	return (0);
}

int	check_arguments(t_philo *philos, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		ft_printf("Wrong numbers of arguments!\n");
		return (1);
	}
	while (++i < argc)
	{
		if (!(check_numbers(argv[i])))
		{
			ft_printf("Wrong tipe of arguments!\n");
			return (1);
		}
	}
	initializer(philos, argc, argv);
	return (0);
}

void	initializer(t_philo *philos, int argc, char	**argv)
{
	philos->die_time = ft_atoi(argv[1]);
	philos->eat_time = ft_atoi(argv[2]);
	philos->sleep_time = ft_atoi(argv[3]);
	philos->index_philo = ft_atoi(argv[4]);
	if (argc == 6)
		philos->multiplier = ft_atoi(argv[5]);
	else
		philos->multiplier = 0;
}
