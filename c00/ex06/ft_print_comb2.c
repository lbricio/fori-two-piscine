/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:41:33 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/15 20:20:07 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	char	num[5];

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			num[0] = (a / 10) + '0';
			num[1] = (a % 10) + '0';
			num[2] = ' ';
			num[3] = (b / 10) + '0';
			num[4] = (b % 10) + '0';
			write(1, num, 5);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
