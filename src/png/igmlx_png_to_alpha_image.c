/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   igmlx_png_to_alpha_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:26:47 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/06 10:06:40 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_alpha_img	*igmlx_png_to_alpha_image(t_igmlx *igmlx, const char *path)
{
	int fd;

	fd = igmlx_open_png_file(path);
	if (fd == -1)
		return (NULL);
	(void)igmlx;
	return (NULL);
}
