/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:42 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/23 20:13:42 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGMGR_H

# define IMGMGR_H

# include "plotter.h"
# include "fractol_common.h"

int	image_init(t_fra *fra_data);
int	image_draw(t_fra *fra_data);

#endif
