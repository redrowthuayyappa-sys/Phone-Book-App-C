phonebook: main.o create.o display.o find.o delete.o edit.o file.o
	gcc -Wall -Wextra -o phonebook main.o create.o display.o find.o delete.o edit.o file.o

main.o: main.c contact.h
	gcc -Wall -Wextra -c main.c

create.o: create.c contact.h
	gcc -Wall -Wextra -c create.c

display.o: display.c contact.h
	gcc -Wall -Wextra -c display.c

find.o: find.c contact.h
	gcc -Wall -Wextra -c find.c

delete.o: delete.c contact.h
	gcc -Wall -Wextra -c delete.c

edit.o: edit.c contact.h
	gcc -Wall -Wextra -c edit.c

file.o: file.c contact.h
	gcc -Wall -Wextra -c file.c

clean:
	rm -f *.o phonebook phonebook.dat
