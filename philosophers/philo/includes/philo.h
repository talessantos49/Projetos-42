/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:46:01 by tasantos          #+#    #+#             */
/*   Updated: 2023/09/27 18:07:04 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <time.h>
# include <pthread.h>
# include "libft.h"

typedef struct s_philo {
	int		index_philo;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		multiplier;
}	t_philo;

int		check_numbers(char *str);
int		check_arguments(t_philo *philos, int argc, char **argv);
void	initializer(t_philo *philos, int argc, char	**argv);

#endif