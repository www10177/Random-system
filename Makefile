Compiler 	= gcc
Flags    	= -Wall 

Create:Create.c
	$(Compiler) $(Flags) Create.c -o Create
clean:
	rm  Create 
Cleandat:
	rm -i .*.dat

