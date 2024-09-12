/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:37:44 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:50 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] >= 'a') && (str[c] <= 'z'))
			str[c] -= 'a' - 'A';
		c++;
	}
	return (str);
}

// #include <stdio.h>
// int	main()
// {
// 	char test1[] = "abcde";
// 	char test2[] = "abcDEF123!";
// 	printf("Testando \"%s \": %s\n", test1, ft_strupcase(test1));
// 	printf("Testando \"%s \": %s\n", test2, ft_strupcase(test2));
// }