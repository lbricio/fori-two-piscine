/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:26:43 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:53 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (!(str[c] >= 'A' && str[c] <= 'Z'))
			return (0);
		c++;
	}
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	char *test1 = "ABC";
// 	char *test2 = "ABCabc";
// 	char *test3 = "OnlyLetters123";
// 	char *test4 = "Special!@#";
// 	char *test5 = "";
// 	printf("Testando \"%s : 1\": %d\n", test1, ft_str_is_uppercase(test1));
// 	printf("Testando \"%s : 0\": %d\n", test2, ft_str_is_uppercase(test2));
// 	printf("Testando \"%s : 0\": %d\n", test3, ft_str_is_uppercase(test3));
// 	printf("Testando \"%s : 0\": %d\n", test4, ft_str_is_uppercase(test4));
// 	printf("Testando \"%s : 0\": %d\n", test5, ft_str_is_uppercase(test5));
// }