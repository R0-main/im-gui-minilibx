/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:06:39 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 16:16:03 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
# include "igmlx.h"
#include "intern.h"
#include <X11/X.h>
#include <stdio.h>

int	destroy_close(t_mlx *mlx)
{
	mlx_loop_end(mlx->instance);
	return (0);
}

t_igmlx_button_component *button;

int main_loop(t_igmlx *igmlx)
{
	(void)igmlx;
	igmlx_render(igmlx);
	// ft_fprintf(STDOUT_FILENO, "loop 1\n");
	return (0);
}

int	main(void)
{
	t_mlx	mlx;
	t_igmlx *igmlx;

	mlx.instance = mlx_init();
	if (!mlx.instance)
		return (EXIT_FAILURE);
	mlx.window = mlx_new_window(mlx.instance, 550, 750, "Im-GUI-Minilibx");
	if (!mlx.window)
	{
		mlx_destroy_display(mlx.instance);
		free(mlx.instance);
	}
	igmlx = igmlx_init(mlx.instance);
	igmlx_hook(igmlx);

	button = create_button(igmlx, mlx.window);

	mlx_hook(mlx.window, DestroyNotify, 0, destroy_close, &mlx);
	mlx_loop_hook(igmlx->mlx, main_loop, igmlx);
	mlx_loop(mlx.instance);

	igmlx_destroy(igmlx);
	mlx_destroy_window(mlx.instance, mlx.window);
	mlx_destroy_display(mlx.instance);

	free(mlx.instance);
	return (0);
}
