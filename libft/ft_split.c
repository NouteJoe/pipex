/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:44:42 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/07/12 15:23:14 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_lign;
	int		start;
	int		end;
	int		j;

	start = 0;
	j = 0;
	nb_lign = count_words((char *)s, c);
	tab = (char **) malloc((nb_lign + 1) * sizeof(char *));
	if (!tab || !s)
		return (NULL);
	while (j < nb_lign)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != 0)
			end++;
		tab[j] = ft_substr(s, start, (end - start));
		start = end;
		j++;
	}
	tab[j] = 0;
	return (tab);
}
