/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:46:01 by tasantos          #+#    #+#             */
/*   Updated: 2023/09/25 19:35:45 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <time.h>
# include <pthread.h>

typedef struct s_philo {
	int		index_philo;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		multiplier;
}	t_philo;

#endif