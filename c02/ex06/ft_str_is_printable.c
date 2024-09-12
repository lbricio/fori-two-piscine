/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:46:05 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:52 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 32) || (str[c] > 126))
			return (0);
		c++;
	}
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	char *test1 = "abc123@!";
// 	char *test2 = "\t\r";
// 	char *test3 = "";
// 	printf("Testando \"%s : 0\": %d\n", test1, ft_str_is_printable(test1));
// 	printf("Testando \"%s : 1\": %d\n", test2, ft_str_is_printable(test2));
// 	printf("Testando \"%s : 1\": %d\n", test3, ft_str_is_printable(test3));
// }