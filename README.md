# 42_Push_Swap

5 Nums in 12 operations or less
3 in 3
2 in 1

Todo's:
input check ✅
create stack ✅
sorting:
1-5 ✅

turk algo:

Push everything to b except 3 numbers
find lowest amount of operation in the current constellation
-> if there is no number between the current num and next go to next num
	->see if there is a num betwween the current abd the next. smallest of those.
	-
-> when the best move is found save node in b that needs to be behind node a
-> after every succesful push to a reindex both a and b

Go through each num is A.
Find the nearest num in b that betwee

Helper func:
func that index the current spots ✅

Extra:
if its cheaper to go both in one direction do it
or if one is in the middle