# BSQ
*Elementary Programming in C | Epitech | Tek1*

##### Purpose of the project :
- [x] Find the biggest square on a text file with some '.' and 'o'
- [x] Replace the biggest square consists of '.' by 'x'

## Dependencies
- [gcc](https://gcc.gnu.org)
- [make](https://www.gnu.org/software/make/)
- [python3](https://www.python.org) *(testing script)*

## Build
```
$ make
```

## Usage
```
$ ./bsq -h
USAGE
	./bsq [file]
DESCRIPTION
	file: text file containing the map to solve
```

## Testing
All files contained in the `mouli_maps` folder can be tested with :
```
$ ./mouli.py
```

### Example
```
$ ./mouli.py
[1] intermediate_map_100_100: in 0.0441 seconds
STATUS :  PASSED

[2] intermediate_map_1000_1000: in 0.1242 seconds
STATUS :  PASSED

[3] intermediate_map_10000_10000: in 1.6480 seconds
STATUS :  TIMEOUT

[4] empty_map: in 0.0283 seconds
STATUS :  ERROR


TOTAL TIME : 1.8446 seconds
[total : 4] [passed : 2] [timed out : 1] [failed : 1]  >> 50.00 %
```
