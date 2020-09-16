/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:25:34 by skarry            #+#    #+#             */
/*   Updated: 2020/09/08 15:25:40 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			my_mlx_pixel_put(pix *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			getpixelcolor(pix *img, int x, int y)
{
	if (!img->width || !img->height)
		return (0);
	x = abs(x);
	y = abs(y);
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int*)(img->addr + ((x + (y * img->width))\
		* (img->bits_per_pixel / 8))));
}

void			all_paint(data_cub *data, pix *img, void *mlx)
{
	data->win = mlx_new_window(mlx, data->r1, data->r2, "cub3D");
	img->img = mlx_new_image(mlx, data->r1, data->r2);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,\
					&img->line_length, &img->endian);
	get_all_texture(&*data, mlx, &data->txt);
	put_map(&*data, &*img);
	mlx_put_image_to_window(mlx, data->win, img->img, 0, 0);
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