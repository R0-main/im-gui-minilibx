// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pre_render.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/31 11:22:14 by rguigneb          #+#    #+#             */
// /*   Updated: 2025/04/02 12:09:24 by rguigneb         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "intern.h"

// static void for_each_components(t_igmlx *igmlx, t_list **components)
// {
// 	t_list	*current;

// 	if (!components)
// 		return ;
// 	current = *components;
// 	while (current)
// 	{
// 		if (current->content)
// 			init_component_states_images(igmlx, (t_igmlx_default_component *)current->content);
// 		current = current->next;
// 	}
// }

// void pre_render_components(t_igmlx *igmlx)
// {
// 	t_list	*current;

// 	_info("Pre Rendering ...");
// 	if (!igmlx)
// 		return ;
// 	current = igmlx->wins_data;
// 	while (current)
// 	{
// 		for_each_components(igmlx, &((t_win_data *)current->content)->components);
// 		current = current->next;
// 	}
// 	_info("Components PreRendered");
// }
