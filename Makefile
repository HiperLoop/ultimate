compile: build run

build:
	gcc -mwindows ./src/main.c ./src/test.c ./src/board.c -o ./public/main.exe -lSDL3
run:
	./public/main.exe

test:
	gcc ./src/main.c ./src/test.c ./src/board.c -o ./public/test.exe -lSDL3
	./public/test.exe

app:
	gcc ./src/app.c ./src/test.c ./src/board.c -o ./public/app.exe -lSDL3
	./public/app.exe