#include <iostream>

#include "util/BufferedInputStream.h"
#include "code/BinaryFileParse.h"
#include "runtime/interpreter.h"

int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("vm need a param: filename\n");
        return 0;
    }
    BufferedInputStream stream(argv[1]);
    BinaryFileParse parser(&stream);
    CodeObject* main_code = parser.parse();


    auto i = new Interpreter();
    i->run(main_code);

    return 0;
}
