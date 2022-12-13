#include <printf.h>
#include "includes/onichan.h"
#include "includes/inout.h"

int main() {
    char* file_content = read_file("../examples/example1.oni");
    run_run_bby(file_content);

    return 0;
}
