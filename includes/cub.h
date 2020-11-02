#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"
# include "fcntl.h"
# include "stdio.h"
# include "stdlib.h"

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
}				t_mapinfo;

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
int				ft_checkmap2(char **map);
int				ft_checkmap(char **map);
int				*ft_colmax(char	**map);
char			**ft_fillmask(char **map);
char			**ft_deposemask(char **map, char **mask);
void			ft_checkfill(char **map);
void			ft_bzero(void *s, size_t n);

#endif