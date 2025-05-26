/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:24:57 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/26 11:58:49 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next_lst;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next_lst = temp->next;
		if (del)
			del(temp->content);
		free(temp);
		temp = next_lst;
	}
	*lst = NULL;
}
