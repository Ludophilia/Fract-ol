/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:38:52 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/18 21:29:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H

# define FRACTOL_BONUS_H

# include "../includes/fractol.h"

# define WINB_NAME "fractol bonus"

# define ERRB_USAGE "usage: fractol (0 | 1 <const_real> <const_imag> | 2)\n"

# define SHIP 2
# define SHP_ITMX 75.00

# define SHIFT_FACTOR 0.05

# define CLSH_FWD 1
# define CLSH_BCK 0
# define CLSH_RST -1

int		clib_get_args(int argc, char **argv, t_fra *fra);

int		hookb_key_event_manage(int keycode, t_ui *ui);
int		hookb_mouse_event_manage(int button, int x, int y, t_pln *pln);
int		hookb_loop_event_manage(t_ui *ui);

void	uib_loop(t_ui *ui);
int		uib_destroy(int target, t_ui *ui);
int		uib_init(t_ui *ui);

int		imageb_init(t_ui *ui);
int		imageb_ui_draw(t_ui *ui);

t_pnt	plotb_get_cmplx_coords(t_pnt *pt, t_pln *pln);
double	plotb_get_max_iter(t_pnt *cpt, t_fra *fra);

int		viewb_shift_color(int dir, t_fra *fra);
void	viewb_chg_zoom_lvl(int zoom_in, t_pnt *pt, t_pln *pln);
void	viewb_shift_plane(int keycode, double factor, t_pln *pln);
int		viewb_colorize_coords(t_pnt *pt, t_ui *ui);

#endif
