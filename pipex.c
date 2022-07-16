/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:29:23 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/07/16 16:49:58 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_find_line_env(char **env, char **cmd)
{
	int		i;
	char	*line;
	char	**path;

	i = -1;
	line = NULL;
	if (!cmd[0])
		ft_error(2);
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	if (!env[i])
		ft_error(5);
	line = &(env[i][5]);
	path = ft_split(line, ':');
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
	ft_error(5);
	return (NULL);
}

void	ft_child(char **env, char *argv, int *fd)
{
	int		ret;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	close(fd[0]);
	ret = execve(ft_find_path(env, cmd), cmd, env);
	if (ret == -1)
		ft_error(7);
}

void	ft_process(int argc, char **argv, char **env, int tmp)
{
	int		i;
	pid_t	pid;
	int		fd[2];

	i = 1;
	while (++i < argc - 1)
	{	
		pipe(fd);
		pid = fork();
		if (pid == -1)
			ft_error(6);
		if (pid == 0)
		{
			dup2(tmp, STDIN_FILENO);
			if (i < (argc - 2))
				dup2(fd[1], STDOUT_FILENO);
			ft_child(env, argv[i], fd);
		}
		else
		{
			dup2(fd[0], tmp);
			close(fd[1]);
			wait(NULL);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fdin;
	int		fdout;
	int		tmp;

	if (argc < 5)
		ft_error(1);
	fdin = open(argv[1], O_RDWR);
	if (fdin == -1)
		ft_error(3);
	fdout = open (argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fdout == -1)
		ft_error(4);
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	tmp = dup(STDIN_FILENO);
	ft_process(argc, argv, env, tmp);
	return (0);
}
