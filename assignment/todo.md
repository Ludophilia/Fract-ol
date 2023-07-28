# Todo list for Fract-ol

# Foundations

- [o] Read the project
- [x] Search and understand what you don't know...
	- [x] Fractals? Mandelbrot? Julia?
	- [x] X11 ? Server? Window Management? Desktop Environment?
	- [x] MiniLibX?
	- [x] Try the MiniLibX via a small experiment that
	may grow throughout the project...
	- [x] Maths functions?
- [x] Restructure libft: move ft_dprintf/ into libft/
- [x] Write and build Makefile (with a small window open)

# Fractal generation

- [x] Manage to draw the mandelbrot/julia set in black and white,
that is manage to express with a color for every pixel of the window 
if the sequence zn+1 = zn**2 + c is convergent toward a limit l to be defined 
or not. Black means convergence, white, divergence. 
	- [x] Learn to draw on an mlx image first...
	- [x] learn about the complex numbers and associated maths functions
	- [x] Now the meat of the subject: find by yourself a plotting for julian 
	and mandelbrot algorithm.
	- [x] Improve your algorithm. Search what kind of plotting algorithm 
	to implement

# Fractal coloring

- [x] Add colors to the fractals!
	- [x] Build a first palette
	- [x] Mod your julia/mandelbrot function so they return a result that 
	could be plugged to color interpolation function
	- [x] Implement a function that interpolate colors
	- [x] Appreciate the result.

- [x] Clean the mess, optimize, the result should be norm compliant

- [o] Add parameters management to your program
-   [x] How to manage float numbers
- 	[x] Mind special cases: No parameters, empty parameters ("" "" ""), 
	incorrect parameters... (display usage and stuff)
-   [x] Big numbers like 0.98888888888888888888888 are interpreted as
0... Why? Rep: in a double precision number coded on 64bits,
52 bits are used for the significand, 1 for the sign, and 11 for
the exponent... The max number that could be store in 52 bits is 2**52 -1, a
15 digits number.
-   [x] ./fractol 1 +0.285 0 returns something different
from ./fractol 1 0.285 0... What does this happen. Rep : + sign
flipped the sign...
- [x] How to load or manage a color palette?
	- [x] Read it from a file ??? But they are hexes...
	- [x] Build a palette computationally via interpolation of two colors?

-   [x] What's going with the colors when I dezoom... Res: it was because 

# Event management

- [x] Manage the zoom (zoom + <-> scrll_up / zoom - <-> scrll_down) with the
mouse scrollwheel

# Bonus: Event management

- [x] Bonus: Improve the zoom, now it should follow the pointer.

- [x] Bonus: Manage the view with the arrow key?

- [x] Bonus: Manage color shifting with (the space bar by example)
	- [x] Build another palette for the occasion. Why not greyscale,
	psychedelic?

# Bonus: Fractal generation?

- [ ] Bonus: Add a new fractal?

# Tests

- [o] Mind memory leaks
- [o] Mind special cases for user input
- [o] Make sure that everything stays smooth when window is closed, minimized...
