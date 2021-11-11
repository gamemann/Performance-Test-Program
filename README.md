# Simple Performance Test
## Description
This is a simple program in C for performance testing which only works for x86 systems. A for loop is executed *x* times and we use the Assembly instruction `rdtsc` for profiling.

## Test 1
Test #1 simply creates a character array with a size of 256 bytes and a string value of "a string" is copied to the character array via `strcpy()`. Afterwards, a variable representing the profiling average along with the highest and lowest profile speeds are calculated.

## Command Line
There is currently only one command line argument which may be found below.

```
-c --count => The amount of times to execute for/while loops.
```

### Example
```
./perftest1 -c 10000000
```

## Building And Installing
You can use `git` and `make` to build and install the program.

```
git clone https://github.com/gamemann/Performance-Test-Program.git
cd Performance-Test-Program/
sudo make && sudo make install
```

The binary `perftest1` will be copied to `/usr/bin`. Therefore, it should be added to your path (e.g. you can write `perftest1 ...`).

## Credits
* [Christian Deacon](https://github.com/gamemann)