/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:03:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 16:18:38 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "colors.h"
# include "ft_fprintf.h"
# include "igmlx.h"
# include "libft.h"

# define IGMLX_LOG_PREFIX "IGMLX"

# define IGMLX_BUTTON_DEFAULT                           \
	(t_igmlx_button_component)                         \
	{                                                  \
		(t_igmlx_component){IGMLX_COMPONENT_BUTTON,    \
							(t_vec_2){50, 50},         \
							(t_vec_2){50, 50},         \
							NULL,                      \
							{                          \
								{                      \
									(t_color)0xFFFFFF, \
									(t_color)0xFF00FF, \
									1,                 \
									1,                 \
								},                     \
								{                      \
									(t_color)0xFFFFFF, \
									(t_color)0xFF00FF, \
									1,                 \
									1,                 \
								},                     \
								{                      \
									(t_color)0xFFFFFF, \
									(t_color)0xFF00FF, \
									1,                 \
									1,                 \
								},                     \
							}},                        \
			NULL, NULL, NULL, NULL,                    \
	}

typedef int						t_color;

typedef struct s_vec_2
{
	int							x;
	int							y;
}								t_vec_2;

typedef enum e_igmlx_state
{
	IGMLX_STATE_DEFAULT,
	IGMLX_STATE_HOVERED,
	IGMLX_STATE_PRESSED,

	IGMLX_STATE_COUNT
}								t_e_igmlx_state;

typedef enum e_igmlx_log_level
{
	IGMLX_LOG_DEBUG,
	IGMLX_LOG_INFO,
	IGMLX_LOG_WARNING,
	IGMLX_LOG_ERROR
}								t_e_igmlx_log_level;

typedef enum e_igmlx_component_type
{
	IGMLX_COMPONENT_BUTTON,
}								t_e_igmlx_component_type;

typedef struct s_igmlx_component_state
{
	t_color						backgroud_color;
	t_color						text_color;
	int							size_mutliplier;
	int							opacity;
}								t_igmlx_component_state;

typedef struct s_igmlx_component
{
	t_e_igmlx_component_type	type;
	t_vec_2						collision_box;
	t_vec_2						pos;
	void						*win;
	t_igmlx_component_state		state[IGMLX_STATE_COUNT];
}								t_igmlx_component;

typedef struct s_igmlx_button_component
{
	t_igmlx_component			base;
	void						(*press)(void *);
	void						(*touch)(void *);
	void						(*leave)(void *);
	void						(*hover)(void *);
}								t_igmlx_button_component;

typedef struct s_win_data
{
	void						*win;
	t_list						*components;
}								t_win_data;

typedef struct s_igmlx
{
	void						*mlx;
	t_list						*wins_data;
}								t_igmlx;

int								igmlx_loop(t_igmlx *igmlx);
int								igmlx_render(t_igmlx *igmlx);

void							_log(t_e_igmlx_log_level level,
									const char *msg);

bool							add_to_window_data(t_igmlx *igmlx, void *win,
									void *component);

#endif
