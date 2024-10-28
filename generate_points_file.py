import random


def generate_points(f_name, points_num, x_range=(-10, 10), y_range=(-10, 10)):
    """
    Generates a file with random 2D points.

    Parameters:
    - f_name: Name of the generated file.
    - points_num: Number of points to generate.
    - x_range: Tuple indicating the range of x-coordinates (min, max).
    - y_range: Tuple indicating the range of y-coordinates (min, max).
    """
    with open(f_name, 'w') as file:
        file.write(f"{points_num}\n")  # Write the number of points

        for _ in range(points_num):
            x = round(random.uniform(*x_range), 1)
            y = round(random.uniform(*y_range), 1)
            file.write(f"{x} {y}\n")


if __name__ == "__main__":
    filename = input("Enter the filename to save points (e.g., points.txt): ")
    points_number = int(input("Enter the number of points to generate: "))
    generate_points(filename, points_number)

    print(f"File '{filename}' created with {points_number} random points.")
