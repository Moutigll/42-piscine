/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeddah <almeddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:45:52 by almeddah          #+#    #+#             */
/*   Updated: 2024/08/24 15:32:42 by almeddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_listfree(t_list1 *list)
{
	t_list1	*node;
	t_list1	*next;

	node = list;
	while (node)
	{
		free(node->nb);
		free(node->trad);
		next = node->next;
		free(node);
		node = next;
	}
}

t_list1	*ft_listlast(t_list1 *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

int	ft_listsize(t_list1 *lst)
{
	int	e;

	e = 0;
	while (lst)
	{
		lst = lst->next;
		e++;
	}
	return (e);
}

void	ft_listadd_back(t_list1 **lst, t_list1 *new)
{
	t_list1	*lst_;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		lst_ = ft_listlast(*lst);
		lst_->next = new;
	}
}

t_list1	*ft_listnew(char *nb, char *trad)
{
	t_list1	*new_node;

	new_node = malloc(sizeof(t_list1));
	if (new_node)
	{
		new_node->nb = nb;
		new_node->trad = trad;
		new_node->next = NULL;
	}
	return (new_node);
}
