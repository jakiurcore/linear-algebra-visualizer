# learn-raylib

Small experiments for learning [raylib](https://www.raylib.com/), the C graphics library, as groundwork for the linear algebra visualizer.

## 001-basic-understanding.c

Opens a 960x720 window and draws a 2D Cartesian coordinate plane with one vector on it: a red arrow from the origin to the point (4, 5).

### Coordinate mapping

Math coordinates and screen coordinates differ in two ways:

- The screen origin is the top-left corner. Math puts (0, 0) in the middle of the plane.
- Screen y grows downward. Math y grows upward.

`ToScreen` converts between them:

```c
screen.x = origin.x + v.x * SCALE;
screen.y = origin.y - v.y * SCALE;   // minus flips the y axis
```

- `origin = {480, 360}` is the pixel at the centre of the window, where math (0, 0) is drawn.
- `SCALE = 40` means one math unit is 40 pixels.

All drawing code works in math coordinates and calls `ToScreen` only when it hands points to raylib.

### Structure

1. **Setup:** `InitWindow(960, 720, ...)` creates the window and `SetTargetFPS(60)` caps the frame rate.
2. **Main loop:** runs until `WindowShouldClose()` is true (window closed or Esc pressed). Each frame is wrapped in `BeginDrawing()` / `EndDrawing()` and starts with `ClearBackground(WHITE)`.
3. **Axes:** the x axis runs from (-12, 0) to (12, 0) and the y axis from (0, -9) to (0, 9). Both are 4px black lines drawn with `DrawLineEx`.
4. **Grid:** two loops draw 1px black lines at every integer x from -12 to 12 (vertical lines) and every integer y from -9 to 9 (horizontal lines).
5. **Vector:** `DrawLineEx` draws a 3px red line from the screen origin to `ToScreen({4, 5})`.
6. **Cleanup:** `CloseWindow()` releases the window.

The plane spans 24 x 18 units, which at 40px per unit is exactly the 960x720 window.

### Build and run

The build output goes in `build/`, which is git-ignored. For example:

```sh
gcc 001-basic-understanding.c -o build/001-basic-understanding -lraylib -lm
./build/001-basic-understanding
```

### Limitations

- The vector is drawn as a plain line with no arrowhead.
- The grid and axes have the same colour, so the axes are told apart only by thickness.
- The plane has no tick labels.
- The vector and plane size are hard-coded.
