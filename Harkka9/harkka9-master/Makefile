app: teht1.o teht1-functions.o
	gcc teht1.o teht1-functions.o header.h -o app
functions.o: teht1-functions.c header.h
	gcc -c teht1-functions.c
teht1.o: teht1.c header.h
	gcc -c teht1.c