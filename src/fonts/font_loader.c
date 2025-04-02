/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:20 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/02 12:34:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

static void	init_letters_images(t_igmlx *igmlx, t_igmlx_font *font,
		t_img *font_img)
{
	char c;

	c = -1;
	while (++c <= CHAR_MAX)
	{
		font->letters[c] = mlx_new_image(igmlx->mlx, 48, 48);
		if (!font->letters[c])
		{
			_error("mlx_new_image failed!");
			return ;
		}
		igmlx_copy_to_dest(font_img, (t_uvec_2){(c * 48) % (8 * 48), (c * 48) % (16 * 48)}, (t_uvec_2){48, 48}, font->letters[c], (t_uvec_2){0, 0});
	}
}

void	igmlx_load_font(t_igmlx *igmlx, char *path)
{
	t_igmlx_font	*font;
	t_img			*img;

	font = balloc(sizeof(t_igmlx_font));
	if (!font)
		return ;
	img = mlx_xpm_file_to_image(igmlx->mlx, path, NULL, NULL);
	if (!img)
	{
		_error("failed to load xpm file of a font");
		return ;
	}
	init_letters_images(igmlx, font, img);
	ft_lstadd_front(&igmlx->fonts, ft_lstnew(font));
}
