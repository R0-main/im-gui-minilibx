/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:03:13 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/31 11:20:42 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx_component_state get_component_state(t_igmlx_default_component *component)
{
	return (component->base.states[component->base.state]);
}

t_img	*get_component_image(t_igmlx_default_component *component)
{
	return (get_component_state(component).render);
}

t_img	*create_image_from_state(t_igmlx *igmlx, t_igmlx_default_component *component, t_e_igmlx_state state)
{
	t_img	*img;
	t_vec_2	c;

	c = (t_vec_2){0, 0};
	img = mlx_new_image(igmlx->mlx, component->base.collision_box.x, component->base.collision_box.y);
	if (!img)
	{
		_log(IGMLX_LOG_WARNING, "mlx_new_image failed !");
		return (NULL);
	}
	while (c.x < component->base.collision_box.x)
	{
		c.y = 0;
		while (c.y < component->base.collision_box.y)
		{
			((int *)img->data)[((c.y * (img->size_line / 4)) + c.x)] = component->base.states[state].backgroud_color;
			c.y++;
		}
		c.x++;
	}
	return (img);
}

void	init_component_states_images(t_igmlx *igmlx, t_igmlx_default_component *component)
{
	size_t i;

	i = 0;
	while (i < IGMLX_STATE_COUNT)
	{
		component->base.states[i].render = create_image_from_state(igmlx, component, (t_e_igmlx_state)i);
		i++;
	}
}
