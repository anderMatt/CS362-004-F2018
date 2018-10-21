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
