/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:46:27 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:47 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	len;

	index = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size != 0)
	{
		while (src[index] != '\0' && index < (size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dest[20];
// 	unsigned int len;
// 	len = ft_strlcpy(dest, src, sizeof(dest));
// 	printf("Source: %s\n", src);
// 	printf("Destination: %s\n", dest);
// 	printf("Length of source: %u\n", len);
// }