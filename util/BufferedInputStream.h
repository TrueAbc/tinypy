//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_BUFFEREDINPUTSTREAM_H
#define TINYPY_BUFFEREDINPUTSTREAM_H


#include <cstdio>

#define BUFFER_LEN 256

class BufferedInputStream {
private:
    FILE *fp;
    char szBuffer[BUFFER_LEN];
    unsigned short index;

public:
    BufferedInputStream(char const* filename){
        fp = fopen(filename, "rb");
        fread(szBuffer, BUFFER_LEN * sizeof (char), 1, fp);
        index = 0;
    }

    ~BufferedInputStream(){
        close();
    }

    char read(){
        if(index < BUFFER_LEN) {
            return szBuffer[index++];
        } else {
            index = 0;
            fread(szBuffer, BUFFER_LEN * sizeof(char), 1, fp);
            return szBuffer[index++];
        }
    }

    int read_int(){
        int b1 = read() & 0xff;
        int b2 = read() & 0xff;
        int b3 = read() & 0xff;
        int b4 = read() & 0xff;
        // small endian
        return b4<<24 | b3 << 16 | b2 << 8 | b1;
    }

    void unread(){
        index--;
    }

    void close(){
        if(fp != nullptr) {
            fclose(fp);
            fp = nullptr;
        }
    }
};


#endif //TINYPY_BUFFEREDINPUTSTREAM_H
