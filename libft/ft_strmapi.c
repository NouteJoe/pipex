/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:09:17 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/03/10 19:17:34 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		j;
	char	*str;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s[j])
	{
		str[j] = f(j, s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
