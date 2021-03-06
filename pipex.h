/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:07:53 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/07/16 16:51:11 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

void	ft_process(int argc, char **argv, char **env, int tmp);
char	*ft_find_path(char **env, char **cmd);
char	**ft_find_line_env(char **env, char **cmd);
void	ft_error(int x);
void	ft_child(char **env, char *argv, int *fd);

#endif
