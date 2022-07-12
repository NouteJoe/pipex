/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:09:16 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/03/16 17:04:29 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{	
	t_list	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last->next != NULL)
			last = last->next;
	return (last);
}
