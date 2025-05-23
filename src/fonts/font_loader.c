/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:20 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/28 13:52:14 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

static void	init_letters_images(t_igmlx *igmlx, t_igmlx_font *font,
		t_img *font_img)
{
	char c;
	int y;
	int x;
	t_img *tmp;
	// t_img *upscaled;

	c = -1;
	y = 0;
	x = 0;
	while (++c < CHAR_MAX)
	{
		tmp = mlx_new_image(igmlx->mlx, 48, 48);
		if (!tmp)
		{
			_error("mlx_new_image failed!");
			return ;
		}
		if (x == 16)
		{
			y++;
			x = 0;
		}
		igmlx_copy_to_dest(font_img, (t_uvec_2){x * 48, y * 48}, (t_uvec_2){48, 48}, tmp, (t_uvec_2){0, 0});
		igmlx_apply_color_filter(tmp, font->color);
		// upscaled = igmlx_upscale_img(igmlx, tmp, font->size_mutliplier);
		// if (upscaled != tmp)
		// 	mlx_destroy_image(igmlx->mlx, tmp);
		font->letters[(int)c] = tmp;
		// mlx_destroy_image(igmlx->mlx, upscaled);
		x++;
	}
}

void	igmlx_load_font(t_igmlx *igmlx, char *path, t_igmlx_font_params params)
{
	t_igmlx_font	*font;
	t_img			*img;

	if (!path)
		return;
	if (get_font(igmlx, path))
	{
		_warning("tried to load the same font twice!");
		return ;
	}
	font = balloc(sizeof(t_igmlx_font));
	if (!font)
		return ;
	font->color = params.color;
	font->size_mutliplier = params.size_multiplier;
	font->inner_offset = params.inner_offset;
	font->path = path;
	img = mlx_xpm_file_to_image(igmlx->mlx, path, (int *)&font->length.x, (int *)&font->length.y);
	if (!img)
	{
		_error("failed to load xpm file of a font");
		return ;
	}
	init_letters_images(igmlx, font, img);
	mlx_destroy_image(igmlx->mlx, img);
	ft_lstadd_front(&igmlx->fonts, ft_lstnew(font));
}
