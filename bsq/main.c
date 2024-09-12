/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:55:56 by naharumi          #+#    #+#             */
/*   Updated: 2024/09/05 16:32:51 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_error("error\n");
		return (-1);
	}
	return (fd);
}

t_map	*initialize_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error("error\n");
	return (map);
}

void	process_input(int fd, t_map *map)
{
	if (read_file(fd, map) != NULL)
	{
		solve_bsq(map);
		print_map(map);
	}
	else
		ft_error("map error\n");
	if (fd != 0)
		close(fd);
}

void	process_all_inputs(int ac, char **av, t_map *map)
{
	int	i;
	int	fd;

	if (ac < 2)
		process_input(0, map);
	else
	{
		i = 1;
		while (i < ac)
		{
			fd = open_file(av[i]);
			if (fd != -1)
				process_input(fd, map);
			i++;
			write(1, "\n", 1);
		}
	}
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = initialize_map();
	if (!map)
		return (1);
	process_all_inputs(ac, av, map);
	free(map);
	return (0);
}
