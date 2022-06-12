//
//  main.cpp
//  简单壳
//
//  Created by rurenyi mac on 2022/3/9.
//
#include"framework.h"
#include <iostream>
#include "Coding_method.h"
#include "PE_Structures.h"






void THE(TCHAR TFilePath[], TCHAR TNewFilePath[], TCHAR TSrcPath[]) {

    char FilePath[MAX_PATH] = {0};
    char SrcPath[MAX_PATH] = { 0 };
    char NewFilePath[MAX_PATH] = { 0 };

    setlocale(LC_ALL, "");
    wcstombs(SrcPath, TSrcPath, wcslen(TSrcPath) + 2);

    wcstombs(FilePath, TFilePath, wcslen(TFilePath) + 2);

    wcstombs(NewFilePath, TNewFilePath, wcslen(TNewFilePath) + 2);
    setlocale(LC_ALL, "C");

    strcat(SrcPath, "\\SHELL.sb");

    strcat(NewFilePath, "\\NewApp.exe");

    Memory_Details MemoryFile = GetMemory(SrcPath);
    Memory_Details MemorySRC = GetMemory(FilePath);
    char* NewMemory = (char*)malloc(MemorySRC.FileSize + MemoryFile.FileSize);
    Co_DeCoding1((unsigned char*)MemoryFile.Memory, MemoryFile.FileSize);
    memset(NewMemory, 0, sizeof(MemorySRC.FileSize + MemoryFile.FileSize));
    memcpy(NewMemory, MemorySRC.Memory, MemorySRC.FileSize);
    memcpy(NewMemory + MemorySRC.FileSize, MemoryFile.Memory, MemoryFile.FileSize);
    AddingNewList(MemorySRC.Memory, MemorySRC.FileSize, MemoryFile.FileSize);

    FILE* NewFile = fopen(NewFilePath, "wb");
    fwrite(NewMemory, MemorySRC.FileSize + MemoryFile.FileSize, 1, NewFile);
    fclose(NewFile);
    free(MemorySRC.Memory);
    free(MemoryFile.Memory);
    free(NewMemory);
}