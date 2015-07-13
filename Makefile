Create Random:Create.c Random.c
	gcc Create.c -o Create 
	gcc Random.c -o Random 
	gcc Browse.c -o Browse

clean: 
	rm -vf Create Random Browse

cleandat:
	rm -i .*.dat .name.lst

