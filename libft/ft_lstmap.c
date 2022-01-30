/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yryu <yryu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:23:28 by yryu              #+#    #+#             */
/*   Updated: 2022/01/30 14:09:44 by yryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*current;

	if (!lst || !f)
		return (0);
	result = ft_lstnew(f(lst->content));
	if (!result)
		return (0);
	current = result;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst->content));
		if (!(current->next))
		{
			ft_lstclear(&result, del);
			return (0);
		}
		current = current->next;
		lst = lst->next;
	}
	return (result);
}
