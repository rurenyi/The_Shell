#include "PE_Structures.h"

//
//  PE_Structures.cpp
//  ¼òµ¥¿Ç
//
//  Created by rurenyi mac on 2022/3/10.
//

#include <iostream>
#include "PE_Structures.h"


char* AddingNewList(char* SrcMemory, long SrcSize, long FileSize) {
    _IMAGE_DOS_HEADER6* Dos_header = (_IMAGE_DOS_HEADER6*)SrcMemory;
    int unsigned NT = Dos_header->e_lfanew;
    _IMAGE_FILE_HEADER6* FIle_header = (_IMAGE_FILE_HEADER6*)(SrcMemory + NT + 0x04);
    _IMAGE_OPTIONAL_HEADER6* Optional_header = (_IMAGE_OPTIONAL_HEADER6*)(SrcMemory + NT + 0x18);
    char* ptr_of_lists = SrcMemory + NT + 0x18 + FIle_header->SizeOfOptionalHeader;
    long FreeSpace = (long)Optional_header->SizeOfHeaders - (long)(ptr_of_lists - SrcMemory);
    long ExistSpace = FIle_header->NumberOfSections * 28;
    if (FreeSpace - ExistSpace < 28 * 2) {
        printf("%s\n", "No enough space in header");
        exit(0);
    }

    _IMAGE_SECTION_HEADER6* OldSectiom;
    OldSectiom = (_IMAGE_SECTION_HEADER6*)ptr_of_lists;
    _IMAGE_SECTION_HEADER6* NewSectiom;
    NewSectiom = (_IMAGE_SECTION_HEADER6*)(ExistSpace + ptr_of_lists);
    NewSectiom = OldSectiom;


    NewSectiom->PointerToRawData = (int)SrcSize;
    NewSectiom->VirtualAddress = Optional_header->SizeOfImage;
    NewSectiom->Characteristics = 0x60000020;
    NewSectiom->SizeOfRawData = (int)FileSize;
    FIle_header->NumberOfSections = FIle_header->NumberOfSections + 1;
    Optional_header->SizeOfImage = Optional_header->SizeOfImage + (int)FileSize;
    char* NewList_ptr = SrcMemory + SrcSize;
    return NewList_ptr;
}