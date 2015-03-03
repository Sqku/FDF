/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 21:28:15 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 21:28:28 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_env *e, char **av)
{
	fill_pallette(e->tab);
	e->nby = nb_line(av[1]);
	e->zoom = 20;
	e->alt = 20.0;
	e->down = 1.0;
	e->move_x = 800;
	e->move_y = 400;
	e->inc = 1.0;
	e->turn = 1.0;
	e->file = av[1];
	e->mlx = mlx_init();
	if (e->mlx == 0)
	{
		ft_putstr_fd("fdf: ca sent le fdp tout d'un coups\n", 2);
		exit (0);
	}
}
