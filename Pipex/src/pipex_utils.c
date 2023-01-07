/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:47:14 by tasantos          #+#    #+#             */
/*   Updated: 2023/01/07 22:25:00 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char	*file_path, int mode)
{
	int	fdin;
	int	fdout;

	if (mode == IN)
	{
		if (access(file_path, F_OK))
			exit_error(file_path, 1);
		fdin = open(file_path, O_RDONLY, 0644);
		if (fdin < 0)
			exit_error(file_path, 1);
		return (fdin);
	}
	else
	{
		fdout = open(file_path, O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (fdout < 0)
			exit_error(file_path, 1);
		return (fdout);
	}
}

void	check_arguments(int argc, char	**argv, char *envp[], t_pipex *pipex)
{
	char	**path_command;
	char	**firstCommandArg;
	char	**secondCommandArg;

	if (argc != 5)
	{
		write(2, "Input must be: ./pipex infile cmd1 cmd2 outfile\n", 56);
		exit(1);
	}
	else
	{
		path_command = ft_split(find_path(envp), ':');
		firstCommandArg = ft_split(argv[2], ' ');
		pipex->first_command = find_cmd(path_command, firstCommandArg[0]);
		free_split(firstCommandArg);
		if (pipex->first_command == NULL)
		{
			free(pipex->first_command);
			exit_error(argv[2], 1);
		}
		secondCommandArg = ft_split(argv[3], ' ');
		pipex->second_command = find_cmd(path_command, secondCommandArg[0]);
		free_split(secondCommandArg);
		free_split(path_command);
		if (pipex->second_command == NULL)
		{
			free(pipex->second_command);
			exit_error(argv[3], 1);
		}
		if (!access(argv[4], W_OK))
			exit_error(argv[4], 1);
		if (access(argv[1], F_OK))
			exit_error(argv[1], 1);
	}
}

void	free_split(char	**vectors)
{
	int	i;

	i = 0;
	while(vectors[i] != NULL)
	{
		free (vectors[i]);
		i++;
	}
	free(vectors);
}

void	free_all(t_pipex *pipex)
{
	free (pipex->first_command);
	free (pipex->second_command);
	free (pipex->cmd);
}
