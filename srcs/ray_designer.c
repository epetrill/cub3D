/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_designer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:19:05 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 09:56:57 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	texturing_buf(t_mapinfo *pinfo, int x)
{
	int		y;
	int		color;

	y = pinfo->ray.drawstart;
	while (y < pinfo->ray.drawend)
	{
		pinfo->ray.tex_y = (int)pinfo->ray.texpos & (HEIGHT - 1);
		pinfo->ray.texpos += pinfo->ray.step;
		if (pinfo->ray.side == 0 && pinfo->ray.raydir_x > 0)
			color = pinfo->tex[3][HEIGHT * pinfo->ray.tex_y + pinfo->ray.tex_x];
		else if (pinfo->ray.side == 0 && pinfo->ray.raydir_x < 0)
			color = pinfo->tex[2][HEIGHT * pinfo->ray.tex_y + pinfo->ray.tex_x];
		else if (pinfo->ray.side == 1 && pinfo->ray.raydir_y < 0)
			color = pinfo->tex[0][HEIGHT * pinfo->ray.tex_y + pinfo->ray.tex_x];
		else
			color = pinfo->tex[1][HEIGHT * pinfo->ray.tex_y + pinfo->ray.tex_x];
		pinfo->buffer[y][x] = color;
		y++;
	}
}

void	ray_init(t_mapinfo *pinfo, int x)
{
	pinfo->ray.camera_x = 2 * x / (double)pinfo->res_x - 1;
	pinfo->ray.raydir_x = pinfo->player.dir_x + pinfo->player.plane_x
	* pinfo->ray.camera_x;
	pinfo->ray.raydir_y = pinfo->player.dir_y + pinfo->player.plane_y
	* pinfo->ray.camera_x;
	pinfo->ray.map_x = (int)pinfo->player.pos_x;
	pinfo->ray.map_y = (int)pinfo->player.pos_y;
	pinfo->ray.deltadist_x = fabs(1 / pinfo->ray.raydir_x);
	pinfo->ray.deltadist_y = fabs(1 / pinfo->ray.raydir_y);
	pinfo->ray.hit = 0;
}

void        draw_floor_ceiling(t_mapinfo *pinfo)
{
    int x;
    int y;

    y = 0;
    while (y < pinfo->res_y)
    {
        x = 0;
        while (x < pinfo->res_x)
        {
            if (y > pinfo->res_y / 2)
                pinfo->buffer[y][x] = pinfo->hexfloor;
            else
                pinfo->buffer[y][x] = pinfo->hexceil;
            x++;            
        }
        y++;
    }
}

void        designer(t_mapinfo *pinfo)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < pinfo->res_y)
    {
        while (x < pinfo->res_x)
        {
            pinfo->data.img_data[y * pinfo->res_x + x] = pinfo->buffer[y][x];
            x++;
        }
        x = 0;
        y++;
    }
    mlx_put_image_to_window(pinfo->data.ptr, pinfo->data.win, 
    pinfo->data.img, 0, 0);
}

void	launcher(t_mapinfo *pinfo)
{
	int x;

	x = 0;
	draw_floor_ceiling(pinfo);
	while (x < pinfo->res_x)
	{
		ray_init(pinfo, x);
		step_calculation(pinfo);
		hit_analyzing(pinfo);
		wall_distance_calculation(pinfo);
		wall_height_calculation(pinfo);
		tex_calculation(pinfo);
		texturing_buf(pinfo, x);
		pinfo->spribuf[x] = pinfo->ray.perpwalldist;
		x++;
	}
}