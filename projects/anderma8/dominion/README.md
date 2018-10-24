Assignment 3
===

Running Tests
===

```bash
$ make unittestresults  // Results written to 'unittestresults.out'
```

IMPORTANT
===
In assignment 2 I introduced a bug to the 'Adventurer' card that will cause the program to enter an infinite loop. This  
will also cause the unit tests to loop, and they **WILL NOT COMPLETE**. To generate the appropriate output, either  
comment out the 'unittest2' recipe, or fix the bug (decrement *tempHandIndex* in the while loop of the effect.)

In Makefile, comment out this line if an infinite loop occurs:
``` bash
make unittestresults
	.
	.
	.
	# @./cardtest2 >> $(REPORT)
```

or, make this change to playAdventurer in dominion.c:

```c
	while (tempHandIndex - 1 > 0 {
		.
		.
		.
		tempHandIndex--;  // ADD THIS.
}
```

Copy of *unittestresults.out* with this fix in place has also been included in the repository for reference - *unittestresults.out.NO_LOOP
