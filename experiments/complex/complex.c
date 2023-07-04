/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:08:14 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/04 19:17:52 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <complex.h>

int	main(void)
{
	// complex 	z1;
	double complex	z1;
	// float complex 	z1; // if float, use the float specific functions 
	// which are built for double by default. Example: crealf for creal.
	// imaginary	z2;
	double complex	z2;

	z1 = I * I;
	printf("z1 = %.lf + %.lfI\n", creal(z1), cimag(z1));
	// printf("z1 = %.lf + %.lfI\n", creal(z1), cimag(z1));

	// Addition, substraction, multiplication, division ?
	// Conjuguate?

	// printf("z1 = %.lf + %.lfI\n", creal(z1), cimag(z1));
}
