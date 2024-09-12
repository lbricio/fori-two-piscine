/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-luca <tde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:01:58 by lebricio          #+#    #+#             */
/*   Updated: 2024/08/18 15:54:46 by tde-luca         ###   ########.fr       */
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
			ft_putchar('C');
		else if (i < width - 1)
			ft_putchar('B');
		else
			ft_putchar('A');
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
