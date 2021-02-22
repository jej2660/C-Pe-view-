#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned long long QWORD;

typedef struct LOCAL_HEADER {
	DWORD Signature;
	WORD Vesrion;
	WORD Flags;
	WORD Compression;
	WORD Mod_Time;
	WORD Mod_Date;
	DWORD Crc_32;
	DWORD Compressed_Size;
	DWORD Uncompressed;
	WORD File_Name_Size;
	WORD Exrtra_field_Size;
	
}LOCAL_HEADER;

//char FileName[File_Name_Size];
//BYTE Data[Compressed_Size];

void Print(struct LOCAL_HEADER h)
{
	printf("Signature		: %08X\n",h.Signature);
	printf("Vesrion			: %08X\n",h.Vesrion);
	printf("Flags			: %08X\n",h.Flags); 
	printf("Compression		: %08X\n",h.Compression);
	printf("Mod_Time		: %08X\n", h.Mod_Time);
	printf("Mod_Date		: %08X\n", h.Mod_Date);
	printf("Crc_32			: %08X\n",h.Crc_32);
	printf("Compressed_Size		: %08X\n",h.Compressed_Size);
	printf("Uncompressed		: %08X\n",h.Uncompressed);
	printf("File_Name_Size		: %08X\n",h.File_Name_Size);
	printf("Exrtra_field_Size	: %08X\n",h.Exrtra_field_Size);
}
int main()
{
	struct LOCAL_HEADER LOCAL_HEADER;
	
	int size;
	

	FILE* fp = fopen("My_Name.zip", "rb");

	if (fp == NULL)
	{
		printf("Fail to File Open\n");
		return 0;
	}

	fseek(fp, 0, SEEK_END);
	size = sizeof(fp);
	fseek(fp, 0, SEEK_SET);

	fread(&LOCAL_HEADER, sizeof(LOCAL_HEADER),1, fp);

	Print(LOCAL_HEADER);
}



