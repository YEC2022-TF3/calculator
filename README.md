## calculator

This project is for team "Team Fortress 3" for York Engineering Competition (Programming).

Members:
Bardia Moshiri, David Badiei, Wilson Qiu and Eric Haitzer

This calculator is supposed to interpret user input and calculate everything like symbolab.

## Working functions

Currently we have natural logarithm, logarithm, nth root, exponent, trig functions, inverse trig functions, factorial, summation, product and all the basic math operations.

The reason we used C++ instead of as an example python is because it's so much faster and can be optimized at compile time.

Trig functions are done in inline assembly (MSVC) so they are also very fast.

Natural logarithm uses an algorithm which is so fast and advanced that we were shocked by how it was implemented (available in fastapprox repo in github).

# Interpreter

The main issue we have right now is the interpreter which interprets user input into equations and calculates it.
