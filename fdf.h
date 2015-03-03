/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:48:18 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 21:40:54 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define SIZE_X 1920
# define SIZE_Y 1080

typedef	struct	s_3d
{
	int	x;
	int	y;
	int	z;
}				t_3d;

typedef struct	s_img
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	void	*img;
}				t_img;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	char	*file;
	int		nbx;
	int		nby;
	int		zoom;
	int		c;
	int		tab[30];
	int		min;
	int		max;
	int		move_x;
	int		move_y;
	float	inc;
	float	turn;
	t_img	img;
	int		**coord;
	float	alt;
	int		re;
	float	down;
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

void			line(t_point p1, t_point p2, t_env *e, int color);
void			line_1(t_line line, t_env *e, int color);
void			line_2(t_line line, t_env *e, int color);
void			draw(t_env *e);
void			draw_x(t_3d d0, t_3d d1, t_env *e, int **coord);
void			draw_y(t_3d d0, t_3d d2, t_env *e, int **coord);
void			redraw(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				key_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);
int				get_next_line(int fd, char **line);
t_point			f3d_2d(t_3d p3d, t_env *e);
int				nb_line(char *file);
int				**map(char *file, int nb, t_env *e);
void			get_map(int fd, int **mapi, t_env *e);
void			get_map2(char **splity, int **map, int i, t_env *e);
void			fill_pallette1(int tab[30]);
void			fill_pallette2(int tab[30]);
void			fill_pallette(int tab[30]);
int				l_map(int x, int min, int max);
void			ft_pixel_img(t_env *e, int x, int y, int color);
void			move_x(int keycode, t_env *e);
void			move_y(int keycode, t_env *e);
void			move_inc(int keycode, t_env *e);
void			init(t_env *e, char **av);
void			init_v(t_env *e);
void			restart(int keycode, t_env *e);
#endif
