Compiler 	= gcc
Flags    	= -Wall 

Create:Create.c
	$(Compiler) $(Flags) Create.c -o Create
rmdat:.*.dat
	rm -v .*.dat
