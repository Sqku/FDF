/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 21:27:52 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 21:27:58 by ahua             ###   ########.fr       */
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
	ft_pixel_img(e, line.p1.x, line.p1.y, color);
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
		ft_pixel_img(e, line.p1.x, line.p1.y, color);
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
		ft_pixel_img(e, line.p1.x, line.p1.y, color);
	}
}

void	ft_pixel_img(t_env *e, int x, int y, int color)
{
	if (x > 0 && x < SIZE_X && y > 0 && y < SIZE_Y)
		ft_memcpy(&e->img.data[(x * 4) + (y * e->img.sizeline)],\
				&color, (size_t)(sizeof(int)));
}
