/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:04:57 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 16:17:27 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_win_data	*get_window_data(t_igmlx *igmlx, void *win)
{
	t_list	*current;

	current = igmlx->wins_data;
	while (current)
	{
		if (((t_win_data *)current->content)->win == win)
			return (((t_win_data *)current->content));
		current = current->next;
	}
	return (NULL);
}

t_win_data	*create_window_data(t_igmlx *igmlx)
{
	t_win_data	*data;

	data = malloc(sizeof(t_win_data));
	if (!data)
		return (NULL);
	ft_bzero(data, sizeof(t_win_data));
	ft_lstadd_front(&igmlx->wins_data, ft_lstnew(data));
	return (data);
}

bool	add_to_window_data(t_igmlx *igmlx, void *win, void *component)
{
	t_win_data	*data;

	if (!component)
		return (false);
	data = get_window_data(igmlx, win);
	if (!data)
		data = create_window_data(igmlx);
	if (data)
		ft_lstadd_front(&data->components, ft_lstnew(component));
	return (true);
}
