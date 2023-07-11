import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
from matplotlib import colors
import numpy as np

xs, ys = 2, 4
xe, ye = 14, 10
raster = np.random.randint(1, size=(16, 16))

# Bresenhanm's Line Drawing Algorithm
# the idea is to calculate the positions of the pixels and then set
# corresponding element in raster to 1 denoting they are part of the line segment
dx = xe - xs
dy = ye - ys
p = 2 * dy - dx
x, y = xs, ys
raster[y][x] = 1
while(x<xe):
    print(x,y)
    x = x + 1
    if (p < 0):
        p = p + 2 * dy
    else:
        y = y + 1
        p = p + 2 * dy - 2 * dx
    raster[y][x] = 1

# create discrete colormap
cmap = colors.ListedColormap(['white', 'lightblue'])
bounds = [0, 1] # 0 = white; 1 = gray
norm = colors.BoundaryNorm(bounds, cmap.N)

fig, ax = plt.subplots(figsize=(6, 6))
ax.set_xlim(-1, 16)
ax.set_ylim(-1, 16)
ax.set_frame_on(False)
# apply color map
ax.imshow(raster, cmap=cmap, norm=norm)

# positions for major gridlines
xy_positions = np.arange(-0.5, 16, 1)
xy_labels = [f'{int(x + 0.5)}' for x in xy_positions]
# positions for minor ticks (to show label in the center)
xy_minor_positions = xy_positions + 0.5
ax.grid(which='major', axis='both', linestyle='-', color='k', linewidth=2, alpha=0.5)
# hide major lables, show the minor labels
ax.xaxis.set_major_formatter(ticker.NullFormatter())
ax.xaxis.set_major_locator(ticker.FixedLocator(xy_positions))

ax.xaxis.set_minor_locator(ticker.FixedLocator(xy_minor_positions))
ax.xaxis.set_minor_formatter(ticker.FixedFormatter(xy_labels))

ax.yaxis.set_major_formatter(ticker.NullFormatter())
ax.yaxis.set_major_locator(ticker.FixedLocator(xy_positions))

ax.yaxis.set_minor_locator(ticker.FixedLocator(xy_minor_positions))
ax.yaxis.set_minor_formatter(ticker.FixedFormatter(xy_labels))
# don't show the ticks
ax.tick_params(which='both', axis='both', width=0)

# plot the real line segment
ax.plot([xs, xe], [ys, ye], color='#b43757', marker='o', linewidth=2, markersize=10)

plt.show()
