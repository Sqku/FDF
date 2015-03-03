/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 21:29:20 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 22:19:53 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw(t_env *e)
{
	ft_bzero(e->img.data, SIZE_X * SIZE_Y * 4);
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
}

void	move_x(int keycode, t_env *e)
{
	if (keycode == 123)
	{
		e->move_x -= 50;
		e->re = 1;
	}
	if (keycode == 124)
	{
		e->move_x += 50;
		e->re = 1;
	}
}

void	move_y(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		e->move_y -= 50;
		e->re = 1;
	}
	if (keycode == 125)
	{
		e->move_y += 50;
		e->re = 1;
	}
}

void	move_inc(int keycode, t_env *e)
{
	if ((keycode == 78) && (e->inc > 0.0))
	{
		e->inc -= 0.1;
		e->re = 1;
	}
	if ((keycode == 69) && (e->inc < 3.0))
	{
		e->inc += 0.1;
		e->re = 1;
	}
	if ((keycode == 91) && (e->turn > 0.0))
	{
		e->turn -= 0.1;
		e->re = 1;
	}
	if ((keycode == 92) && (e->turn < 3.0))
	{
		e->turn += 0.1;
		e->re = 1;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
	move_x(keycode, e);
	move_y(keycode, e);
	move_inc(keycode, e);
	restart(keycode, e);
	if (keycode == 86)
	{
		e->alt -= 1.0;
		e->re = 1;
	}
	if (keycode == 89)
	{
		e->alt += 1.0;
		e->re = 1;
	}
	return (0);
}
