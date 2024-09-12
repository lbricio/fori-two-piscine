/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:26:21 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:06:00 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while ((src[c] != '\0') && (c < n))
	{
		dest[c] = src[c];
		c++;
	}
	while (c < n)
	{
		dest[c] = '\0';
		c++;
	}
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	src[] = "Hello, World!";
// 	char	dest[50];
// 	printf("before: %s\n", src);
// 	ft_strncpy(dest, src, 5);
// 	printf("after: %s\n", dest);
// 	return (0);
// }