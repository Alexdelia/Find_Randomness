## Find_Randomness
> Personal project on idea to find randomness and use it.

<br />

Use make to compile the project

<br />

The project accept "./Find_Randomness -LCG" to run the LCG testing part
> You can precise the Start and the End of loop, otherwise it will run with default value.

Example: "% ./Find_Radomness -LCG 30 53"

This will have for effect to find the best period of LCG (https://en.wikipedia.org/wiki/Linear_congruential_generator) for predermined seed
> (you can find the seeds in ./includes/random.h)

The loop Start and End will determine the start and end of multipier, increment and moluo, for example for 30-53:

The program will try to find the period of 5 same seeeds with: Xn+1 = (a * Xn + c) % m

> with X the seed, a = 30 to 53, c = 30 to 53 and m = 30 to 53. So it will do a total of 24x24x24 = 13824 loops
> (loop a = 30, c = 30, m = 30 to a = 53, c = 53 m = 53)
> (and without counting the number of loop to find the period)

<br />

I hope you find this project interesting.
