#pragma once

//  PE_Structures.hpp
//  ¼òµ¥¿Ç
//
//  Created by rurenyi mac on 2022/3/10.
//

#ifndef PE_Structures_hpp
#define PE_Structures_hpp

#include <stdio.h>

#endif /* PE_Structures_hpp */

struct _IMAGE_DOS_HEADER6 {
    short e_magic;  short e_cblp;   short e_cp; short e_crlc;   short e_cparhdr;
    short e_minalloc;   short e_maxalloc;   short e_ss; short e_sp; short e_csum;
    short e_ip; short e_cs; short e_lfarlc; short e_ovno;   short e_res[4];
    short e_oemid;  short e_oeminfo;    short e_res2[10];   int e_lfanew;
};

struct _IMAGE_DATA_DIRECTORY6 {
    int VirtualAddress;
    int Size;
};

struct _IMAGE_OPTIONAL_HEADER6 {
    short Magic;    char MajorLinkerVersion;
    char  MinorLinkerVersion;   int SizeOfCode; int SizeOfInitializedData;
    int SizeOfUninitializedData; int AddressOfEntryPoint;    int BaseOfCode;
    long ImageBase; int SectionAlignment; int FileAlignment;
    short MajorOperatingSystemVersion; short MinorOperatingSystemVersion;
    short MajorImageVersion; short MinorImageVersion; short MajorSubsystemVersion;
    short MinorSubsystemVersion; int Win32VersionValue; int SizeOfImage;
    int SizeOfHeaders; int CheckSum; short Subsystem; short DllCharacteristics;
    long SizeOfStackReserve; long SizeOfStackCommit; long SizeOfHeapReserve;
    long SizeOfHeapCommit; int LoaderFlags; int NumberOfRvaAndSizes;
    _IMAGE_DATA_DIRECTORY6 IMAGE_DIRECTORY_ENTRY_EXPORT6[16];
};


struct _IMAGE_FILE_HEADER6 {
    short Machine;
    short NumberOfSections; int TimeDateStamp; int PointerToSymbolTable;
    int NumberOfSymbols; short SizeOfOptionalHeader; short Characteristics;
};


struct _IMAGE_SECTION_HEADER6 {
    char Name[8];
    union {
        int PhysicalAddress; int VirtualSize;
    } Misc;
    int VirtualAddress; int SizeOfRawData; int PointerToRawData; int PointerToRelocations;
    int PointerToLinenumbers; short NumberOfRelocations; short NumberOfLinenumbers;
    int Characteristics;
};

struct _IMAGE_EXPORT_DIRECTORY6 {
    int Characteristics; int TimeDateStamp; short MajorVersion; short MinorVersion;
    int Name; int Base; int NumberOfFunctions; int NumberOfNames; int AddressOfFunctions;
    int AddressOfNames; int AddressOfNameOrdinals;
};

struct _IMAGE_DIRECTORY_ENTRY_BASERELOC6 {
    int VirtualAddress;
    int Size;
};

struct ExportDetail6 {
    long List_FOA;
    long Size;
    long Function_List_FOA;
    int Function_Number;
    long Name_List_FOA;
    int Name_Number;
    long Dictonary_FOA;
};


struct _IMAGE_IMPORT_DESCRIPTOR6 {
    union {
        int Characteristics;
        int OriginalFirstThunk;
    };
    int TimeDateStamp;
    int ForwarderChain;
    int Name;
    int FirstThunk;
};

struct _IMAGE_IMPORT_BY_NAME6 {
    short Hint;
    char Name[1];
};


char* AddingNewList(char* SrcMemory, long SrcSize, long FileSize);
