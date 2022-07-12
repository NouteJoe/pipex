/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:15:55 by jmuni-re          #+#    #+#             */
/*   Updated: 2022/03/18 16:28:47 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;

	if (!lst || !f)
		return (0);
	while (lst)
	{
		element = ft_lstnew((*f)(lst->content));
		if (!element)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		element = element->next;
		lst = lst->next;
		ft_lstadd_back(&lst, element);
	}
	return (element);
}
/*
    t_list    *result;
    t_list    *temp;

    result = NULL;
    while (lst)
    {
        temp = ft_lstnew((*f)(lst->content));
        if (!temp)
        {
            ft_lstclear(&result, del);
            return (NULL);
        }
        ft_lstadd_back(&result, temp);
        temp = temp->next;
        lst = lst->next;
    }
    return (result);
}
*/
