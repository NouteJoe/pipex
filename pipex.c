/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:29:23 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/07/07 17:07:59 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

void	ft_error(void)
{
	perror(NULL);
	exit(1);
}

char	**ft_find_line_env(char **env, char **cmd)
{
	int		i;
	char	*line;
	char	**path;

	i = -1;
	line = NULL;
	if (!cmd[0])
		ft_error();
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	if (!env[i])
		ft_error();
	line = &(env[i][5]);
	path = ft_split(line, ':');
	if (!path[i])
		ft_error();
	return (path);
}

char	*ft_find_path(char **env, char **cmd)
{
	int		i;
	char	*line;
	char	**path;

	path = ft_find_line_env(env, cmd);
	i = -1;
	while (path[++i])
	{
		line = path[i];
		path[i] = ft_strjoin(ft_strjoin(path[i], "/"), cmd[0]);
		free(line);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
	}
	ft_error();
	return (NULL);
}

void	ft_process(char **argv, char **env, int *fd, pid_t pid)
{
	char	**cmd;
	int		ret;

	if (pid == 0)
	{	
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		cmd = ft_split(argv[2], ' ');
		ret = execve(ft_find_path(env, cmd), cmd, env);
		if (ret == -1)
			ft_error();
	}
	else
	{
		close (fd[1]);
		wait(NULL);
		dup2(fd[0], STDIN_FILENO);
		cmd = ft_split(argv[3], ' ');
		ret = execve(ft_find_path(env, cmd), cmd, env);
		if (ret == -1)
			ft_error();
	}
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];
	int		fdin;
	int		fdout;

	if (argc < 5)
		ft_error();
	fdin = open(argv[1], O_RDWR);
	if (fdin == -1)
		ft_error();
	fdout = open (argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fdout == -1)
		ft_error();
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		ft_error();
	ft_process(argv, env, fd, pid);
	return (0);
}
