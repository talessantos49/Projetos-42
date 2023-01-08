/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:29:52 by tasantos          #+#    #+#             */
/*   Updated: 2023/01/08 05:38:47 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "../includes/libft.h"
# include <fcntl.h>
# define IN 	0
# define OUT 1
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define QUOTE '\''

typedef struct s_pipex
{
	char	**cmd;
	char	*paths;
	char	*first_command;
	char	*second_command;
	char	**path_command;
	char	**first_command_arg;
	char	**second_command_arg;
	int		pid;
	int		fd[2];
	int		pipefd[2];	
}	t_pipex;

typedef struct s_split
{
	size_t	index;
	size_t	n_words;
	size_t	n_chars;
	char	**string;
	char	quote;
}	t_split;

int		exit_error(char *string, int exitValue);
char	*find_path(char	**envp);
char	*find_cmd(char **path_command, char	*cmd, t_pipex *pipex, int order);
int		open_file(char	*file_path, int mode);
void	check_arguments(int argc, char	**argv, char *envp[], t_pipex *pipex);
void	child_process(t_pipex *pipex, char	**argv, char *envp[]);
void	free_all(t_pipex *pipex);
void	free_split(char	**vectors);
char	**ft_split_pipex(char const *s, char c);
void	validated_args(t_pipex *pipex, char	**argv, char *envp[]);
void	error_and_exit(int exit, t_pipex *pipex);

#endif