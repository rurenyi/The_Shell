

//
//  Coding_method.cpp
//  ¼òµ¥¿Ç
//
//  Created by rurenyi mac on 2022/3/10.
//

#include "Coding_method.h"
#include <iostream>
#include "framework.h"



Memory_Details GetMemory(char FileName[]) {
    FILE* Notepad;
    Notepad = fopen(FileName, "rb");
    if (Notepad == NULL) {
        MessageBox(0, TEXT("Open File Failed"), 0, 0);
        exit(0);
    }
    fseek(Notepad, 0, 2);
    long length = (ftell(Notepad) / 16 + 1) * 16;
    fseek(Notepad, 0, 0);
    char* memory;
    memory = (char*)malloc(length);
    if (memory == NULL) {
        MessageBox(0, TEXT("error when get memory"), 0, 0);
        free(memory);
        exit(0);
    }
    memset(memory, 0, length);
    fread(memory, 1, length, Notepad);
    fclose(Notepad);
    Memory_Details Details;
    Details.Memory = memory;
    Details.FileSize = length;
    return Details;
}



//Decoding method,0-13,1-8,2-9,3-14,4-15,5-11,6-10,7-12,
void Co_DeCoding1(unsigned char* File_ptr, long FileSize) {
    unsigned char coding_buffer[8];
    for (long i = 0; i < FileSize / 16; i++) {
        for (char j = 0; j < 8; j++) {
            coding_buffer[j] = File_ptr[i * 16 + j];
        }
        File_ptr[i * 16 + 0] = File_ptr[i * 16 + 13];
        File_ptr[i * 16 + 1] = File_ptr[i * 16 + 8];
        File_ptr[i * 16 + 2] = File_ptr[i * 16 + 9];
        File_ptr[i * 16 + 3] = File_ptr[i * 16 + 14];
        File_ptr[i * 16 + 4] = File_ptr[i * 16 + 15];
        File_ptr[i * 16 + 5] = File_ptr[i * 16 + 11];
        File_ptr[i * 16 + 6] = File_ptr[i * 16 + 10];
        File_ptr[i * 16 + 7] = File_ptr[i * 16 + 12];
        File_ptr[i * 16 + 13] = coding_buffer[0];
        File_ptr[i * 16 + 8] = coding_buffer[1];
        File_ptr[i * 16 + 9] = coding_buffer[2];
        File_ptr[i * 16 + 14] = coding_buffer[3];
        File_ptr[i * 16 + 15] = coding_buffer[4];
        File_ptr[i * 16 + 11] = coding_buffer[5];
        File_ptr[i * 16 + 10] = coding_buffer[6];
        File_ptr[i * 16 + 12] = coding_buffer[7];
    }
}


//0-9,1-13,2-15,3-11,4-10,5-12,6-14,7-8
void Co_DeCoding2(unsigned char* File_ptr, long FileSize) {
    unsigned char coding_buffer[8];
    for (long i = 0; i < FileSize / 16; i++) {
        for (char j = 0; j < 8; j++) {
            coding_buffer[j] = File_ptr[i * 16 + j];
        }
        File_ptr[i * 16 + 0] = File_ptr[i * 16 + 9];
        File_ptr[i * 16 + 1] = File_ptr[i * 16 + 13];
        File_ptr[i * 16 + 2] = File_ptr[i * 16 + 15];
        File_ptr[i * 16 + 3] = File_ptr[i * 16 + 11];
        File_ptr[i * 16 + 4] = File_ptr[i * 16 + 10];
        File_ptr[i * 16 + 5] = File_ptr[i * 16 + 12];
        File_ptr[i * 16 + 6] = File_ptr[i * 16 + 14];
        File_ptr[i * 16 + 7] = File_ptr[i * 16 + 8];
        File_ptr[i * 16 + 9] = coding_buffer[0];
        File_ptr[i * 16 + 13] = coding_buffer[1];
        File_ptr[i * 16 + 15] = coding_buffer[2];
        File_ptr[i * 16 + 11] = coding_buffer[3];
        File_ptr[i * 16 + 10] = coding_buffer[4];
        File_ptr[i * 16 + 12] = coding_buffer[5];
        File_ptr[i * 16 + 14] = coding_buffer[6];
        File_ptr[i * 16 + 8] = coding_buffer[7];
    }
}

