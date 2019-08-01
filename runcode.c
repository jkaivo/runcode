#define _POSIX_C_SOURCE 199309
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		return 1;
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("open");
		return 1;
	}

	struct stat st;
	if (fstat(fd, &st) == -1) {
		perror("fstat");
		return 1;
	}

	void *code = mmap(NULL, st.st_size, PROT_EXEC | PROT_READ | PROT_WRITE,
		MAP_PRIVATE, fd, 0);

	if (code == MAP_FAILED) {
		perror("mmap");
		return 1;
	}

	void (*fn)(void) = (void (*)(void))code;
	fn();

	return 0;
}
