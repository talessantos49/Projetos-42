/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:47:14 by tasantos          #+#    #+#             */
/*   Updated: 2023/01/08 05:36:35 by tasantos         ###   ########.fr       */
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

void	validated_args(t_pipex *pipex, char	**argv, char *envp[])
{
	pipex->path_command = ft_split(find_path(envp), ':');
	pipex->first_command_arg = ft_split_pipex(argv[2], ' ');
	pipex->first_command = find_cmd(pipex->path_command, \
	pipex->first_command_arg[0], pipex, 1);
	free_split(pipex->first_command_arg);
	if (pipex->first_command == NULL)
	{
		free(pipex->first_command);
		exit_error(argv[2], 1);
	}
	pipex->second_command_arg = ft_split_pipex(argv[3], ' ');
	pipex->second_command = find_cmd(pipex->path_command, \
	pipex->second_command_arg[0], pipex, 2);
	free_split(pipex->second_command_arg);
	free_split(pipex->path_command);
	if (pipex->second_command == NULL)
	{
		free(pipex->second_command);
		exit_error(argv[3], 1);
	}
}

void	check_arguments(int argc, char	**argv, char *envp[], t_pipex *pipex)
{
	if (argc != 5)
	{
		write(2, "Input must be: ./pipex infile cmd1 cmd2 outfile\n", 56);
		exit(1);
	}
	else
		validated_args (pipex, argv, envp);
}

void	free_split(char	**vectors)
{
	int	i;

	i = 0;
	while (vectors[i] != NULL)
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
