## Find_Randomness
Personal project, the idea is to find random sequences and use them or test them.

<br />

Use "make" to compile the project

<br />

Argument to use:

-LCG [Start] [End]
> Run the LCG part, you can precise a Start and an end to search for

> Example: "% ./Find_Randomness -LCG 30 53"

-perf [Value]
> Run the performance version of LCG finder, you can precise a Value, the program will look close to this value, up to a mod of Value + 15

> Example: "% ./Find_Randomness -perf 200"

-debug
> Used for personal use, help to debug. It show X random number of the best map found.

> Example: "% ./Find_Randomness -perf 200 -debug"

You can put every argument in the order you want, you only need to have the dependcies of it right after it in the good order.
> For Example:
"% ./Find_Randomness -perf 300 -debug" work the same way as "% ./Find_Randomness -debug -perf 300" but "% ./Find_Randomness -perf -debug 300" won't work

For -LCG:
This will have for effect to find the best period of LCG (https://en.wikipedia.org/wiki/Linear_congruential_generator) for predermined seed
> (you can find the seeds in ./includes/random.h)

The loop Start and End will determine the start and end of multipier, increment and moluo, for example for 30-53:

The program will try to find the period of 5 same seeeds with: Xn+1 = (a * Xn + c) % m

> with X the seed, a = 30 to 53, c = 30 to 53 and m = 30 to 53. So it will do a total of 24x24x24 = 13824 loops
> (loop a = 30, c = 30, m = 30 to a = 53, c = 53 m = 53)
> (and without counting the number of loop to find the period)

<br />

I hope you find this project interesting.
