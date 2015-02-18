/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 12:33:18 by ahua              #+#    #+#             */
/*   Updated: 2015/02/18 17:48:39 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_point p1, t_point p2, t_env *e)
{
	t_line		line;

	line.inc.x = ((p2.x - p1.x) > 0) ? 1 : -1;
	line.inc.y = ((p2.y - p1.y) > 0) ? 1 : -1;
	line.dx = abs(p2.x - p1.x);
	line.dy = abs(p2.y - p1.y);
	line.p1 = p1;
	line.p2 = p2;
	mlx_pixel_put(e->mlx, e->win, line.p1.x, line.p1.y, 0xFF0000);
	if (line.dx > line.dy)
		line_1(line, e);
	else
		line_2(line, e);
}

void	line_1(t_line line, t_env *e)
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
		mlx_pixel_put(e->mlx, e->win, line.p1.x, line.p1.y, 0xFF0000);
	}
}

void	line_2(t_line line, t_env *e)
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
		mlx_pixel_put(e->mlx, e->win, line.p1.x, line.p1.y, 0xFF0000);
	}
}



t_point	f3d_2d(t_3d p3d)
{
	t_point p1;

	p1.x = ((p3d.x) - (p3d.y)) + 500;
	p1.y = (p3d.z + ((p3d.x) / 2) + ((p3d.y) / 2)) + 500;
	return (p1);
}

/*void	draw(t_env *e)
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
	int	nbc;
	
	coord = map(e->file, nb_line(e->file), e);
	nbc = e->nbx;
	y = 0;
	while (y <= nb_line(e->file) - 1)
	{
		x = 0;
		while (x < (nbc - 1))
		{
			d0.x = x * e->zoom;
			d0.y = y * e->zoom;
			d0.z = coord[y][x];
			d1.x = (x + 1) * e->zoom;
			d1.y = y * e->zoom;
			d1.z = coord[y][x + 1];
			p0 = f3d_2d(d0);
			p1 = f3d_2d(d1);
			line(p0, p1, e);
			x++;
		}
		y++;
	}

	x = 0;
	while (x <= (nbc - 1))
	{
		y = 0;
		while (y < nb_line(e->file) - 1)
		{
			d0.x = x * e->zoom;
			d0.y = y * e->zoom;
			d0.z = coord[y][x];
			d2.x = x * e->zoom;
			d2.y = (y + 1) * e->zoom;
			d2.z = coord[y + 1][x];
			p0 = f3d_2d(d0);
			p2 = f3d_2d(d2);
			line(p0, p2, e);
			y++;
		}
		x++;
	}
}*/

void	draw(t_env *e)
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
	int	nbc;
	
	coord = map(e->file, nb_line(e->file), e);
	nbc = e->nbx;
	y = 0;
	while (y <= nb_line(e->file) - 1)
	{
		x = 0;
		while (x < (nbc - 1))
		{
			d0.x = x * e->zoom;
			d0.y = y * e->zoom;
			d0.z = coord[y][x];
			d1.x = (x + 1) * e->zoom;
			d1.y = y * e->zoom;
			d1.z = coord[y][x + 1];
			p0 = f3d_2d(d0);
			p1 = f3d_2d(d1);
			line(p0, p1, e);
			x++;
		}
		y++;
	}

	x = 0;
	while (x <= (nbc - 1))
	{
		y = 0;
		while (y < nb_line(e->file) - 1)
		{
			d0.x = x * e->zoom;
			d0.y = y * e->zoom;
			d0.z = coord[y][x];
			d2.x = x * e->zoom;
			d2.y = (y + 1) * e->zoom;
			d2.z = coord[y + 1][x];
			p0 = f3d_2d(d0);
			p2 = f3d_2d(d2);
			line(p0, p2, e);
			y++;
		}
		x++;
	}
}

void	draw_x(t_3d d0, t_3d d1, t_env *e, int nby)
{
	int	y;
	int	x;
	t_point	p0;
	t_point	p1;

	y = 0;
	while (y <= nb_line(e->file) - 1)
	{
		x = 0;
		while (x < (nbc - 1))
		{
			d0.x = x * e->zoom;
			d0.y = y * e->zoom;
			d0.z = coord[y][x];
			d1.x = (x + 1) * e->zoom;
			d1.y = y * e->zoom;
			d1.z = coord[y][x + 1];
			p0 = f3d_2d(d0);
			p1 = f3d_2d(d1);
			line(p0, p1, e);
			x++;
		}
		y++;
	}
}

void	draw_y(t_3d d0, t_3d d2, t_env *e, int nby)
{
	int	y;
	int	x;
	t_point	p0;
	t_point	p2;

	x = 0;
	while (x <= (nbc - 1))
	{
		y = 0;
		while (y < nb_line(e->file) - 1)
		{
			d0.x = x * e->zoom;
			d0.y = y * e->zoom;
			d0.z = coord[y][x];
			d2.x = x * e->zoom;
			d2.y = (y + 1) * e->zoom;
			d2.z = coord[y + 1][x];
			p0 = f3d_2d(d0);
			p2 = f3d_2d(d2);
			line(p0, p2, e);
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

/*int	**map(char *file, int nb, t_env *e)
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
			e->nbx = y;
			free(split[y]);
		}
		free(buff[i]);
		free(split);
		ft_putchar('\n');
		i++;
	}
	free(buff);
	close(fd);
	return (map);
}*/

int	**map(char *file, int nb, t_env *e)
{
	int		fd;
	char	**buff;
	int		**map;

	fd = open(file, O_RDONLY);
	buff = (char **)malloc(sizeof(char *) * (nb + 1));
	map = (int **)malloc(sizeof(int *) * (nb + 1));
	get_map(fd, buff, map, e);
	close(fd);
	return (map);
}

void	get_map(int fd, char **buffer, int **mapi, t_env *e)
{
	int		i;
	char	*line;
	char	**split;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		mapi[i] = (int *)malloc(sizeof(int) * (ft_strlen(line) + 1));
		buffer[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		buffer[i] = ft_strcpy(buffer[i], line);
		split = ft_strsplit(buffer[i], ' ');
		get_map2(split, mapi, i, e);
		free(buffer[i]);
		free(split);
		ft_putchar('\n');
		i++;
	}
	free(buffer);
}

void	get_map2(char **splity, int **map, int i, t_env *e)
{
	int y;

	y = 0;
	while (splity[y])
	{
		map[i][y] = ft_atoi(splity[y]) * -1;
		ft_putnbr(map[i][y]);
		ft_putchar(' ');
		y++;
		e->nbx = y;
		free(splity[y]);
	}
}

int	mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse: %d (%d:%d)\n", button, x, y);
	if (button == 5)
	{
		e->zoom--;
		if (e->zoom >= 5)
			draw(e);
	}
	if (button == 4)
	{
		e->zoom++;
		if (e->zoom <= 100)
			draw(e);
	}

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
	draw(e);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	e;

	e.zoom = 20;
	e.file = av[1];
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1980, 1200, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
