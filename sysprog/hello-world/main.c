

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	mode_t mode = S_IRUSR | S_IWUSR;
	int fd = open("output.txt", O_CREAT | O_TRUNC | O_RDWR, mode);
	write(fd, "Hello\n", 6);
	close(fd);

	for (int i = 5; i; i--) {
		write(STDOUT_FILENO, "Hello\n", 6);
		write(STDERR_FILENO, ".", 1);
	}
	return 0;
}
