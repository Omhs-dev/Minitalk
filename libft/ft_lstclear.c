/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:25:07 by ohamadou          #+#    #+#             */
/*   Updated: 2022/12/16 20:49:57 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	ptr = NULL;
	if (*lst == NULL)
		return ;
	while (*lst != NULL)
	{
		ptr = *lst;
		(*lst) = (*lst)-> next;
		del(ptr-> content);
		free(ptr);
	}
}
