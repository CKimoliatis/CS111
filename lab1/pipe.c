#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int fds[2], prev_fds[2] = {-1, -1};

    if(argc < 2) {
        return EINVAL;
    }

    for (int i = 1; i < argc; i++) {
        errno = 0;
        if (pipe(fds) == -1) {
            return errno;
        }
        int ret = fork();
        errno = 0;
        if (ret < 0) {
            return errno;
        }
        if (ret == 0) { 
            if (prev_fds[0] != -1) {
                errno = 0;
                if (dup2(prev_fds[0], STDIN_FILENO) == -1) {
                    return errno;
                }
                close(prev_fds[0]);
                close(prev_fds[1]);
            }
            if (i < argc - 1) {
                errno = 0;
                if (dup2(fds[1], STDOUT_FILENO) == -1) {
                    return errno;
                }
            }
            close(fds[0]);
            close(fds[1]);
            errno = 0;
            if (execlp(argv[i], argv[i], (char *)NULL) == -1) {
                return errno;
            }
        } else {
            if (prev_fds[0] != -1) {
                close(prev_fds[0]);
                close(prev_fds[1]);
            }
            prev_fds[0] = fds[0];
            prev_fds[1] = fds[1];
            int status;
           
            waitpid(ret, &status, 0);
            if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
                int err = WEXITSTATUS(status);
                return err;
            }
        }
    }

    if (prev_fds[0] != -1) {
        close(prev_fds[0]);
        close(prev_fds[1]);
    }

    return 0;
}