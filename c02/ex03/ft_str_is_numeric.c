/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:26:33 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:57 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (!(str[c] >= '0' && str[c] <= '9'))
			return (0);
		c++;
	}
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	char *test1 = "0123456789";
// 	char *test2 = "Hello123";
// 	char *test3 = "OnlyLetters";
// 	char *test4 = "Special!@#";
// 	char *test5 = "";
// 	printf("Testando \"%s : 1\": %d\n", test1, ft_str_is_numeric(test1));
// 	printf("Testando \"%s : 0\": %d\n", test2, ft_str_is_numeric(test2));
// 	printf("Testando \"%s : 0\": %d\n", test3, ft_str_is_numeric(test3));
// 	printf("Testando \"%s : 0\": %d\n", test4, ft_str_is_numeric(test4));
// 	printf("Testando \"%s : 0\": %d\n", test5, ft_str_is_numeric(test5));
// }