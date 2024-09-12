/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:09:35 by tde-luca          #+#    #+#             */
/*   Updated: 2024/08/19 12:51:51 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_first_line(int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i == 0)
			ft_putchar('A');
		else if (i < width - 1)
			ft_putchar('B');
		else
			ft_putchar('C');
		i++;
	}
}

void	write_middle_line(int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i == 0)
			ft_putchar('B');
		else if (i < width - 1)
			ft_putchar(' ');
		else
			ft_putchar('B');
		i++;
	}
}

void	write_last_line(int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i == 0)
			ft_putchar('A');
		else if (i < width - 1)
			ft_putchar('B');
		else
			ft_putchar('C');
		i++;
	}
}

void	rush(int width, int height)
{
	int	i;

	if (width <= 0 || height <= 0)
		return ;
	i = 0;
	while (i < height)
	{
		if (i == 0)
			write_first_line(width);
		else if (i < height - 1)
			write_middle_line(width);
		else
			write_last_line(width);
		i++;
		ft_putchar('\n');
	}
}
