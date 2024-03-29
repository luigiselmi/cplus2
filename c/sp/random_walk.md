Random walk on a square lattice
===============================
The random walk on a one-dimensional lattice is a stochastic process that can be represented as a continuous but not differentiable function. It can be used to model many random processes in which the future state is independent of the present state, such as the stock market prices of a portfolio such as S & P500 which can be represented as the sum of an increasing linear function and a one-dimensional random process.

<p align="center">
  <img src="images/1d_random_walk.png" width="640" height="476" alt="Random walk in one dimension">
</p>

A stochastic process is defined by a series of states of the system in an N-dimensional lattice. A state is represented by a lattice node. The transition from one node to another is given by a probability. For example, in a two-dimensional square lattice, the probability of transition from one node to another adjacent node is 1/4. A state of the system may or may not depend on the previous state, in the first case we speak of the Markov process, in the second case of random walk or Brownian process or more generally martingale. From theory and from simulations, it is possible to calculate the distance traveled from the origin by a traveler on the square lattice which is proportional to the square root of the time, as can be seen in the graph that shows the linear trend with respect to time of the quadratic distance from the origin in a statistical simulation of 10,000 journeys, each consisting of 100,000 steps (units of time)

<p align="center">
  <img src="images/x2_2d_random_walk.png" width="640" height="476" alt="Quadratic distance of one particle">
</p>

The configuration space of Statistical Mechanics for a mechanical system with N particles is also a lattice (at 6N dimensions) in which the system occupies a cell at each instant of time. There is often confusion between the statistics of one variable, even multidimensional, and a stochastic processes (e.g. Brownian or Markovian). In the first case it is a question of repeated measurements of a system in a stationary state over time of which it is interesting to evaluate the average value and the error of the measurement. In the second case, the system changes over time, for example in its position, and each state represented by a point (or cell) in the configuration space is a random variable and the probability that the system goes to each point of that space is calculated . The probability that a system occupying a point P1 at time t will occupy a point P2 at time t + 1 depends on the type of stochastic process: Brownian (no dependence on the previous state, apart from the position) or Markovian (dependence conditional on the state previous one).

