all:
	@gcc loop.c -o loop -lpthread

run:
	@sudo ./loop