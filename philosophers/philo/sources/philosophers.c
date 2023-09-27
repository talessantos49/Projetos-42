/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:34:28 by tasantos          #+#    #+#             */
/*   Updated: 2023/09/27 18:10:16 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	*sleeping_philo(int time_general, int philo_number)
{
	ft_printf("%d %d is sleeping\n", time_general, philo_number);
	return NULL;
}

void	*dieding_philo(int time_general, int philo_number)
{
	printf("%d %d died\n", time_general, philo_number);
	return NULL;
}

int	taking_fork(int time_general, int philo_number)
{
	printf("%d %d has taken a fork\n", time_general, philo_number);
	return (1);
}
long int    get_current_time(void)
{
    struct timeval    current_time;

    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	philos_routine(t_philo philos)
{
	//has taken a fork
	//is eating
	//is sleeping
	//is thinking
	//died
}

// void	dinners_time(void)
// {

// }
int	main(int argc, char **argv)
{
	pthread_t		thread1;
	pthread_t		thread2;
	t_philo			philos;
	struct timeval	start;
	struct timeval	end;
	int				tester;
	int				timeout;
	int				i = 0;
	// pthread_mutex_t	mutex;

	// pthread_mutex_init(&mutex, NULL);
	timeout = 0;
	tester = 0;
	// pthread_mutex_lock(&mutex);
	// while (i < 30)
	// {
	// 	gettimeofday(&start, NULL);
	// 	if (check_arguments(&philos, argc, argv))
	// 		return (0);
	// 	gettimeofday(&end, NULL);
	// 	timeout = end.tv_usec - start.tv_usec;
	// 	printf("Timeout: %d\n", timeout);
	// 	tester += eating_philo(timeout, 1);
	// 	tester += thinking_philo(timeout, 1);
	// 	sleeping_philo(timeout, 1);
	// 	dieding_philo(timeout, 1);
	// 	tester += taking_fork(timeout, 1);
	// 	i += tester;
	// }
	// pthread_mutex_destroy(&mutex);
	// printf("Timeout: %d\n", timeout);
	// ft_printf("Number of philosophers : %s\n", argv[1]);
	// ft_printf("Time to die : %s\n", argv[2]);
	// ft_printf("Time to eat : %s\n", argv[3]);
	// ft_printf("Time to sleep : %s\n", argv[4]);
	// ft_printf("Number of each philosopher must eat : %s\n", argv[5]);
	pthread_create(&thread1, NULL, sleeping_philo(timeout, 1), NULL);
	pthread_create(&thread2, NULL, dieding_philo(timeout, 1), NULL);
	usleep(50);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	// pthread_mutex_destroy(&mutex);
	return (0);
}