## Single particle
The program performs a number of random walks on a 2-dimensional
square lattice. At each step the traveler can move eastward,
westward, northward or southward with equal probability 1/4.
Therefore each random walk is made up of a fixed number of random
steps. At each step t the program computes the squared absolute
value of the distance from the origin x^2(t) and its error x^4(t)
and adds them to the values computed in the preceding random walks
stored in an array.
After all the random walks (samples) are completed, the program
computes the average values of x^2 and its error for each step
and writes the values on a file. The average values of x^2 at step t,
<x^2(t)> represents the (squared) probability for the traveler to
be at position x in the square lattice.
The <x^2(t)> data can be plotted using gnuplot and the command:
```
gnuplot> plot 'rw2d_ave.dat'
````
From the plot it can be seen that $ &lt; x^2(t) &gt; $ is linear according to the
theory that says

$$ &lt; x^2(t) &gt; = a^2 \frac{t}{D} $$

where a is the length of the edges between two nodes of the square
lattice (in our case a = 1), t is the step (or time), and D is the
dimension (in our case D = 2). The above equation has been determined
from the probability distribution of traveler position in the square
lattice as a function of the position x = (x1, x2) and the step (time)

$$ P(x, t) = (\frac{D}{2 \pi t})^\frac{D}{2} \exp(-\frac{Dx^2}{2ta^2}) $$

so that

$$ &lt; x^2(t) &gt; = \int x^2 P(x, t)dx $$

The application also stores in another file, rw2d_prob.dat, the position
(x1, x2) at each step of any random walk (sample) that is a power of 10
between 1 and 5, that is 10, 100, 1000, 10000 and 100000. We can plot the
distribution of the positions reached by the random traveler after, for
instance 100 steps, in all the random walks. The position reached after
100 steps will be distributed around a value of (100/2)^(1/2), that is 7.07.
We can filter the data from the file to consider only the position after 100
steps
```
$ grep "T 99 " rw2d_prob.dat > rw2d_prob_100.dat
```
If we use gnuplot to plot the data we set the range for x1 and x2
```
gnuplot> set xrange [-300:300]
gnuplot> set yrange [-300:300]
```
then we plot the filtered data
```
gnuplot> plot 'rw2d_prob_100.dat' using 6:8 linecolor 'blue'
```
<p align="center">
  <img src="images/2d_random_walk_position_after_100_steps.png" width="640" height="476" alt="Arrival points of the traveler at each simulation 100 steps">
</p>

The plot shows the distribution of the nodes the traveler went through after 100 steps.

If we repeat the experiment filtering the data to extract the position
after, let's say, 10000 step we will see that the distribution is much
larger and the points are more dispersed.

<p align="center">
  <img src="images/2d_random_walk_position_after_100000_steps.png" width="640" height="476" alt="Arrival points of the traveler at each simulation 10000 steps">
</p>

The traveler moves further and further away from the origin and the probability that he will remain in his vicinity as time passes decreases. Each point represents a complete random walk, after 100,000 steps in this graph, and after 100 in the previous one. Each graph contains 10000 points.

Another experiment is to compute the number of times a certain position
in the square lattice has been reached by the random traveler after a
certain number of steps. For instance, we can count the number of times
the traveler went through the point at (0, 0) after 100 steps
```
$ grep "T 99 X1 0 X2 0" rw2d_prob.dat |wc -l
59
```
If we repeat the test for the position (10, 10)
```
$ grep "T 99 X1 10 X2 10" rw2d_prob.dat |wc -l
4
```
we see that it's much less likely. We can compute the values for all the
points in the square lattice, within the ranges we have set above, to have
the probability distribution for t = 100 or for any other value of t for
which we have the data.

## Lattice gas
Our aim is to compute the mass diffusivity, or diffusion coefficient, of a system
of N particles on a square lattice by performing some simulations using the C code.
We define the variables that will be used in the simulations.

- ρ is the probability of occupation of a lattice's node
- L is the number of nodes per lattice row (or column)
- V = $L^2$ is the total number of nodes of the lattice
- N = ρV is the total number of particles.

The occupation function η(x1, x2) assumes values in the set {0, 1} and tells us when
a node in position (x1, x2) in the lattice is occupied by a particle, so that η(x1, x2) = 1,
or when it is not and η(x1, x2) = 0. We can also define a spin function σ(x1, x2) to represent the same concept using values in the set {-1, 1} so that for an empty node σ(x1, x2) = -1 and
for an occupied node σ(x1, x2) = 1. The relation between the two representations is given by the equation

σ(x1, x2) = 2 * η(x1, x2) - 1

The total number of occupied nodes is equal to the number of particles and is assumed constant   

N = ρ * V = ∑η(x1, x2)

where the summation is made over the set of the lattice's nodes.
A particle α, of the total N particles, is located at the time t in one of the N nodes.
For each particle we have to take into account the position occupied at time t and whether
it moves at time t + 1 to an adjacent node. For the correct location of a particle
we have to take into account the boundary conditions so that

(x1, x2) = (x1 +/- L, x2) = (x1, x2 +/- L)

Each particle α can move at time t to an adjacent free node with equal probability, 1/4
for a square lattice. The quadratic distance between two adjacent nodes is

$$ ΔR_\alpha(t)^2 = (x_1(t) - x_1(0))^2 + (x_2(t) - x_2(0))^2 $$

The average distance traveled by all particles at time t is

$$ ΔR(t)^2 = \frac{1}{N} \sum_\alpha ((x_1(t) - x_1(0))^2 + (x_2(t) - x_2(0))^2) $$

In order to minimize the error we can compute the mean quadratic distance traveled by
all particles at time t by performing a certain number S of travels so that

$$ &lt;\Delta R(t)^2&gt; = \frac{1}{S} \sum_S \Delta R(t)^2$$

For large enough values of t we can compute the diffusion coefficient D(ρ) for a specific
value of the density ρ

$$D(ρ) = \lim_{t \to ∞}D(ρ, t) = \lim_{t \to ∞} \frac{1}{2Dt}&lt;\Delta R(t)^2&gt;$$

where D is the dimensions of the lattice, so D = 2 in our case.

We can perform a certain number of simulations for an increasing value of the time t to analyze
the behavior of the density for an increasing number of steps (i.e. time). For instance we
can measure  $&lt;\Delta R(t)^2&gt;$ at times that are multiples of 10 of each other and verify
that the diffusion coefficient D(ρ) converges to a constant value as shown in the figure.

<p align="center">
  <img src="images/deltaR2_lattice_gas.png" width="634" height="439" alt="Mean quadratic distance">
</p>

The diffusion coefficient is the angular coefficient of the line that represents the mean quadratic distance $&lt;\Delta R(t)^2&gt;$.

## Credits
Barone et al. - Scientific Programming, https://chimera.roma1.infn.it/SPENG/
