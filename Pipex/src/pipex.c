/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:47:14 by tasantos          #+#    #+#             */
/*   Updated: 2023/01/08 05:31:41 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	exit_error(char *string, int exitValue)
{
	perror(string);
	exit(exitValue);
}

char	*find_path(char	**envp)
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	return (*envp + 5);
}

char	*find_cmd(char **path_command, char	*cmd)
{
	char	*temp;
	char	*command;

	while (*path_command)
	{
		temp = ft_strjoin(*path_command, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		path_command++;
	}
	return (NULL);
}

void	child_process(t_pipex *pipex, char	**argv, char *envp[])
{
	dup2(pipex->fd[0], STDIN);
	close(pipex->fd[0]);
	close(pipex->pipefd[IN]);
	dup2(pipex->pipefd[OUT], STDOUT);
	close(pipex->pipefd[OUT]);
	pipex->cmd = ft_split_pipex(argv[2], ' ');
	execve(pipex->first_command, pipex->cmd, envp);
}

int	main(int argc, char **argv, char *envp[])
{
	int		status;
	t_pipex	pipex;

	check_arguments(argc, argv, envp, &pipex);
	pipex.cmd = (char **)malloc(sizeof(char *));
	pipex.fd[0] = open_file(argv[1], IN);
	pipex.fd[1] = open_file(argv[4], OUT);
	if (pipe(pipex.pipefd) == -1)
		exit_error("pipe", 1);
	pipex.pid = fork();
	if (pipex.pid == 0)
		child_process (&pipex, argv, envp);
	else
	{
		close(pipex.pipefd[OUT]);
		dup2(pipex.pipefd[IN], STDIN);
		close(pipex.pipefd[IN]);
		dup2(pipex.fd[1], STDOUT);
		close(pipex.fd[1]);
		pipex.cmd = ft_split_pipex(argv[3], ' ');
		execve(pipex.second_command, pipex.cmd, envp);
	}
	waitpid(pipex.pid, &status, 0);
	free_all(&pipex);
	return (0);
}
