import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import ffmpeg

# Set up parameters
n = 10  # Number of particles
size = 0.04  # Particle size
dt = 0.01  # Time step
tmax = 10  # Maximum simulation time
xlim = (-1, 1)  # x limits
ylim = (-1, 1)  # y limits
speed = 2  # Maximum speed

# Initialize positions and velocities
pos = np.random.uniform(low=(-1, -1), high=(1, 1), size=(n, 2))
vel = np.random.uniform(low=(-speed, -speed), high=(speed, speed), size=(n, 2))

# Create figure and axes
fig, ax = plt.subplots()
ax.set_xlim(xlim)
ax.set_ylim(ylim)

# Create particles
particles = ax.scatter(pos[:, 0], pos[:, 1], s=size*1000)
# Define function to update positions


def update_pos(i):
    global pos, vel

    # Update positions
    pos += vel * dt

    # Check for collisions with walls
    for j in range(n):
        if pos[j, 0] < xlim[0] or pos[j, 0] > xlim[1]:
            vel[j, 0] = -vel[j, 0]
        if pos[j, 1] < ylim[0] or pos[j, 1] > ylim[1]:
            vel[j, 1] = -vel[j, 1]

    # Check for collisions with particles
    for j in range(n):
        for k in range(j+1, n):
            d = pos[j] - pos[k]
            dist = np.sqrt(np.dot(d, d))
            if dist < size:
                d /= dist
                v1 = np.dot(vel[j], d)
                v2 = np.dot(vel[k], d)
                vel[j] -= (v1 - v2) * d
                vel[k] -= (v2 - v1) * d

    # Update particle positions
    particles.set_offsets(pos)

    return particles,


# Create animation
ani = animation.FuncAnimation(fig, update_pos, frames=int(
    tmax/dt), interval=dt*1000, blit=True)
# Save animation
Writer = animation.writers['ffmpeg']
writer = Writer(fps=60, metadata=dict(artist='Me'), bitrate=1800)
ani.save('collision_animation.mp4', writer=writer)
# Show animation
plt.show()
