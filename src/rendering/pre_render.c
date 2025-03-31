/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:22:14 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/31 15:48:26 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

static void for_each_components(t_igmlx *igmlx, t_list **components)
{
	t_list	*current;

	if (!components)
		return ;
	current = *components;
	while (current)
	{
		if (current->content)
			init_component_states_images(igmlx, (t_igmlx_default_component *)current->content);
		current = current->next;
	}
}

void pre_render_components(t_igmlx *igmlx)
{
	t_list	*current;

	_log(IGMLX_LOG_INFO, "Pre Rendering ...");
	if (!igmlx)
		return ;
	current = igmlx->wins_data;
	while (current)
	{
		for_each_components(igmlx, &((t_win_data *)current->content)->components);
		current = current->next;
	}
	_log(IGMLX_LOG_INFO, "Components PreRendered");
}
