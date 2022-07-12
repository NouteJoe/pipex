/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:07:53 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/07/12 16:02:16 by jmuni-re         ###   ########.fr       */
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

void	ft_process(char **argv, char **env, int *fd, pid_t pid);
char	*ft_find_path(char **env, char **cmd);
char	**ft_find_line_env(char **env, char **cmd);
void	ft_error(void);

#endif
