/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:15:53 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/27 21:46:23 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int argc, char **argv)
{
	ft_printf(1,
		"Welcome to %s!\n\tYou added %i arguments.\n",
		*argv,
		argc - 1
	);
}
