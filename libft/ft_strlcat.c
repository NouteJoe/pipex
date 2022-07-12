/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 04:40:04 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/03/11 12:47:46 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	size_dst = i;
	j = 0;
	while (src[j] && i < dstsize -1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size_dst < dstsize)
		dst[i] = '\0';
	return (size_dst + ft_strlen(src));
}
