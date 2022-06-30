/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:28:53 by tasantos          #+#    #+#             */
/*   Updated: 2022/05/27 23:18:16 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	char	*var[3][3];
	int	i;
	int	j;
	int k;
	char	*string[9] = {"banana","maça","kiwi","tomate","farofa","pipoca","bolo","chocolate","betterRaba"};

	i = 0;
	k = 0;
    while(i < 3)
    {
      j = 0;
        while (j < 3)
        {
            var[i][j] = string[k];
            j++;
			k++;
        }
      i++;
    }
	printf("O retorno é %s", var[0][0]);
	return (0);
}


int main()
{
	int mat[3][3];
	int i;
	int j;
	int val;

	i = 0;
	val = 0;

	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			mat[i][j] = val;
			val++;
			j++;
		}
		i++;
	}
	printf("%d \n", mat[2][2]);
	return (0);
}