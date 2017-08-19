#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	FILE *fp = fopen("./TestFile.txt", "r");
	long lSize;
	char *buffer;
	size_t result;
	int row, col;
	if(fp){
		// obtain file size
		fseek(fp, 0, SEEK_END);
		lSize = ftell(fp);
		printf("%ld\n", lSize);
		rewind(fp);
		buffer = (char *)malloc(sizeof(char) * lSize);
		if(buffer == NULL) {
			fputs("Memory error\n", stderr);
			exit(2);
		}
		result = fread(buffer, 1, lSize, fp);

		// 
		row = 1;
		col = 1;
		int i = 0;
		char c;
		for(i = 0; i < lSize; i++){
			c = buffer[i];
			if(c == '')
				continue;
			if()
		}
		fclose(fp);
		free(buffer);
	}else{
		printf("This file can not open\n");
	}
	return 0;
}