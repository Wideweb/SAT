# Separating Axis Theorem

If an axis can be found along witch the projection of two convex shapes do not overlap, then two shapes do not intersect at all.

## Build

1. mkdir build
2. cd build
3. cmake ..
4. cmake --build .

## Run tests

./test

## Run test app

./app

You can specify shapes vertices in the `/assets/shapes.txt` file in the following format:

X0 Y0  
X1 Y1  
...  
Xn Yn

Each shape should consist of n vertices where n > 1. Shapes are divided by empty line.
