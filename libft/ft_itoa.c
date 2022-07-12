/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:25:03 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/03/10 16:09:09 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int nbr)
{
	unsigned int	i;

	i = 1;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*int_to_char(int number, char *str1)
{
	int	nb1;

	nb1 = count(number);
	if (number < 0)
	{
		str1[0] = '-';
		number = -number;
	}		
	str1[nb1] = '\0';
	nb1--;
	while (number > 9)
	{
		str1[nb1] = number % 10 + '0';
		number = number / 10;
		nb1--;
	}
	if (number < 10)
		str1[nb1] = number + '0';
	return (str1);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;

	nb = count(n);
	str = malloc((nb + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{	
		ft_strlcpy(str, "-2147483648", nb + 1);
		return (str);
	}
	int_to_char(n, str);
	return (str);
}
