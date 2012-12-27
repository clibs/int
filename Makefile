
test: int.c test.c
	@$(CC) $^ -std=c99 -o $@
	@./test

.PHONY: test
