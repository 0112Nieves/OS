#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "\\n") == 0) write(1, "\n", 1); 
        else{
            write(1, argv[i], strlen(argv[i]));
            if (i + 1 < argc) write(1, " ", 1);
            else write(1, "\n", 1);
        }
    }
    exit(0);
}
