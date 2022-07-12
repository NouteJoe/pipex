/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:26:41 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/03/06 23:30:01 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*str;

	str = (void *)malloc ((count * size) * sizeof(*str));
	if (!str)
		return (NULL);
	ft_bzero(str, (count * size));
	return (str);
}
