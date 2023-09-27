/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:34:28 by tasantos          #+#    #+#             */
/*   Updated: 2023/09/26 18:26:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
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

int	eating_philo(int time_general, int philo_number)
{
	printf("%d %d is eating\n", time_general, philo_number);
	return (1);
}

int	thinking_philo(int time_general, int philo_number)
{
	printf("%d %d is thinking\n", time_general, philo_number);
	return (1);
}

int	sleeping_philo(int time_general, int philo_number)
{
	printf("%d %d is sleeping\n", time_general, philo_number);
	return (1);
}

int	dieding_philo(int time_general, int philo_number)
{
	printf("%d %d died\n", time_general, philo_number);
	return (1);
}

int	taking_fork(int time_general, int philo_number)
{
	printf("%d %d has taken a fork\n", time_general, philo_number);
	return (1);
}
long int	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	main(int argc, char **argv)
{
	t_philo	philos;
	struct timeval start;
	struct timeval end;
	int		tester;
	int		timeout;
	int		timestamp;
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	timeout = 0;
	tester = 0;
	pthread_mutex_lock(&mutex);
	timestamp = get_current_time();
	while (timeout < 200)
	{
		gettimeofday(&start, NULL);
		if (check_arguments(&philos, argc, argv))
			return (0);
		gettimeofday(&end, NULL);
		timeout = end.tv_usec - start.tv_usec;
		printf("Timestamp: %d\n", timestamp);
		timestamp = get_current_time();
		printf("Timeout: %d\n", timeout);
		tester += eating_philo(timeout, 1);
		tester += thinking_philo(timeout, 1);
		tester += sleeping_philo(timeout, 1);
		tester += dieding_philo(timeout, 1);
		tester += taking_fork(timeout, 1);
	}
	pthread_mutex_destroy(&mutex);
	printf("Timeout: %d\n", timeout);
	ft_printf("Number of philosophers : %s\n", argv[1]);
	ft_printf("Time to die : %s\n", argv[2]);
	ft_printf("Time to eat : %s\n", argv[3]);
	ft_printf("Time to sleep : %s\n", argv[4]);
	ft_printf("Number of each philosopher must eat : %s\n", argv[5]);
	pthread_mutex_destroy(&mutex);
	return (0);
}
