/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:46:34 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:11:54 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(const char *str)
{
	const char	hex[] = "0123456789abcdef";

	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex[(*str) / 16]);
			ft_putchar(hex[(*str) % 16]);
		}
		str++;
	}
}

// int	main(void)
// {
// 	char str[] = "Oi\n\tyou are fine?";
// 	ft_putstr_non_printable(str);
// 	return (0);
// }