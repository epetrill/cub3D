/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:52:32 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/06 03:37:45 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"
# include "fcntl.h"
# include "stdio.h"
# include "stdlib.h"
# include "../minilibx-linux/mlx.h"
# include "key_linux.h"
# define TEX_X 64
# define TEX_Y 64

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	int			img_width;
	int			img_height;
}				t_mlx;



/*
**	Structure joueur
*/

typedef struct 	s_player
{
	double 		pos_x;
	double 		pos_y;
	double 		dir_x;
	double 		dir_y;
	double 		plane_x;
	double 		plane_y;
}				t_player;

/*
**	Structure map + info	
*/

typedef struct	s_mapinfo
{
	int			res_x;
	int			res_y;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceil_r;
	int			ceil_g;
	int			ceil_b;
	int			col;
	int			lign;
	int 		start_x;
	int 		start_y;
	int			**texture;
	t_mlx		data;
	t_player	player;
}				t_mapinfo;

/*
**	Fonctions process map check map
*/

char			**ft_error(char *str);
int				ft_checkinf(t_mapinfo *pinfo);
int				ft_isparam(char *str);
int				ft_strncmp(const char *s1, const char *s2, int n);
char			*ft_strdup(const char *s1);
int				ft_atoimod(char *str, int choix);
int				ft_nblen(char *str);
void			ft_afftab(char **map);
char			**ft_realloc(char **map, int size);
char			**ft_cpymap(char *fichier, char **map);
void			ft_freetab(char **map);
int				ft_mapprocess(char **map, t_mapinfo *pinfo);
int				ft_reachinf(char *line, t_mapinfo *pinfo);
int				ft_reachc(char *line, t_mapinfo *pinfo);
int				ft_reachf(char *line, t_mapinfo *pinfo);
int				ft_reachwall(char *line, t_mapinfo *pinfo, int chx);
int				ft_reachres(char *line, t_mapinfo *pinfo);
void			ft_initinfo(t_mapinfo *pinfo);
int				ft_fillpath(char *line, t_mapinfo *pinfo, int chx);
char			*ft_strcpy(char *dest, char *src);
int				ft_wlen(char *str);
void			ft_putstr(char *str);
void			ft_freestruct(t_mapinfo *pinfo);
char			**ft_cleanmap(char **map);
char			**ft_avoidpar(char **map, int i, int size);
int				ft_coor(char *buff, t_mapinfo *pinfo);
int				ft_checkmap2(char **map, t_mapinfo *pinfo);
int				ft_checkmap(char **map, int start, int j, t_mapinfo *pinfo);
int				*ft_colmax(char	**map, t_mapinfo *pinfo);
char			**ft_fillmask(char **map, t_mapinfo *pinfo);
char			**ft_deposemask(char **map, char **mask);
int				ft_checkfill(char **map, t_mapinfo *pinfo, int i, int j);
void			ft_bzero(void *s, size_t n);

/*
**	Fonctions minilibx
*/

int        		mlx_shit(t_mapinfo *pinfo);
int				mlx_open(t_mapinfo *pinfo);
void			resize_res(t_mapinfo *pinfo);

#endif
