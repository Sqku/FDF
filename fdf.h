/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:48:18 by ahua              #+#    #+#             */
/*   Updated: 2015/02/11 18:55:42 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef	struct	s_3d
{
	int	x;
	int	y;
	int	z;
}				t_3d;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	char	*file;
	int		nbx;
}				t_env;

typedef	struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef	struct	s_line
{
	t_point	p1;
	t_point	p2;
	t_point	inc;
	int		dx;
	int		dy;
}				t_line;

void			line(t_point p1, t_point p2, void *mlx, void *win);
void			line_1(t_line line, void *mlx, void *win);
void			line_2(t_line line, void *mlx, void *win);
void			draw(void *mlx, void *win, char *file);
int				mouse_hook(int button, int x, int y, t_env *e);
int				key_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);
int				get_next_line(int fd, char **line);
t_point			f3d_2d(t_3d p3d);
int				nb_line(char *file);
int				**map(char *file, int nb_line);

#endif
