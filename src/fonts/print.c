/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:04:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/28 14:06:19 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void igmlx_put_str_to_buffer(t_igmlx *igmlx, char *str, char *font_name, t_img *buffer, t_uvec_2 pos)
{
	t_igmlx_font *font;
	int i;
	int y;

	y = 0;
	i = -1;
	font = get_font(igmlx, font_name);
	if (!font)
	{
		_warning("tried to print with unknown font!");
		return;
	}
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			y++;
			continue;
		}
		if (i == 0)
			igmlx_copy_to_dest_ignore_null(font->letters[(int)str[i]], (t_uvec_2){0, 0}, (t_uvec_2){48, 48}, buffer, (t_uvec_2){pos.x + (48 * i), pos.y + (y * 48)});
		else
			igmlx_copy_to_dest_ignore_null(font->letters[(int)str[i]],  (t_uvec_2){0, 0}, (t_uvec_2){48, 48}, buffer, (t_uvec_2){pos.x + (48 * i) - font->inner_offset.x * i, pos.y + (y * 48)});
	}
	_debug("printed");
}
