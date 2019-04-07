# BSQ
*Elementary Programming in C*

##### Purpose of the project :
- [x] Find the biggest square on a text file with some '.' and 'o'
- [x] Replace the biggest square consists of '.' by 'x'

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
$ ./mouli.sh
```

### Exemple
```
$ ./mouli.sh

mouli_maps/empty_map : OK

[TIME] 0:00.00
[CPU]  81%
[EXIT] 84


mouli_maps/intermediate_map_10000_10000 : OK

[TIME] 0:01.92
[CPU]  99%
[EXIT] 0

[total : 2] [passed : 2] [failed : 0] >> 100.00 %
```
