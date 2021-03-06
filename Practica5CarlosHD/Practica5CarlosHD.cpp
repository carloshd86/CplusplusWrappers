// Practica5CarlosHD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IFile.h"


int main()
{
	char * buffer = nullptr;
	unsigned int bytesRead = 0;
	unsigned int bytesWritten = 0;

	FileIdentifier * fId = OpenFile("test.txt", FileOpenMode::ReadOnly);

	if (fId)
	{
		buffer = new char[14];
		bytesRead = ReadFile(buffer, fId, 13);
		buffer[13] = '\0';

		printf("\n%d bytes read from file", bytesRead);
		printf("\nBytes read: %s", buffer);
		bytesRead = ReadFile(buffer, fId, 13);
		buffer[13] = '\0';

		printf("\n%d bytes read from file", bytesRead);
		printf("\nBytes read: %s", buffer);
		bytesRead = ReadFile(buffer, fId, 13);
		buffer[13] = '\0';

		printf("\n%d bytes read from file", bytesRead);
		printf("\nBytes read: %s", buffer);
		int file1Closed = CloseFile(fId);
		printf("\nResult of CloseFile 1: %d", file1Closed);

		fId = OpenFile("newFile.txt", FileOpenMode::ReadWrite);
		if (fId)
		{
			bytesWritten = WriteFile(buffer, fId, 13);
			printf("\n\n%d bytes written in new file", bytesWritten);
			int file2Closed = CloseFile(fId);
			printf("\nResult of CloseFile 2: %d", file2Closed);
		}
		else
			printf("\n\nFile couldn't be opened");

		delete[]buffer;
		buffer = nullptr;

		fId = OpenFile("newFile.txt", FileOpenMode::ReadOnly);
		if (fId)
		{
			buffer = new char[14];

			printf("\n\nNew file opened");
			bytesRead = ReadFile(buffer, fId, 13);
			buffer[13] = '\0';
			printf("\n%d bytes read from new file", bytesRead);
			printf("\nBytes read: %s", buffer);
			int file3Closed = CloseFile(fId);
			printf("\nResult of CloseFile 3: %d", file3Closed);

			delete[]buffer;
			buffer = nullptr;
		}
		else
			printf("\n\nFile couldn't be opened");

	}
	else
		printf("\n\nFile couldn't be opened");

	printf("\n\nPress Enter to quit...");
	getchar();

	return 0;
}

