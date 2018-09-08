
// input upto EOF.........................

while True:
    try:
        input_ = input("Enter:\t")
        #or
        _input = raw_input("Enter:\t")
    except EOFError:
        break
    print type(input_)
    print type(_input)
    print input_
    print _input

// make array of size n....................
    a = [0]*n

// input integer...........................
	n=int(input())

// input two numbers in python 2.7 or PYPY 2.6 .......................
	a,b = raw_input().split()	
	a,b = [int(a), int(b)]

// formatted output..................
	print("%.2f %d" % (num1, num2))

// for prtinting in loop without spaces.................. ex- 123456
	from __future__ import print_function
	for i in range(1,7):
    	print(i, end='')

// for printing in loop with spaces...................... ex- 1 2 3 4 5 6
	for i in range(1,7):
    	print i,

// to change a character at index pos in a string.............
// convert into list first then change the char and then join without anything between them
	li = list(str)
    li[pos] = c
    str = "".join(li)
    return str

// input a string ................. ex: insert 0 5
	raw_input()          			//' insert 0 5     '
	raw_input().strip()  			//'insert 0 5'
	raw_input().strip().split()  	//['insert', '0', '5']
	raw_input().strip().split(';')	//if str = 'insert;0;5'	then the result is ['insert', '0', '5']