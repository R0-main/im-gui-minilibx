/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:18:48 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/04 11:35:49 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	igmlx_melt_colors(unsigned int input, unsigned int filter)
{
	unsigned int	result;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = input >> 16;
	green = (input << 16) >> 24;
	blue = (input << 24) >> 24;
	result |= (((filter << 8) >> 24) << 16) + red;
	result |= (((filter << 24) >> 24)) + blue;
	result |= (((filter << 24) >> 24) << 8) + green;
	return (result);
}

int	main(void)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	unsigned int color = 0x0000FF00; // red
	unsigned int input = 0x00FF0000; // red
	red = color >> 16;
	green = (color << 16) >> 24;
	blue = (color << 24) >> 24;
	input |= (((input << 8) >> 24) << 16) + red;
	input |= (((input << 24) >> 24)) + blue;
	input |= (((input << 24) >> 24) << 8) + green;
	printf("r %x\n", red);
	printf("g %x\n", green);
	printf("b %x\n", blue);
	printf("r %x\n", input >> 16);
	printf("g %x\n", (input << 24) >> 24);
	printf("b %x\n", (input << 16) >> 24);
	return (0);
}
