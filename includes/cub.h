/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:52:32 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 21:12:52 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"
# include "fcntl.h"
# include "stdio.h"
# include "stdlib.h"
# include "../minilibx-linux/mlx.h"
# include "math.h"
# include "string.h"

# define WIDTH 64
# define HEIGHT 64

# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362

# define KEY_ESC 65307
# define KEY_SPACE 32
# define KEY_ENTER 65293

# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100

/*
**		Structure xpm
*/

typedef struct	s_xpm
{
	void		*sprite;
	char		*path_sprite;
	int			width;
	int			height;
}				t_xpm;

/*
**		Structure raycasting
*/

typedef struct	s_ray
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		texpos;
}				t_ray;

/*
**		Structure calcul sprite
*/

typedef struct	s_spray
{
	double		x;
	double		y;
	double		inversion;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			v_move_screen;
	int			height;
	int			width;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			tex_x;
	int			tex_y;
}				t_spray;

/*
**	Structure sprite
*/

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
}				t_sprite;

/*
**	Structure mlx data
*/

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*img_data;
	int			bpp;
	int			size_l;
	int			endian;
	int			img_width;
	int			img_height;
}				t_mlx;

/*
**	Structure joueur
*/

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		old_dir_x;
	double		old_plane_x;
	double		movespeed;
	double		rotspeed;
}				t_player;

/*
**	Structure map + info
*/

typedef struct	s_mapinfo
{
	char		**map;
	int			res_x;
	int			res_y;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*path_sprites;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceil_r;
	int			ceil_g;
	int			ceil_b;
	int			col;
	int			lign;
	int			start_x;
	int			start_y;
	int			cardinal;
	int			**tex;
	int			**buffer;
	double		*spribuf;
	int			counter_sprite;
	int			numsprite;
	int			hexfloor;
	int			hexceil;
	t_mlx		data;
	t_player	player;
	t_spray		s_ray;
	t_spray		spray;
	t_sprite	*sprite;
	t_ray		ray;
	t_xpm		xpm;
}				t_mapinfo;

/*
**	Fonctions process map check map
*/

int				ft_iscardi(char c);
char			**ft_error(char *str);
void			*ft_calloc(size_t count, size_t size);
int				ft_checkinf(t_mapinfo *map);
int				ft_isparam(char *str);
int				ft_strncmp(const char *s1, const char *s2, int n);
char			*ft_strdup(const char *s1);
int				ft_atoimod(char *str, int choix);
int				ft_nblen(char *str);
char			**ft_realloc(char **map, int size);
char			**ft_cpymap(char *fichier, char **map);
void			ft_freetab(char **map);
int				ft_mapprocess(t_mapinfo *map);
int				ft_reachinf(char *line, t_mapinfo *map);
int				ft_reachc(char *line, t_mapinfo *map);
int				ft_reachf(char *line, t_mapinfo *map);
int				ft_reachwall(char *line, t_mapinfo *map, int chx);
int				ft_reachres(char *line, t_mapinfo *map);
void			ft_initinfo(t_mapinfo *map);
int				ft_fillpath(char *line, t_mapinfo *map, int chx);
char			*ft_strcpy(char *dest, char *src);
int				ft_wlen(char *str);
void			ft_putstr(char *str);
void			ft_freestruct(t_mapinfo *map);
char			**ft_cleanmap(char **map);
char			**ft_avoidpar(char **map, int i, int size);
int				ft_coor(char *buff, t_mapinfo *map);
int				ft_checkmap2(t_mapinfo *map);
int				ft_checkmap(int start, int j, t_mapinfo *map);
int				*ft_colmax(t_mapinfo *map);
char			**ft_fillmask(t_mapinfo *map);
char			**ft_deposemask(char **mask, t_mapinfo *map);
int				ft_checkfill(t_mapinfo *map, int i, int j);
void			ft_bzero(void *s, size_t n);
int				ft_isthing(char c);
void			ft_startpos(t_mapinfo *map, char c, int i, int j);

/*
**	Fonctions minilibx
*/

int				mlx_shit(t_mapinfo *map);
int				mlx_open(t_mapinfo *map);
void			resize_res(t_mapinfo *map);
int				buffer_init(t_mapinfo *map);
int				texture_init(t_mapinfo *map);
void			sprite_usher(t_mapinfo *map, int i, int x, int y);
int				sprite_init(t_mapinfo *map);
void			img_loader(t_mapinfo *map, int *texture, char *path);
void			tex_loader(t_mapinfo *map);
void			angle_setter(t_mapinfo *map);
void			east_setter(t_mapinfo *map);
void			north_setter(t_mapinfo *map);
void			south_setter(t_mapinfo *map);
void			west_setter(t_mapinfo *map);
void			moving_up(t_mapinfo *map);
void			moving_down(t_mapinfo *map);
void			moving_left(t_mapinfo *map);
void			moving_right(t_mapinfo *map);
int				key_release(int code, t_mapinfo *map);
int				key_press(int code, t_mapinfo *map, int choice);
void			watching_left(t_mapinfo *map);
void			watching_right(t_mapinfo *map);
int				close_game(t_mapinfo *map);
void			draw_floor_ceiling(t_mapinfo *map);
void			designer(t_mapinfo *map);
void			ft_rgbtohex(t_mapinfo *map);
int				main_loop(t_mapinfo *map);
void			launcher(t_mapinfo *map);
void			tex_calculation(t_mapinfo *map);
void			wall_height_calculation(t_mapinfo *map);
void			wall_distance_calculation(t_mapinfo *map);
void			hit_analyzing(t_mapinfo *map);
void			step_calculation(t_mapinfo *map);
void			texturing_buf(t_mapinfo *map, int x);
void			get_sprite_color(t_mapinfo *map, int stripe);
void			calculate_sprite_width(t_mapinfo *map);
void			calculate_sprite_height(t_mapinfo *map);
void			translating_sprite(t_mapinfo *map, int i);
void			spriter(t_mapinfo *map);
void			sprite_mapper(t_mapinfo *map);
void			sprite_sorter(t_mapinfo *map);

#endif
