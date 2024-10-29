import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial import ConvexHull


def read_points(filename):
    """
    Reads a list of points from a file, where the first line indicates
    the number of points, and each subsequent line contains the x and y
    coordinates of a point.

    Args:
        filename (str): The name of the file containing point data.

    Returns:
        np.array: A NumPy array of points with shape (n, 2).
    """

    with open(filename, 'r') as file:
        n = int(file.readline().strip())
        points = []
        for _ in range(n):
            x, y = map(float, file.readline().strip().split())
            points.append((x, y))
    return np.array(points)


def plot_convex_hull(points, hull):
    """
    Plots the given points and highlights the convex hull.

    Args:
        points (np.array): An array of points with shape (n, 2).
        hull (ConvexHull): A ConvexHull object representing the convex hull of the points.
    """

    plt.figure(figsize=(8, 6))
    plt.plot(points[:, 0], points[:, 1], 'o', color='orange', markersize=8, label="Points")

    for simplex in hull.simplices:
        plt.plot(points[simplex, 0], points[simplex, 1], 'g-', linewidth=2)

    hull_points = points[hull.vertices]
    plt.plot(hull_points[:, 0], hull_points[:, 1], 'o', color='green', markersize=10, label="Convex Hull Points")

    plt.xlabel("X")
    plt.ylabel("Y")
    plt.title("Convex Hull Visualization")
    plt.legend()
    plt.grid()
    plt.show()


def execute():
    """
    Function to execute the convex hull computation and plot the result.
    Reads points from a file, computes the convex hull, and displays both the
    hull points and the complete set of points.
    """

    filename = input("Enter the filename: ")
    points = read_points(filename)
    hull = ConvexHull(points)

    print("Convex Hull Points:")

    for vertex in hull.vertices:
        print(f"({points[vertex][0]}, {points[vertex][1]})")

    plot_convex_hull(points, hull)


if __name__ == "__main__":
    execute()
