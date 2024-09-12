/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:46:23 by naharumi          #+#    #+#             */
/*   Updated: 2024/09/04 22:19:24 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strjoin_bsq(char *s1, const size_t size1,
		char *s2, const size_t size2)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1, size1);
	ft_strcpy(&res[size1], s2, size2);
	free(s1);
	return (res);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;

	if (!dst && !src)
		return (0);
	x = 0;
	while (x < n)
	{
		((unsigned char *)dst)[x] = ((unsigned char *)src)[x];
		x++;
	}
	return (dst);
}
