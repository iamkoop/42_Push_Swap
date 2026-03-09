*This project has been created as part of the 42 curriculum by <nildruon>*

# Description

This is Pushswap:
A project aimed at sorting the inputs using given operations rotate, swap and reverse rotate.
It takes numbers writen in the cmd as inputs converts them into a list and sorts them.
I opted for the turk_algo that i optimized

# Instructions

To run the program either do:

	./push_swap arg1 arg2 arg3 | ./checker_linux arg1 arg2 arg3

or do:

	ARG="arg1 arg2 arg3"; ./push_swap $ARG | ./checker_OS $ARG
	
to make ./checker_linux an excecutable do:

	 chmod +x ./checker_linux

Note that the first works in all cases.
The second one works only in bash since my program doenst accept multiple numbers in one argument.

# Rescources:

https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

This was a big insperation. Vaguely read through the idea and came up with a cool solution.

Ai was used for testing perpouses where i deemed it unescerry to write the whole unit_test by myself
