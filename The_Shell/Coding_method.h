#pragma once
//
//  Coding_method.hpp
//  ¼òµ¥¿Ç
//
//  Created by rurenyi mac on 2022/3/10.
//

struct Memory_Details {
    char* Memory;
    long FileSize;
};


Memory_Details GetMemory(char FileName[]);


void Co_DeCoding1(unsigned char* File_ptr, long FileSize);
void Co_DeCoding2(unsigned char* File_ptr, long FileSize);