/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:26:13 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:06:02 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	c;

	c = 0;
	while (src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	src[] = "Hello, World!";
// 	char	dest[20];
// 	printf("before: %s\n", dest);
// 	ft_strcpy(dest, src);
// 	printf("after: %s\n", dest);
// 	return (0);
// }