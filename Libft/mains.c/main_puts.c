/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_puts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 01:13:49 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/10 15:54:55 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

int	main(void)
{
	char	string[] = "João tem um pão!";

	ft_putnbr_fd(21474836473, 1);
	ft_putendl_fd(string, 1);
	ft_putstr_fd(string, 1);
}
