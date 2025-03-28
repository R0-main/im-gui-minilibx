/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:03:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 13:27:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "im_gui_minilibx.h"
# include "libft.h"
# include "ft_fprintf.h"

typedef enum e_igmlx_log_level
{
	IGMLX_LOG_DEBUG,
	IGMLX_LOG_INFO,
	IGMLX_LOG_WARNING,
	IGMLX_LOG_ERROR
};

typedef struct s_igmlx_component
{

}			t_igmlx_component;

int igmlx_loop(t_igmlx *igmlx);
int igmlx_render(t_igmlx *igmlx);

#endif
