# push_swap

# Usage
$> make
$> make bonus
$> bash
$> ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
	6
$> ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
	ok

$> ./push_swap 3 2 1
ra
sa

$> ./checker 3 2 1
ra
sa
OK

$> ./checker 3 2 1
ra
sa
ra
KO

## option
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.