/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:46:18 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:48 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	c;
	int	new_word;

	c = 0;
	new_word = 1;
	while (str[c] != '\0')
	{
		if (new_word && (str[c] >= 'a' && str[c] <= 'z'))
			str[c] -= 'a' - 'A';
		else if (!new_word && (str[c] >= 'A' && str[c] <= 'Z'))
			str[c] += 'a' - 'A';
		if ((str[c] >= '0' && str[c] <= '9')
			|| (str[c] >= 'A' && str[c] <= 'Z')
			|| (str[c] >= 'a' && str[c] <= 'z'))
			new_word = 0;
		else
			new_word = 1;
		c++;
	}
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char test1[] = "lowercase";
// 	char test2[] = "NoTT lOweR123 case";
// 	printf("Original: \"%s\"\n", test1);
// 	printf("Modificada: \"%s\"\n", ft_strcapitalize(test1));
// 	printf("Original: \"%s\"\n", test2);
// 	printf("Modificada: \"%s\"\n", ft_strcapitalize(test2));
// 	return (0);
// }