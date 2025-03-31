/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:21:20 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/31 14:23:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

bool	is_inside_rectangle(t_uvec_2 p1, t_uvec_2 p2, t_uvec_2 target)
{
	return (target.x <= p2.x && target.x >= p1.x && target.y <= p2.y && target.y >= p1.y);
}
