/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 12:33:18 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 21:37:37 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	nb_line(char *file)
{
	int		fd;
	int		i;
	char	*ligne;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("fdf: Map does not exist or is invalid\n", 2);
		exit (0);
	}
	if (get_next_line(fd, &ligne) == -1)
	{
		ft_putstr_fd("fdf: Map is a directory\n", 2);
		exit(0);
	}
	i = 0;
	while (get_next_line(fd, &ligne) > 0)
		i++;
	close(fd);
	return (i);
}

int	mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		if (e->zoom)
			e->zoom--;
		if (e->alt > 0.0)
			e->alt--;
		e->re = 1;
	}
	if (button == 4)
	{
		e->zoom++;
		e->alt++;
		e->re = 1;
	}
	return (0);
}

int	expose_hook(t_env *e)
{
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int	loop_hook(t_env *e)
{
	if (e->re)
	{
		redraw(e);
		e->re = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		init(&e, av);
		e.coord = map(e.file, e.nby, &e);
		e.win = mlx_new_window(e.mlx, SIZE_X, SIZE_Y, "FDF");
		e.img.img = mlx_new_image(e.mlx, SIZE_X, SIZE_Y);
		e.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp, &e.img.sizeline,
				&e.img.endian);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop_hook(e.mlx, loop_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putstr_fd("usage: ./fdf <map.fdf>\n", 2);
	return (0);
}
