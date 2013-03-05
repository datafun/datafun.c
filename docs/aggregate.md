
aggregate
=========

These commands compute a number or numbers from the entire input.


max
---

Computers the maximum number from the input. Can also output the index that the number is found out.


### usage

    Usage: max [options]

    Options:

      -V, --version                 output program version
      -h, --help                    output help information
      -i, --input <path>            specify input file [stdin]
      -o, --output <path>           specify output file [stdout]
      -n, --number [number]         specify the number [0]
      -s, --start [number]          the start of the data, x0 [0]
      -x, --show-index              show the index along with the maximum 


### examples

**input: (data.txt)**

    45
    23.0
    -10000.34
    10442
    0.42424
    2
    45.0
    -5.678
    6


#### 1

**cmd:**

    max << data.txt


**output:**

    10442


#### 2

**cmd:**

    max -x << data.txt


**output:**

    3,10442.000000


#### 3

**cmd:**

    max -s 100 -n 0.5 << data.txt


**output:**

    101.500000,10442.000000



