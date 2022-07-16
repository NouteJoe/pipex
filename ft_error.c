/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:32:19 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/07/16 16:48:20 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_error(int x)
{
	if (x == 0)
		perror(NULL);
	if (x == 1)
		perror("Wrong number of arguments");
	if (x == 2)
		perror("Command not found");
	if (x == 3)
		perror("Open infile failed ");
	if (x == 4)
		perror("Open outfile failed");
	if (x == 5)
		perror("Path not found ");
	if (x == 6)
		perror("Error with fork ");
	if (x == 7)
		perror("Error with excve");
	exit(1);
}
