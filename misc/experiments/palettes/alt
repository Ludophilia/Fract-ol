Great — let's dig into `get_color(double t)` and break down **what those cryptic numbers actually do**:

---

### 🧠 Here's the function again:

```c
uint32_t get_color(double t)
{
	int r = (int)(127.5 * (1 + sin(6.2831 * t + 0)));       // Red
	int g = (int)(127.5 * (1 + sin(6.2831 * t + 2.0944)));   // Green
	int b = (int)(127.5 * (1 + sin(6.2831 * t + 4.1888)));   // Blue

	return (r << 16) | (g << 8) | b;
}
```

---

## 🔍 What's actually happening

### ➤ `t` is your normalized iteration value
```c
double t = iter / MAX_ITER;
```
This should be in the range [0, 1] — and controls the color.

---

### ➤ `6.2831` ≈ 2π

This is one full sine wave cycle.  
So `sin(6.2831 * t)` = `sin(2π * t)` = one wave as `t` goes from 0 → 1.

That means:
- When `t = 0`: `sin(0) = 0`
- When `t = 0.25`: `sin(π/2) = 1`
- When `t = 0.5`: `sin(π) = 0`
- When `t = 0.75`: `sin(3π/2) = -1`
- When `t = 1.0`: `sin(2π) = 0`

So you're getting a **smooth wave**.

---

### ➤ `127.5 * (1 + sin(...))`  
This part rescales the sine wave from:

- `sin(x)` → range [-1, 1]
- So `1 + sin(x)` → range [0, 2]
- Multiply by 127.5 → range [0, 255]

So the result is a color channel (R, G, or B) that smoothly cycles from 0 → 255 → 0.  
It's **perfectly smooth** — great for gradients.

---

### ➤ The **magic offsets**: `+0`, `+2.0944`, `+4.1888`

Those are **phase shifts**:
- `2.0944 ≈ 2π/3`
- `4.1888 ≈ 4π/3`

They're used to **offset the sine waves** for each RGB channel.

That way:
- Red peaks at `t = 0`
- Green peaks later (`+120°`)
- Blue peaks after that (`+240°`)

This creates a **balanced rainbow gradient**:
![Color wave](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a9/RGB_Cube_Gradient.png/320px-RGB_Cube_Gradient.png)

You're sweeping through **hues** using sine waves instead of hard palette steps.

---

## 🧠 Why not just HSV then?

You could — HSV is more intuitive for direct hue control.

But sine-based RGB cycling:
- Requires **zero external libs**
- Gives **perceptual smoothness**
- Feels *organic* in fractals

HSV gives you more **explicit** control.  
Sine gives you a more **natural-feeling** loop.

---

## ✅ TL;DR

| Number         | Meaning                                      |
|----------------|----------------------------------------------|
| `6.2831`       | 2π — full sine wave cycle                    |
| `127.5 * (1 + sin(...))` | Rescales sine to 0–255 (for RGB)        |
| `0, 2.0944, 4.1888` | Phase offsets for R, G, B (120° apart)     |

It’s elegant math magic — and absolutely perfect for fractal coloring.

Want an HSV version next to compare side-by-side?