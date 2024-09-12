/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:30:56 by lebricio          #+#    #+#             */
/*   Updated: 2024/09/05 18:53:53 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*tab;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].copy = ft_strdup(av[i]);
		tab[i].str = av[i];
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

/*
int    main(void)
{
	t_stock_str    *tab;
	char        *strs[4];
	int            size;

	size = 4;
	strs[0] = "hello";
	strs[1] = "hoje é um bom dia";
	strs[2] = "hello, world!";
	strs[3] = "tchau :)";
	tab = ft_strs_to_tab(size, strs);
	ft_show_tab(ft_strs_to_tab(size, strs));
	free(tab);
	return (0);
}
*/
