/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 21:27:29 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 21:40:08 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**map(char *file, int nb, t_env *e)
{
	int		fd;
	int		**map;

	fd = open(file, O_RDONLY);
	if ((map = (int **)malloc(sizeof(int *) * (nb + 1))) == NULL)
	{
		ft_putstr_fd("malloc fail\n", 2);
		exit (0);
	}
	get_map(fd, map, e);
	close(fd);
	return (map);
}

void	get_map(int fd, int **mapi, t_env *e)
{
	int		i;
	char	*line;
	char	**split;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		mapi[i] = (int *)malloc(sizeof(int) * (ft_strlen(line) + 1));
		if (!mapi[i])
		{
			ft_putstr_fd("malloc fail\n", 2);
			exit (0);
		}
		split = ft_strsplit(line, ' ');
		get_map2(split, mapi, i, e);
		free(split);
		i++;
	}
}

void	get_map2(char **splity, int **map, int i, t_env *e)
{
	int y;

	y = 0;
	if (!i)
	{
		e->max = ft_atoi(splity[0]) * -1;
		e->min = e->max;
	}
	while (splity[y])
	{
		map[i][y] = ft_atoi(splity[y]) * -1;
		if (map[i][y] < e->max)
			e->max = map[i][y];
		if (map[i][y] > e->min)
			e->min = map[i][y];
		y++;
		e->nbx = y;
		free(splity[y]);
	}
}
