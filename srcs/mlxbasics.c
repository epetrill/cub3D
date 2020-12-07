/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxbasics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:40:36 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 03:43:20 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

int       mlx_open(t_mapinfo *pinfo)
{
    if ((pinfo->data.win = mlx_new_window(pinfo->data.ptr, pinfo->res_x, pinfo->res_y, "Cub3D")) == NULL)
        return (EXIT_FAILURE);
    mlx_loop(pinfo->data.ptr);
    return (EXIT_SUCCESS);
}

void       resize_res(t_mapinfo *pinfo)
{
    int resX;
    int resY;

    mlx_get_screen_size(pinfo->data.ptr, &resX, &resY);
    if(pinfo->res_x > resX)
        pinfo->res_x = resX;
    if(pinfo->res_y > resY)
        pinfo->res_y = resY;
}

int       cross_close(t_mapinfo *pinfo)
{
    ft_putstr("Vous avez quitte avec la croix !\n");
    return (key_press(KEY_ESC, pinfo, 118));
}

int        mlx_shit(t_mapinfo *pinfo)
{
    if ((pinfo->data.ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    resize_res(pinfo);
    mlx_open(pinfo);
    buffer_init(pinfo);
    texture_init(pinfo);
    sprite_init(pinfo);
    tex_loader(pinfo);
    angle_setter(pinfo);
    if ((pinfo->data.win = mlx_new_window(pinfo->data.ptr, pinfo->res_x, pinfo->res_y
    , "Cub3D")) == NULL)
        return(-1);
    if ((pinfo->data.img = mlx_new_image(pinfo->data.ptr, pinfo->res_x, pinfo->res_y))
    == NULL)
        return(-1);
    if((pinfo->data.img_data = (int *)mlx_get_data_addr(pinfo->data.img,
    &pinfo->data.bpp, &pinfo->data.size_l, &pinfo->data.endian)) == NULL)
        return(-1);
    mlx_hook(pinfo->data.win, 3, 1, &key_release, pinfo);
    mlx_hook(pinfo->data.win, 2, 1, &key_press, pinfo);
    mlx_hook(pinfo->data.win, 33, 0, &cross_close, pinfo);
    mlx_loop_hook(pinfo->data.ptr, &main_loop, pinfo);
    mlx_loop(pinfo->data.ptr);
    return (0);
}