/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:29:07 by skarry            #+#    #+#             */
/*   Updated: 2020/09/15 18:29:09 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		get_one_texture(void *mlx, pix *n, char *no)
{
	n->img = mlx_xpm_file_to_image(mlx, no, &n->width, &n->height);
	if (n->img == NULL)
		ft_exit("Invalid texture");
	else
		n->addr = mlx_get_data_addr(n->img, &n->bits_per_pixel,\
				&n->line_length, &n->endian);
}

void		get_all_texture(data_cub *data, void *mlx, txt *txt)
{
	get_one_texture(mlx, &txt->n, data->no);
	get_one_texture(mlx, &txt->s, data->so);
	get_one_texture(mlx, &txt->e, data->we);
	get_one_texture(mlx, &txt->w, data->ea);
	get_one_texture(mlx, &txt->sp, data->s);
}
