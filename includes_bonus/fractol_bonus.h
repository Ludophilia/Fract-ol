/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:38:52 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/15 21:25:00 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H

# define FRACTOL_BONUS_H

# include "../includes/fractol.h"

// # define PALETTE_SIZE 4

# define SHIP 2

# define SHIFT_FACTOR 0.05
# define SHIFT_LEFT 0x10
# define SHIFT_RIGHT 0x20
# define SHIFT_UP 0x30
# define SHIFT_DOWN 0x40

typedef struct s_inp
{
	int	fract;
	double	zcons[2];
	char	*zconsrw[2];
}	t_inp;

int		clib_get_args(int argc, char **argv, t_fra *fra);

int		hookb_key_event_manage(int keycode, t_ui *ui);
int		hookb_mouse_event_manage(int button, int x, int y, t_pln *pln);
int		hookb_loop_event_manage(t_ui *ui);

void	uib_events_register(t_ui *ui);
int		uib_init(t_ui *ui);

int		imageb_ui_draw(t_ui *ui);

double	plotb_get_max_iter(t_pnt *cpt, t_fra *fra);

void	view_change_comp_plane_zoom_level(int zoom_in, double x, double y,
		t_pln *com_pln);
void	viewb_shift_plane(int direct, double factor, t_pln *pln);
int		viewb_colorize_coords(t_pnt *pt, t_ui *ui);

#endif
