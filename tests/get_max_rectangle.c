/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_rectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:14:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 12:27:30 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int get_tall(int **tab, int x, int height)
{
	int y = height - 1;
	int total = 0;

	printf("%d\n", tab[3][0]);
	while (y > 0)
	{
		total += tab[y--][x];
	}
	printf("%d\n", total);
	return (total);
}

int get_max_area(int **tab,  int width, int height)
{
	int x = 0;
	int x2 = 0;
	int x3 = 0;
	int y = 0;
	int max = 0;

	int current_tall = 0;

	while (x < width)
	{
		x2 = x;
		current_tall = get_tall(tab, x, height);

		while (x2 > 0 && get_tall(tab, x2 - 1, height) == current_tall)
			x2--;
		while (x2 > 0 && x2 < width && get_tall(tab, x2, height) == current_tall)
			x2--;
		max = x2 * current_tall;
	}
	return (max);
}

int main(void)
{
	int tab[5][5] = {
		{0, 0, 0, 0 ,0},
		{0, 0, 1, 1 ,0},
		{0, 0, 1, 1 ,0},
		{1, 0, 1, 1 ,1},
		{1, 1, 1, 1 ,1},
	};

	printf("max area : %d\n", get_max_area(tab, 5, 5));
	return 0;
}
