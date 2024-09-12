/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:35:30 by lebricio          #+#    #+#             */
/*   Updated: 2024/09/05 12:39:35 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

typedef struct s_map
{
	char	empty;
	char	full;
	char	obstacle;
	int		cols;
	int		rows;
	char	**matrix;
}	t_map;

typedef struct s_dp
{
	int		*prev_dp;
	int		*curr_dp;
	int		max_size;
	int		max_row;
	int		max_col;
}	t_dp;

typedef struct s_max_info
{
	int		max_size;
	int		max_row;
	int		max_col;
}	t_max_info;

typedef struct s_context
{
	t_map		*map;
	t_max_info	*max_info;
}	t_context;

t_map	*read_file(int fd, t_map *map);
char	*init_matrix(t_map *map, char *file_buf, int *i, int size);
char	*get_line(t_map *map, char *file_buf, int *i);
char	*ft_strjoin_bsq(char *s1, const size_t size1, char *s2,
			const size_t size2);
int		ft_strlen(char *str);
int		ft_error(char *str);
int		solve_bsq(t_map *map);
int		ft_strcpy(char *dst, const char *src, const size_t size);
void	print_map(t_map *map);
void	free_map_matrix(t_map *map);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	update_dp_and_find_max(t_map *map, int *prev_dp, int *curr_dp,
			t_max_info *max_info);
char	*ft_strjoin(char *s1, char *s2);
int		check_params(char c);

#endif
