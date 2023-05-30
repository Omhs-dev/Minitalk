/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:51:10 by ohamadou          #+#    #+#             */
/*   Updated: 2022/12/04 19:35:12 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int an)
{
	if (ft_isalpha(an) || ft_isdigit(an))
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	int an;

// 	an = 'A';
// 	if (ft_isalnum(an))
// 		write(1, "alnum", 5);
// 	else
// 		write(1, "not", 3);
// }