/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 12:33:18 by ahua              #+#    #+#             */
/*   Updated: 2015/02/11 19:05:24 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void ligne(t_point p1, t_point p2, void *mlx, void *win) 
{
	t_line	ligne;
	
	ligne.inc.x = ((p2.x - p1.x) > 0) ? 1 : -1;
	ligne.inc.y = ((p2.y - p1.y) > 0) ? 1 : -1;
	ligne.dx = abs(p2.x - p1.x);
	ligne.dy = abs(p2.y - p1.y);
	ligne.p1 = p1;
	ligne.p1 = p2;
	mlx_pixel_put(mlx, win, ligne.p1.x, ligne.p1.y, 0xFF0000);
	if (ligne.dx > ligne.dy) 
		ligne1(ligne, mlx, win);
	else 
		ligne2(ligne, mlx, win);
}

void	ligne1(t_line ligne, void *mlx, void *win)
{	
	int	i;
	int	cumul;

	cumul = ligne.dx / 2;
	i = 1;
	while (i++ <= ligne.dx)
	{
		ligne.p1.x += ligne.inc.x;
		cumul += ligne.dy;
		if (cumul >= ligne.dx)
		{
			cumul -= ligne.dx;
			ligne.p1.y += ligne.inc.y;
		}
		mlx_pixel_put(mlx, win, ligne.p1.x, ligne.p1.y, 0xFF0000);
	}
}

void	ligne2(t_line ligne, void *mlx, void *win)
{
	int	i;
	int	cumul;

	cumul = ligne.dy / 2;
	i = 1;
	while (i++ <= ligne.dy)
	{
		ligne.p1.y += ligne.inc.y;
		cumul += ligne.dx;
		if (cumul >= ligne.dy)
		{
			cumul -= ligne.dy;
			ligne.p1.x += ligne.inc.x;
		}
		mlx_pixel_put(mlx, win, ligne.p1.x, ligne.p1.y, 0xFF0000);
	}
}*/



void	line(t_point p1, t_point p2, void *mlx, void *win)
{
	t_line		line;

	line.inc.x = ((p2.x - p1.x) > 0) ? 1 : -1;
	line.inc.y = ((p2.y - p1.y) > 0) ? 1 : -1;
	line.dx = abs(p2.x - p1.x);
	line.dy = abs(p2.y - p1.y);
	line.p1 = p1;
	line.p2 = p2;
	mlx_pixel_put(mlx, win, line.p1.x, line.p1.y, 0xFF0000);
	if (line.dx > line.dy)
		line_1(line, mlx, win);
	else
		line_2(line, mlx, win);
}

void	line_1(t_line line, void *mlx, void *win)
{
	int			i;
	int			cumul;

	i = 1;
	cumul = line.dx / 2;
	while (i++ <= line.dx)
	{
		line.p1.x += line.inc.x;
		cumul += line.dy;
		if (cumul >= line.dx)
		{
			cumul -= line.dx;
			line.p1.y += line.inc.y;
		}
		mlx_pixel_put(mlx, win, line.p1.x, line.p1.y, 0xFF0000);
	}
}

void	line_2(t_line line, void *mlx, void *win)
{
	int			i;
	int			cumul;

	i = 1;
	cumul = line.dy / 2;
	while (i++ <= line.dy)
	{
		line.p1.y += line.inc.y;
		cumul += line.dx;
		if (cumul >= line.dy)
		{
			cumul -= line.dy;
			line.p1.x += line.inc.x;
		}
		mlx_pixel_put(mlx, win, line.p1.x, line.p1.y, 0xFF0000);
	}
}



t_point	f3d_2d(t_3d p3d)
{
	t_point p1;

	p1.x = ((p3d.x) - (p3d.y)) + 500;
	p1.y = (p3d.z + ((p3d.x) / 2) + ((p3d.y) / 2)) + 300;
	return (p1);
}

void	draw(void *mlx, void *win, char *file)
{
	int	**coord;
	t_3d	d0;
	t_3d	d1;
	t_3d	d2;
	t_point	p0;
	t_point	p1;
	t_point	p2;
	int	y;
	int	x;
	
	coord = map(file, nb_line(file));
	y = 0;
	while (y <= nb_line(file) - 1)
	{
		x = 0;
		while (x < 20)
		{
			d0.x = x * 20;
			d0.y = y * 20;
			d0.z = coord[y][x];
			d1.x = (x + 1) * 20;
			d1.y = y * 20;
			d1.z = coord[y][x + 1];
			p0 = f3d_2d(d0);
			p1 = f3d_2d(d1);
			line(p0, p1, mlx, win);
			x++;
		}
		y++;
	}

	x = 0;
	while (x <= 20)
	{
		y = 0;
		while (y < nb_line(file) - 1)
		{
			d0.x = x * 20;
			d0.y = y * 20;
			d0.z = coord[y][x];
			d2.x = x * 20;
			d2.y = (y + 1) * 20;
			d2.z = coord[y + 1][x];
			p0 = f3d_2d(d0);
			p2 = f3d_2d(d2);
			line(p0, p2, mlx, win);
			y++;
		}
		x++;
	}
}

int	nb_line(char *file)
{
	int	fd;
	int	i;
	char	*ligne;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &ligne) > 0)
		i++;
	close(fd);
	return (i);
}

int	**map(char *file, int nb)
{
	int		fd;
	char	**buff;
	int		i;
	char	*line;
	int		**map;
	char	**split;
	int		y;

	fd = open(file, O_RDONLY);
	buff = (char **)malloc(sizeof(char *) * (nb + 1));
	map = (int **)malloc(sizeof(int *) * (nb + 1));
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = (int *)malloc(sizeof(int) * (ft_strlen(line) + 1));
		buff[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		buff[i] = ft_strcpy(buff[i], line);
		split = ft_strsplit(buff[i], ' ');
		y = 0;
		while (split[y])
		{
			map[i][y] = ft_atoi(split[y]) * -1;
			ft_putnbr(map[i][y]);
			ft_putchar(' ');
			y++;
		}
		free(buff[i]);
		free(split);
		ft_putchar('\n');
		i++;
	}
	close(fd);
	return (map);
}

int	mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);	
}

int	key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit (0);
	return (0);
}
int	expose_hook(t_env *e)
{
	draw(e->mlx, e->win, e->file);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	e;

	e.file = av[1];
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1980, 1200, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
