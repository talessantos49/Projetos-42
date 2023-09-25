<div align="center">
  <img src="https://user-images.githubusercontent.com/86013047/235568429-5bc9c51b-d3da-4348-adf9-5785b8c73223.png">
</div>


<h2>
The project
</h2>

### Rules

You have 2 stacks named `A` and `B`. 
- The `stack A` contains a random amount of negative and/or positive numbers which cannot be duplicated. 
- The `stack B` is empty. 

The goal is to sort in ascending order numbers into `stack A`.
To do so you have the following operations at your disposal: 

- `sa` (swap a): Swap the first 2 elements at the top of `stack A`. Do nothing if there is only one or no elements. 
- `sb` (swap b): Swap the first 2 elements at the top of `stack B`. Do nothing if there is only one or no elements. 
- `ss` : `sa` and `sb` at the same time. 
- `pa` (push a): Take the first element at the top of `B` and put it at the top of `A`. Do nothing if `B` is empty. 
- `pb` (push b): Take the first element at the top of `A` and put it at the top of `B`. Do nothing if `A` is empty.  
- `ra` (rotate a): Shift up all elements of `stack A` by 1. The first element becomes the last one. 
- `rb` (rotate b): Shift up all elements of `stack B` by 1. The first element becomes the last one.  
- `rr`: `ra` and `rb` at the same time. 
- `rra` (reverse rotate a): Shift down all elements of `stack A` by 1. The last element becomes the first one. 
- `rrb` (reverse rotate b): Shift down all elements of `stack B` by 1. The last element becomes the first one.  
- `rrr`: `rra` and `rrb` at the same time.

You can launch the program by doing
```sh
> $ ./push_swap <list_of_integers> 
```
The list can be passed as a single array of multiple numbers, indiferently. 
```sh
> $ ./push_swap 1 3 5 4 2 0 -4
```
or
```sh
> $ ./push_swap "1 3 5 4 2 0 -4"
```

The expected output should be the instructions applied in order to sort the stack: 

```sh
> $ ./push_swap 0 4 2
> pb
> ra
> pa
```
Or an `Error` message in case of errors of any kind:
```sh
> $ ./push_swap 0 4 two
> Error
```

If no parameters are passed, the command prompted will be returned with no error message:
Or an `Error` message in case of errors of any kind:
```sh
> $ ./push_swap
> $
```

The grade depends on how efficient the program's sorting process is.
 
* Sorting 3 values: no more than 3 actions.
* Sorting 5 values: no more than 12 actions.
* Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 700 actions
  * 4 points for less than 900
  * 3 points for less than 1100
  * 2 points for less than 1300
  * 1 point for less than 1500
* Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 5500 actions
  * 4 points for less than 7000
  * 3 points for less than 8500
  * 2 points for less than 10000
  * 1 point for less than 11500
