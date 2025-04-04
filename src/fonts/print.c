/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:04:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/04 12:05:36 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void igmlx_put_str(t_igmlx *igmlx, char *str, char *font_name, void *win, t_uvec_2 pos)
{
	t_igmlx_font *font;
	int i;

	i = -1;
	font = get_font(igmlx, font_name);
	if (!font)
	{
		_warning("tried to print with unknown font!");
		return;
	}
	while (str[++i])
	{
		if (i == 0)
			igmlx_put_alpha_to_window(igmlx, win, font->letters[(int)str[i]], (t_uvec_2){pos.x + (48 * i), pos.y});
		else
			igmlx_put_alpha_to_window(igmlx, win, font->letters[(int)str[i]], (t_uvec_2){pos.x + (48 * i) + font->inner_offset.x * i, pos.y});
	}
	_debug("printed");
}
