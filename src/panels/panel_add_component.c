/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_add_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:09:20 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 15:26:01 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void igmlx_panel_add_component(t_igmlx_panel *parent, t_igmlx_component *component)
{
	t_list *lst;

	lst = ft_lstnew(component);
	if (!lst)
		return ;
	ft_lstadd_back(&parent->childs, lst);
}
