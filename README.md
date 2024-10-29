# PWR-Racing-Team-Software-Task

This project contains three main scripts for solving the convex hull problem:

1. `generate_points_file.py`: Generates a file with random 2D points.
2. `convex_hull_script.cpp`: Computes the convex hull of a set of 2D points using the Graham Scan algorithm.
3. `convex_hull_visualization.py`: Visualizes the computed convex hull using Matplotlib.

## Table of Contents
- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
    - [Generating Points](#generating-points)
    - [Computing the Convex Hull](#computing-the-convex-hull)
    - [Visualizing the Convex Hull](#visualizing-the-convex-hull)
- [Example](#example)

## Overview

The **Convex Hull Project** uses the Graham Scan algorithm to calculate the convex hull of a set of 2D points. The project is divided into three parts:

- **`convex_hull_script.cpp`**: The main C++ script that reads a file containing a list of 2D points, computes their convex hull, and prints the result.
- **`generate_points_file.py`**: A Python script that creates a file with random 2D points, used as input for the convex hull computation.
- **`convex_hull_visualization.py`**: A Python visualization script that reads points from a file, computes the convex hull using the `scipy.spatial.ConvexHull` library, and displays both the points and their convex hull.

## Installation

### Prerequisites
- C++ compiler (for `convex_hull_script.cpp`)
- Python 3.x
- Required Python libraries:
    - `matplotlib`
    - `numpy`
    - `scipy`

To install the required libraries, you can use:
```bash
pip install -r requirements.txt
```

## Usage

### 1. Generating Points
First, use `generate_points_file.py` to create a file with random 2D points.

```bash
python generate_points_file.py
```

This script will prompt for:
- **File name**: Name of the output file for saving points.
- **Number of points**: Number of 2D points to generate.

The generated file format will be:
```
<number_of_points>
<x1> <y1>
<x2> <y2>
...
```

### 2. Computing the Convex Hull
Use `convex_hull_script.cpp` to compute the convex hull for a set of points.

#### Compilation with CMake
1. **Navigate to the Project Directory**:
   Ensure you're in the main project directory where `CMakeLists.txt` is located.

2. **Create a Build Directory**:
   This directory will contain all compiled files and build information:
   ```bash
   mkdir build
   cd build
   ```

3. **Generate Build Files with CMake**:
   Run the following command to create the necessary build files based on `CMakeLists.txt`:
   ```bash
   cmake ..
   ```

4. **Build the Project**:
   Compile the project by running:
   ```bash
   cmake --build .
   ```

#### Running the Executable
After building, you can run the executable:

```bash
./convex_hull
```

The script will prompt for the filename containing the points, read them, compute the convex hull, and print the resulting coordinates.
### 3. Visualizing the Convex Hull
Finally, use `convex_hull_visualization.py` to display the points and the convex hull and verify results from `convex_hull_script.cpp` output.

```bash
python convex_hull_visualization.py
```

The script will prompt for the file name, read the points, compute the convex hull, and display it. Points inside the hull are marked with orange dots, and points on the hull are marked with green.

## Example

1. **Generate Points**: Run `generate_points_file.py` and specify a file name (e.g., `points.txt`) and the number of points (e.g., `50`).
2. **Compute Convex Hull**: Run `convex_hull_script.cpp` and provide the generated `points.txt` file to compute the convex hull.
3. **Visualize Convex Hull**: Run `convex_hull_visualization.py` to see the result, with points on the convex hull highlighted.
