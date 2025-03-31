/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:49:42 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 09:36:43 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H

# define TIMER_H

# include <stdbool.h>
# include <sys/time.h>

typedef struct timeval	t_time;

typedef struct s_timer
{
	int					duration;
	t_time				started_at;
	t_time				end_at;
	bool				started;
}						t_timer;

//-------------------------------------------------
//
//	TIMER
//
//-------------------------------------------------
void					start_timer(t_timer *timer);
bool					is_timer_finished(t_timer *timer);
bool					date_lowest_than(t_time t1, t_time t2);

#endif
