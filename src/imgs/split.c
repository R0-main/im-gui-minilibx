/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:18:34 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/04 12:06:56 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

int	get_tall(t_img *img, int x, int y_max)
{
	int	y;
	int	total;

	y = y_max;
	total = 0;
	while (y >= 0)
	{
		if (*get_pixel(img, (t_uvec_2){x, y}) == 0xFF000000)
			break ;
		total += 1;
		y--;
	}
	return (total);
}

t_rectangle	get_max_area(t_img *img, int y_max)
{
	t_uvec_2	c;
	t_rectangle	max;
	int			x2;
	int			x3;
	int			current_tall;

	c = (t_uvec_2){0, 0};
	x2 = 0;
	x3 = 0;
	ft_bzero(&max, sizeof(t_rectangle));
	current_tall = 0;
	while ((int)c.x < img->width)
	{
		x2 = (int)c.x;
		current_tall = get_tall(img, (int)c.x, y_max);

		while (x2 > 0 && get_tall(img, x2 - 1, y_max) >= current_tall)
			x2--;

		x3 = x2;
		while (x2 >= 0 && x2 < img->width && get_tall(img, x2, y_max) >= current_tall)
			x2++;
		if ((x2 - x3) * current_tall > max.area)
			max = (t_rectangle){(t_uvec_2){x3, (y_max - current_tall) + 1}, (t_uvec_2){(x2 - x3),
				current_tall}, (x2 - x3) * current_tall};
		c.x++;
	}
	return (max);
}

t_rectangle	get_largest_rectangle_available_img(t_img *img)
{
	int			y;
	t_rectangle	max;
	t_rectangle	tmp;

	y = 0;
	ft_bzero(&max, sizeof(t_rectangle));
	ft_bzero(&tmp, sizeof(t_rectangle));
	while (y < img->height)
	{
		tmp = get_max_area(img, y);
		if (tmp.area > max.area)
			max = tmp;
		y++;
	}
	// printf("max area : %d at x : %d, y : %d | w : %d, h : %d\n", max.area,
	// 	max.pos.x, max.pos.y, max.length.x, max.length.y);
	return (max);
}
