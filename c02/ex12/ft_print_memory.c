/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:46:40 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/21 17:10:28 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_puthex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	print_address_and_content(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_puthex(addr[i]);
		else
			ft_putstr("  ");
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	line_size;

	i = 0;
	while (i < size)
	{
		if (size - i >= 16)
			line_size = 16;
		else
			line_size = size - i;
		print_address_and_content((unsigned char *)addr + i, line_size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}

// int    main(void)
// {
// 	char str[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on "
// 	             "peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
//     ft_print_memory(str, sizeof(str));
//     return (0);
// }
