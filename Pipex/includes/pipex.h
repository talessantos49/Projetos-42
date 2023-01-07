/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:29:52 by tasantos          #+#    #+#             */
/*   Updated: 2023/01/07 18:52:14 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/stat.h>
# include "../includes/libft.h"
# include <fcntl.h>
# define IN 	0
# define OUT 1
# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_pipex
{
	char	**cmd;
	char	*paths;
	char	*first_command;
	char	*second_command;
	int		pid;
	int		fd[2];
	int		pipefd[2];
}	t_pipex;

int 	exit_error(char *string, int exitValue);
char	*find_path(char	**envp);
char	*find_cmd(char **path_command, char	*cmd);
int		open_file(char	*file_path, int mode);
void 	check_arguments(int argc, char	**argv, char *envp[], t_pipex *pipex);
void	child_process(t_pipex *pipex, char	**argv, char *envp[]);
void	free_all(t_pipex *pipex);
void	free_split(char	**vectors);

#endif