// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/07 18:33:40 by tasantos          #+#    #+#             */
// /*   Updated: 2023/02/13 22:06:13 by tasantos         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/push_swap.h"

// #define INT_MAX 2147483647
// #define INT_MIN -2147483648

// void    check_arguments(int argc, char **argv)
// {
//     int i;
//     int k;
//     int is_num;
//     int len;
//     long long int enter_argument;

//     i = 0;
//     k = -1;
//     enter_argument = 0;
//     is_num = 0;
//     while (i < argc)
//     {
//         ft_printf("teste: %i\n", argv[i][k++]);
//         len = ft_strlen(argv[i]);
//         ft_printf("len: %i\n", len);
//         while (k++ < len)
//         {
//             is_num = ft_isdigit(argv[i][k]);
//             if (ft_isdigit(argv[i][k]))
//                 ft_printf("is_num = %d\n",is_num);   
//         }
//         enter_argument = ft_atoi (argv[i]);
//         if (is_num == 1)
//             ft_printf("Error: Invalid type of argument, please put a number\n");
//         if (enter_argument >= INT_MAX)
//             enter_argument = (INT_MAX);
//         if (enter_argument <= INT_MIN)
//             enter_argument = INT_MIN;
//         if (enter_argument == INT_MAX)
//             ft_printf("Error: Enter a valid argument number.\n");
//         if (enter_argument == INT_MIN)
//             ft_printf("Error: Enter a valid argument number Interger Overflow.\n");
//         i++;
//         k = 0;
//     }
// }

// int main (int argc, char **argv)
// {
//     check_arguments (argc, argv);
// }


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:33:00 by tasantos          #+#    #+#             */
/*   Updated: 2023/03/08 19:25:08 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

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

void	checkers(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_numbers(argv[i]) == 0)
			exit(0);
		if (check_max_min(argv[i]) == 0)
			exit(0);
		i++;
	}
}

// int duplicated_args(char *str)
// {

// }

void    check_argv(int argc, char *argv[])
{
    int    	i = 1;
	// ssize_t i = 0;
    // int 	k = 0;
    // int    	atoi = 0;
	// char 	*int_Max = "-2147483648";

    while (i < argc)
    {
        check_max_min(argv[i]);
        // k = 0;
		// ft_printf("O primeiro Argumento : ");
		// ft_printf(argv[i]);
		// ft_printf("\n");
		// ft_printf("O valor de Int Max : ");
		// ft_printf(int_Max);
		// ft_printf("\n");
		// if (argv[i] == int_Max)
		// 	ft_printf("O valor de int maximo negativo está sendo usado!");
        // while (argv[i][k])
        // {
        //     if (!ft_isdigit(argv[i][k]))
        //         ft_printf("Is not a number\n");
        //     // ft_printf("%d Its a number\n",ft_isdigit(argv[i][k]));
        //     k++;
        // }
      	// atoi = ft_atoi_push(argv[i]);
        // ft_printf("The number of the atoi is %d\n", atoi);
        i++;
    }
}

int    main(int argc, char **argv)
{

    if (argc < 2)
        return (ft_printf("1- Error\n"));
    checkers(argv);

    return (0);
}