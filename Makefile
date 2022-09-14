guessdll.o:guessdll.c
	gcc -c guessdll.c
guessdll.dll guessdll.a:guessdll.o
	gcc -shared -o guessdll.dll -Wl,--out-implib=guessdll.a -Wl,--image-base=0x62500000 guessdll.o
guess.exe:guessthenumber.c guessdll.a
gcc guessthenumber.c -o guess.exe -Wl,--image-base=0x63600000 -lws2_32 ./guessdll.a