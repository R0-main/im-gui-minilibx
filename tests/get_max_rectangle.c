/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_rectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 02:04:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 15:09:27 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_tall(int *tab, int x, int height, int y_max)
{
	int	y;
	int	total;

	y = y_max;
	total = 0;
	while (y >= 0)
	{
		if (tab[y * 5 + x] == 0)
			break ;
		total += tab[y * 5 + x];
		y--;
	}
	return (total);
}

int	get_max_area(int *tab, int width, int height, int y_max)
{
	int	x;
	int	x2;
	int	x3;
	int	y;
	int	max;
	int	maxX;
	int	maxY;
	int	current_tall;

	x = 0;
	x2 = 0;
	x3 = 0;
	y = 0;
	max = 0;
	maxX = 0;
	maxY = 0;
	current_tall = 0;
	while (x < width)
	{
		x2 = x;
		current_tall = get_tall(tab, x, height, y_max);
		printf("	%d | taille : %d\n", y_max, current_tall);
		while (x2 > 0 && get_tall(tab, x2 - 1, height, y_max) >= current_tall)
			x2--;
		x3 = x2;
		while (x2 < width && get_tall(tab, x2, height, y_max) >= current_tall)
			x2++;
		if ((x2 - x3) * current_tall > max)
		{
			max = (x2 - x3) * current_tall;
			maxX = x;
			maxY = y;
		}
		x++;
	}
	printf("x : %d | y : %d\n", maxX, maxY);
	printf("+-----------------------------+\n");
	return (max);
}

int	main(void)
{
	int	x;
	int	y;
	int	max;

	int tab[5][5] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{1, 0, 1, 1, 0},
		{1, 0, 1, 1, 0},
		{0, 0, 1, 1, 0},
	};
	x = 0;
	y = 0;
	max = 0;
	while (y < 5)
	{
		if (get_max_area((int *)tab, 5, 5, y) > max)
			max = get_max_area((int *)tab, 5, 5, y);
		y++;
	}
	printf("max area : %d\n", max);
	return (0);
}
