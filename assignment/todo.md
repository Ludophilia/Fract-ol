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

- [x] How to load or manage a color palette?
	- [x] Read it from a file ??? But they are hexes...
	- [x] Build a palette computationally via interpolation of two colors?

# Event management

- [o] Manage the zoom (zoom + <-> scrll_up / zoom - <-> scrll_down)
with the mouse scrollwheel, bonus: it should follow the pointer?

- [ ] Bonus: Manage the view with the arrow key?

- [ ] Bonus: Manage color shifting with (the space bar by example)
	- [ ] Build another palette for the occasion. Why not greyscale,
	psychedelic?

# More fractal generation?

- [ ] Bonus: Add a new fractal?

# Tests

- [ ] Mind memory leaks
- [ ] Mind special cases for user input
- [ ] Make sure that everything stays smooth when window is closed, minimized...