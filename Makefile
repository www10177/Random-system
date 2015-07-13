Create Random:Create.c Random.c
	gcc Create.c -o Create 
	gcc Random.c -o Random 

clean: 
	rm -vf Create Random

cleandat:
	rm -i .*.dat .name.lst

