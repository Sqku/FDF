/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 12:33:18 by ahua              #+#    #+#             */
/*   Updated: 2015/02/25 18:21:12 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_point p1, t_point p2, t_env *e, int color)
{
	t_line		line;

	line.inc.x = ((p2.x - p1.x) > 0) ? 1 : -1;
	line.inc.y = ((p2.y - p1.y) > 0) ? 1 : -1;
	line.dx = abs(p2.x - p1.x);
	line.dy = abs(p2.y - p1.y);
	line.p1 = p1;
	line.p2 = p2;
	mlx_pixel_put(e->mlx, e->win, line.p1.x, line.p1.y, color);
	if (line.dx > line.dy)
		line_1(line, e, color);
	else
		line_2(line, e, color);
}

void	line_1(t_line line, t_env *e, int color)
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
		mlx_pixel_put(e->mlx, e->win, line.p1.x, line.p1.y, color);
	}
}

void	line_2(t_line line, t_env *e, int color)
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
		mlx_pixel_put(e->mlx, e->win, line.p1.x, line.p1.y, color);
	}
}

t_point	f3d_2d(t_3d p3d, t_env *e)
{
	t_point p1;

	p1.x = ((p3d.x * e->turn) - (p3d.y * e->turn)) + e->move_x;
	p1.y = (p3d.z + ((p3d.x * e->inc) / 2) + ((p3d.y * e->inc) / 2)) + e->move_y;
	return (p1);
}


int		l_map(int x, int min, int max)
{
	return ((x - min) * (29) / (max - min));
}


void	fill_pallette1(int tab[30])
{
	tab[0] = 0x31698A;
	tab[1] = 0x2181AC;
	tab[2] = 0x1199CE;
	tab[3] = 0x01B0F0;
	tab[4] = 0x01B0F0;
	tab[5] = 0x01B0F0;
	tab[6] = 0x01B0F0;
	tab[7] = 0x01B0F0;
	tab[8] = 0x01B0F0;
	tab[9] = 0x01B0F0;
	tab[10] = 0x01B0F0;
	tab[11] = 0xffeb7f;
	tab[12] = 0x71A12F;
	tab[13] = 0x65902a;
	tab[14] = 0x5a8025;
}

void	fill_pallette2(int tab[30])
{
	tab[15] = 0x4f7020;
	tab[16] = 0x5a8025;
	tab[17] = 0x65902a;
	tab[18] = 0x71A12F;
	tab[19] = 0x8a745a;
	tab[20] = 0x8a745a;
	tab[21] = 0x7d6548;
	tab[22] = 0x7d6548;
	tab[23] = 0x705a40;
	tab[24] = 0x705a40;
	tab[25] = 0x645039;
	tab[26] = 0x645039;
	tab[27] = 0xFFFFFF;
	tab[28] = 0xFFFFFF;
	tab[29] = 0xFFFFFF;
}

void	fill_pallette(int tab[30])
{
	fill_pallette1(tab);
	fill_pallette2(tab);
}


void	draw(t_env *e)
{
	int	**coord;
	t_3d	d0;
	t_3d	d1;
	t_3d	d2;
	
	coord = map(e->file, e->nby, e);
	draw_x(d0, d1, e, coord);
	draw_y(d0, d2, e, coord);
}

void	draw_x(t_3d d0, t_3d d1, t_env *e, int **coord)
{
	int	y;
	int	x;
	t_point	p0;
	t_point	p1;

	y = 0;
	while (y <= e->nby)
	{
		x = 0;
		while (x < (e->nbx - 1))
		{
			d0.x = x * e->zoom;
			d0.y = y * e->zoom;
			d0.z = coord[y][x];
			d1.x = (x + 1) * e->zoom;
			d1.y = y * e->zoom;
			d1.z = coord[y][x + 1];
			p0 = f3d_2d(d0, e);
			p1 = f3d_2d(d1, e);
			line(p0, p1, e, e->tab[l_map((d0.z + d1.z) / 2, e->min, e->max)]);
			x++;
		}
		y++;
	}
}

void	draw_y(t_3d d0, t_3d d2, t_env *e, int **coord)
{
	int	y;
	int	x;
	t_point	p0;
	t_point	p2;

	x = 0;
	while (x <= (e->nbx - 1))
	{
		y = 0;
		while (y < e->nby)
		{
			d0.x = x * e->zoom;
			d0.y = y * e->zoom;
			d0.z = coord[y][x];
			d2.x = x * e->zoom;
			d2.y = (y + 1) * e->zoom;
			d2.z = coord[y + 1][x];
			p0 = f3d_2d(d0, e);
			p2 = f3d_2d(d2, e);
			line(p0, p2, e, e->tab[l_map((d0.z + d2.z) / 2, e->min, e->max)]);
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

int	**map(char *file, int nb, t_env *e)
{
	int		fd;
	char	**buff;
	int		**map;
	int		tmp;

	fd = open(file, O_RDONLY);
	if ((buff = (char **)malloc(sizeof(char *) * (nb + 1))) == NULL)
	{
		ft_putstr_fd("malloc fail\n", 2);
		exit (0);
	}
	if ((map = (int **)malloc(sizeof(int *) * (nb + 1))) == NULL)
	{
		ft_putstr_fd("malloc fail\n", 2);
		exit (0);
	}
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
		if (!mapi[i] || !buffer[i])
		{
			ft_putstr_fd("malloc fail\n", 2);
			exit (0);
		}
		buffer[i] = ft_strcpy(buffer[i], line);
		split = ft_strsplit(buffer[i], ' ');
		get_map2(split, mapi, i, e);
		free(buffer[i]);
		free(split);
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
		if (map[i][y] < e->max)
			e->max = map[i][y];
		if (map[i][y] > e->min)
			e->min = map[i][y];
		y++;
		e->nbx = y;
		free(splity[y]);
	}
}

void	redraw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	draw(e);
}


int	mouse_hook(int button, int x, int y, t_env *e)
{
	if ((button == 5) && (e->zoom >= 2))
	{
		e->zoom -= 2;
		redraw(e);
	}
	if ((button == 4) && (e->zoom <= 100))
	{
		e->zoom += 2;
		redraw(e);
	}
	return (0);	
}

int	key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit (0);
	if ((keycode == 65361) && (e->move_x > -300))
	{
		e->move_x -= 50;
		redraw(e);
	}
	if ((keycode == 65363) && (e->move_x < 2200))
	{
		e->move_x += 50;
		redraw(e);
	}
	if ((keycode == 65362) && (e->move_y > -300))
	{
		e->move_y -= 50;
		redraw(e);
	}
	if ((keycode == 65364) && (e->move_y < 1500))
	{
		e->move_y += 50;
		redraw(e);
	}
	if ((keycode == 65453) && (e->inc > 0.0))
	{
		e->inc -= 0.1;
		redraw(e);
	}
	if ((keycode == 65451) && (e->inc < 3.0))
	{
		e->inc += 0.1;
		redraw(e);
	}
	if ((keycode == 65464) && (e->turn > 0.0))
	{
		e->turn -= 0.1;
		redraw(e);
	}
	if ((keycode == 65465) && (e->turn < 3.0))
	{
		e->turn += 0.1;
		redraw(e);
	}
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
	
	if (ac == 2)
	{
		fill_pallette(e.tab);
		e.min = -10000;
		e.max = 10000;
		e.nby = nb_line(av[1]);
		e.zoom = 20;
		e.move_x = 800;
		e.move_y = 400;
		e.inc = 1.0;
		e.turn = 1.0;
		e.file = av[1];
		e.mlx = mlx_init();
		if (e.mlx == 0)
			exit (0);
		e.win = mlx_new_window(e.mlx, 1980, 1400, "FDF");
		e.img = mlx_new_image(e.mlx, 1980, 1400);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	else 
		ft_putstr_fd("usage: ./fdf <map.fdf>\n", 2);
	return (0);
}
