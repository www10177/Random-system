##Before Use:
	You need to create your own list by this program or download lists (not available now) 
	before doing random


##Usage:
	./main.sh [argv1]
	Key in any char in [argv1] too execute this program QUICKLY.


##Warning:
	Please Don't Use Ctrl-C to Terminate the Program or Your Data might Corrupted

##Limit :
	List name length is MUST less than 100 characters.
	Data name length is MUST less than  20 characters.

##Delete Lists:
	Sorry, you can only delete list manually now.
	There are the steps.
	First, type "rm .$(LISTNAME).dat" in your shell( Please replace $(LISTNAME) with your name)
	Then, edit .name.lst with any editor you like and delete the line that includes your listname
	There is example instrustion:
```
	 rm .$(LISTNAME).dat ( Please replace yout list name with $(LISTNAME) )
	 vim .name.lst
	 /$(LISTNAME)  ( Please replace yout list name with $(LISTNAME) )
	 dd
	 :wq
```
	 Or if you want to clean all data
	 Just input "make cleandat"
	 and Press 'y' repeatedly XDDD

##Some Bugs:
	When there are too many item in a list, it might cause error.(MAX:100)
	In Random, if user don't input a number, it will casue error


####Need to Improved:
	When user key in instruction, they can key in 'L' to show instruiction list.
	Color it !!
	Convert main to header
	upload and download system
	Maybe somewhere user's input will mix with the text show
	After first Random user need to wait a second
	Combined make into main
	Delete List
	Fixed Makefile
	Add loop in Browse.c
