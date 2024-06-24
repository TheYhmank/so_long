/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:19:02 by jergoh            #+#    #+#             */
/*   Updated: 2024/06/24 16:06:13 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todelete;

	if (!lst)
		return ;
	while (*lst)
	{
		todelete = (*lst);
		*lst = (*lst)->next;
		ft_lstdelone(todelete, del);
	}
}
