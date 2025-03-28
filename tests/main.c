/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:06:39 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 13:13:04 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "im_gui_minilibx.h"
#include <X11/X.h>
#include <stdio.h>

int	destroy_close(t_mlx *mlx)
{
	mlx_loop_end(mlx->instance);
	return (0);
}

int main_loop(t_mlx *mlx)
{
	(void)mlx;
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
	mlx_hook(mlx.window, DestroyNotify, 0, destroy_close, &mlx);
	igmlx = igmlx_hook(&mlx);
	mlx_loop_hook(mlx.instance, main_loop, &mlx);
	mlx_loop(mlx.instance);
	mlx_destroy_window(mlx.instance, mlx.window);
	mlx_destroy_display(mlx.instance);
	free(mlx.instance);
	return (0);
}
