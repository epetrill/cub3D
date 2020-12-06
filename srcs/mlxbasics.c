/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxbasics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:40:36 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/06 03:48:53 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

int       mlx_open(t_mapinfo *pinfo)
{
    if ((pinfo->data.ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
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

int        mlx_shit(t_mapinfo *pinfo)
{
    resize_res(pinfo);
    mlx_open(pinfo);
    return (0);
}