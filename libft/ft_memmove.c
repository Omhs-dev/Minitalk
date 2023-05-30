/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:46:53 by ohamadou          #+#    #+#             */
/*   Updated: 2022/12/04 18:37:06 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*des ;
	char	*sr;

	des = (char *)dst;
	sr = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (des > sr)
	{
		while (len > 0)
		{
			des[len - 1] = sr[len - 1];
			len--;
		}
	}
	ft_memcpy(des, sr, len);
	return (dst);
}
