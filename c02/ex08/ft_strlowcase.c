/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:37:49 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:49 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] >= 'A') && (str[c] <= 'Z'))
			str[c] += 'a' - 'A';
		c++;
	}
	return (str);
}

// #include <stdio.h>
// int	main()
// {
// 	char test1[] = "AbCdEfGhH123@!";
// 	printf("Antes: %s\n", test1);
// 	printf("Depois: %s\n", ft_strlowcase(test1));
// }