import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib.patches import Circle

# Set the size of the rectangular plane
width = 10
height = 10

# Set the number of particles
n = 5

# Set the radius of each particle
radius = 0.2

# Set the mass of each particle
mass = 1.0

# Set the initial positions and velocities of the particles randomly
positions = np.random.uniform(radius, width - radius, (n, 2))
velocities = np.random.uniform(-1, 1, (n, 2))

# Create a figure and axis for plotting
fig, ax = plt.subplots()

# Set the axis limits
ax.set_xlim(0, width)
ax.set_ylim(0, height)

# Create a list of circles to represent the particles
circles = [Circle(positions[i], radius) for i in range(n)]

# Add the circles to the axis
for circle in circles:
    ax.add_patch(circle)

# Define a function to update the positions of the particles


def update(frame):
    # Get the time step
    dt = 0.01

    # Update the positions of the particles
    for i in range(n):
        # Update the position of the particle based on its velocity
        positions[i] += velocities[i] * dt

        # Check if the particle collides with the walls of the rectangular plane
        if positions[i][0] - radius < 0 or positions[i][0] + radius > width:
            velocities[i][0] *= -1

        if positions[i][1] - radius < 0 or positions[i][1] + radius > height:
            velocities[i][1] *= -1

        # Check if the particle collides with any other particles
        for j in range(i+1, n):
            distance = np.linalg.norm(positions[i] - positions[j])
            if distance < 2*radius:
                # Calculate the normal vector and tangent vector of the collision
                normal = (positions[i] - positions[j]) / distance
                tangent = np.array([-normal[1], normal[0]])

                # Calculate the velocities of the particles after the collision
                v1 = velocities[i].dot(normal) * normal + \
                    velocities[i].dot(tangent) * tangent
                v2 = velocities[j].dot(normal) * normal + \
                    velocities[j].dot(tangent) * tangent

                # Update the velocities of the particles
                velocities[i] = v1
                velocities[j] = v2

    # Update the positions of the circles
    for i in range(n):
        circles[i].center = positions[i]

    return circles


# Create an animation using the update function
ani = animation.FuncAnimation(fig, update, frames=1000, interval=10, blit=True)

# Save the animation as a video using ffmpeg
Writer = animation.writers['ffmpeg']
writer = Writer(fps=30, bitrate=1800)
ani.save('particles.mp4', writer=writer)

# Show the animation
plt.show()
