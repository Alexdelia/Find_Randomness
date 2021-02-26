## Find_Randomness

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/0d390452c3c3489d85da6a18a59aae1e)](https://app.codacy.com/gh/Alexdelia/Find_Randomness?utm_source=github.com&utm_medium=referral&utm_content=Alexdelia/Find_Randomness&utm_campaign=Badge_Grade_Settings)

Personal project, the idea is to find random sequences and use them or test them.

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/2704c025c72249f2805b988368aabad8)](https://www.codacy.com/gh/Alexdelia/Find_Randomness/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Alexdelia/Find_Randomness&amp;utm_campaign=Badge_Grade)

<br />

Use "make" to compile the project

<br />

Warning: The program hasn't been optimised to handle stack overflow yet ! I never got one, even with GIANT value to look for (my program use a big array to find the period, so bigger is the modulo, bigger is this array), but take that in consideration.

<br />

Argument to use:

-LCG [Start] [End]
> Run the LCG part, you can precise a Start and an End to search for (Optional)

> Example: "% ./Find_Randomness -LCG 30 53"

-perf [Value]
> Run the performance version of LCG finder (faster and overall more effective), you can precise a Value (Optional), the program will look close to this value, up to a modulo of Value + 15

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

The loop Start and End will determine the start and end of multiplier, increment and modulo, for example for 30-53:

The program will try to find the period of 5 same seeeds with: Xn+1 = (a * Xn + c) % m

> with X the seed, a = 30 to 53, c = 30 to 53 and m = 30 to 53. So it will do a total of 24x24x24 = 13824 loops
> (loop a = 30, c = 30, m = 30 to a = 53, c = 53 m = 53)
> (and without counting the number of loop to find the period)

<br />

I hope you find this project interesting.
