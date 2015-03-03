/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 21:25:21 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 21:39:32 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	f3d_2d(t_3d p3d, t_env *e)
{
	t_point p1;

	p1.x = ((p3d.x * e->turn) - (p3d.y * e->turn)) + e->move_x;
	p1.y = (p3d.z + (p3d.x * e->inc / 2) + (p3d.y * e->inc / 2)) + e->move_y;
	return (p1);
}

int		l_map(int x, int min, int max)
{
	return ((x - min) * (29) / (max - min));
}

void	draw(t_env *e)
{
	t_3d	d0;
	t_3d	d1;
	t_3d	d2;

	draw_x(d0, d1, e, e->coord);
	draw_y(d0, d2, e, e->coord);
}

void	draw_x(t_3d d0, t_3d d1, t_env *e, int **coord)
{
	int		y;
	int		x;
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
			d0.z = (coord[y][x]) * e->alt / 4;
			d1.x = (x + 1) * e->zoom;
			d1.y = y * e->zoom;
			d1.z = (coord[y][x + 1]) * e->alt / 4;
			p0 = f3d_2d(d0, e);
			p1 = f3d_2d(d1, e);
			line(p0, p1, e, e->tab[l_map((coord[y][x] + coord[y][x + 1]) / 2,
						e->min, e->max)]);
			x++;
		}
		y++;
	}
}

void	draw_y(t_3d d0, t_3d d2, t_env *e, int **coord)
{
	int		y;
	int		x;
	t_point	p0;
	t_point	p2;

	x = -1;
	while (++x <= (e->nbx - 1))
	{
		y = -1;
		while (++y < e->nby)
		{
			d0.x = x * e->zoom;
			d0.y = y * e->zoom;
			d0.z = (coord[y][x]) * e->alt / 4;
			d2.x = x * e->zoom;
			d2.y = (y + 1) * e->zoom;
			d2.z = (coord[y + 1][x]) * e->alt / 4;
			p0 = f3d_2d(d0, e);
			p2 = f3d_2d(d2, e);
			line(p0, p2, e, e->tab[l_map((coord[y][x] + coord[y + 1][x]) / 2,
						e->min, e->max)]);
		}
	}
}
