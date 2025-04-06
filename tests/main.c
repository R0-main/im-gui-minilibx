/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:06:39 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/06 10:52:03 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "igmlx.h"
#include "intern.h"
#include <X11/X.h>
#include <stdio.h>

typedef struct s_data
{
	t_mlx					mlx;
	t_igmlx					*igmlx;
	int						clicks;
}							t_data;

int	destroy_close(t_mlx *mlx)
{
	mlx_loop_end(mlx->instance);
	return (0);
}

t_igmlx_button_component	*button;

int	main_loop(t_data *data)
{
	(void)data;
	igmlx_render(data->igmlx, data->mlx.window);
	// ft_fprintf(STDOUT_FILENO, "loop %d\n", data->clicks);
	return (0);
}

void	on_press1(t_data *data)
{
	(void)data;
	data->clicks--;
	// button->base.states[IGMLX_STATE_PRESSED].backgroud_color += 0x33;
	// pre_render_components(data->igmlx); // only for one
	ft_fprintf(STDOUT_FILENO, "Pressed button\n");
}

void	on_press(t_data *data)
{
	(void)data;
	data->clicks++;
	// button->base.states[IGMLX_STATE_PRESSED].backgroud_color += 0x33;
	// pre_render_components(data->igmlx); // only for one
	// button->base.pos.y+=10;
	ft_fprintf(STDOUT_FILENO, "Pressed button\n");
}

int	main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.mlx.instance = mlx_init();
	if (!data.mlx.instance)
		return (EXIT_FAILURE);
	data.mlx.window = mlx_new_window(data.mlx.instance, 550, 750,
			"Im-GUI-Minilibx");
	if (!data.mlx.window)
	{
		mlx_destroy_display(data.mlx.instance);
		free(data.mlx.instance);
	}
	data.igmlx = igmlx_init(data.mlx.instance);
	button = create_button(data.igmlx, data.mlx.window);
	button->base.pos = (t_uvec_2){150, 150};
	button->base.states[IGMLX_STATE_DEFAULT].backgroud_color = 0x00FFFF;
	button->base.states[IGMLX_STATE_HOVERED].backgroud_color = 0xFFFF00;
	button->data = &data;
	button->delay = 1000;
	button->press = (void (*)(void *))on_press1;
	button = create_button(data.igmlx, data.mlx.window);
	button->base.pos = (t_uvec_2){250, 150};
	button->base.states[IGMLX_STATE_DEFAULT].backgroud_color = 0xFFFFFF;
	button->base.states[IGMLX_STATE_HOVERED].backgroud_color = 0x00FFFF;
	button->base.states[IGMLX_STATE_PRESSED].backgroud_color = 0x00FF00;
	// button->base.state = IGMLX_STATE_PRESSED;
	button->base.states[IGMLX_STATE_DEFAULT].borders_radius[IGMLX_CORNER_TOP_LEFT] = 75;
	// 75% rounded
	// button->base.states[IGMLX_STATE_HOVERED].collision_box = (t_uvec_2){75,
	// 75};
	button->data = &data;
	button->press = (void (*)(void *))on_press;
	pre_render_components(data.igmlx);
	igmlx_hook(data.igmlx);
	// t_img *background = mlx_new_image(data.mlx.instance, 550, 750);
	// for (size_t i = 0; i < 550; i++)
	// {
	// 	for (size_t j = 0; j < 750; j++)
	// 	{
	// 		((int *)background->data)[j * (background->size_line / 4) + i] = 0xFFDDEE00;
	// 	}
	// 	/* code */
	// }
	// mlx_put_image_to_window(data.mlx.instance, data.mlx.window, background, 0, 0);


	// igmlx_load_font(data.igmlx, "/home/rguigneb/pppprojects/im-gui-minilibx/fonts/default.xpm", (t_igmlx_font_params){0x00FF00, 2, (t_uvec_2){-10, 0}});
	// igmlx_put_str(data.igmlx, (char *)"teswqfqfqwfqfqwfqfqwfqfwq", "/home/rguigneb/pppprojects/im-gui-minilibx/fonts/default.xpm", data.mlx.window, (t_uvec_2){0, 450});


	// t_img *tmp;
	// int i;

	// tmp = mlx_xpm_file_to_image(data.mlx.instance, "/home/rguigneb/pppprojects/im-gui-minilibx/fonts/test.xpm", &i, &i);
	// mlx_put_image_to_window(data.mlx.instance, data.mlx.window, tmp, 0, 0);

	// tmp = igmlx_upscale_img(data.igmlx, tmp, 10);
	// igmlx_apply_color_filter(tmp, 0xFF0000);
	// t_alpha_img *test = transform_img_to_alpha_img(data.igmlx, tmp);
	// igmlx_put_alpha_to_window(data.igmlx, data.mlx.window, test, (t_uvec_2){150, 500});

	t_alpha_img	*img = igmlx_png_to_alpha_image(data.igmlx, "/home/rguigneb/pppprojects/im-gui-minilibx/pngs/apple.png");

	igmlx_put_alpha_to_window(data.igmlx, data.mlx.window, img, (t_uvec_2){0, 0});
	// tmp = mlx_new_image(data.mlx.instance, 100, 100);
	// for (size_t i = 10; i < 90; i++)
	// {
	// 	for (size_t j = 10; j < 90; j++)
	// 	{
	// 		*get_pixel(tmp, (t_uvec_2){i, j}) = 0x00FF00FF;
	// 	}
	// }

	// for (size_t i = 0; i < 5; i++)
	// {
	// 	for (size_t j = 0; j < 90; j++)
	// 	{
	// 		*get_pixel(tmp, (t_uvec_2){i, j}) = 0x00FF00FF;
	// 	}
	// }

	// mlx_put_image_to_window(data.mlx.instance, data.mlx.window, tmp, 0, 0);

	// t_rectangle max = get_largest_rectangle_available_img(tmp);
	// (void)max;
	// t_alpha_img *alpha;
	// alpha = transform_img_to_alpha_img(data.igmlx, tmp);
	// igmlx_put_alpha_to_window(data.igmlx, data.mlx.window, alpha, (t_uvec_2){150, 0});
	// igmlx_load_font(data.igmlx, "fonts/default.xpm", );
	// button->base.collision_box = (t_vec_2){150, 150};
	// mlx_hook(data.mlx.window, DestroyNotify, 0, destroy_close, &data.mlx);
	// mlx_loop_hook(data.mlx.instance, main_loop, &data);
	// mlx_loop(data.mlx.instance);
	igmlx_destroy(data.igmlx);
	mlx_destroy_window(data.mlx.instance, data.mlx.window);
	// mlx_destroy_image(data.mlx.instance, background);
	mlx_destroy_display(data.mlx.instance);
	free(data.mlx.instance);
	return (0);
}
