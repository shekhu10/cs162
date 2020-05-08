#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;
    long int max_stack_size, max_no_of_process, max_file_descriptors; 
    if (getrlimit(RLIMIT_STACK, &lim) == 0){
        max_stack_size = lim.rlim_cur;
    }
    if(getrlimit(RLIMIT_NPROC, &lim) == 0){
        max_no_of_process = lim.rlim_cur;
    }
    if (getrlimit(RLIMIT_NOFILE, &lim) == 0){
        max_file_descriptors = lim.rlim_cur;
    }
    printf("stack size: %ld\n", max_stack_size);
    printf("process limit: %ld\n", max_no_of_process);
    printf("max file descriptors: %ld\n", max_file_descriptors);
    return 0;
}
