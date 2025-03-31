/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:22:48 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/31 11:33:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

static void	render_component(t_igmlx *igmlx, void *win,
		t_igmlx_default_component *component)
{
	t_img	*img;

	if (!component)
		return ;
	img = get_component_image(component);
	if (!img)
		return ;
	mlx_put_image_to_window(igmlx->mlx, win, img, component->base.pos.x,
		component->base.pos.y);
}

static void	render_window_components(t_igmlx *igmlx, void *win)
{
	t_win_data	*data;
	t_list		*current;

	data = get_window_data(igmlx, win);
	if (!data)
		return ;
	current = data->components;
	while (current)
	{
		render_component(igmlx, win,
			(t_igmlx_default_component *)current->content);
		current = current->next;
	}
}

int	igmlx_render(t_igmlx *igmlx, void *win)
{
	render_window_components(igmlx, win);
	return (0);
}
