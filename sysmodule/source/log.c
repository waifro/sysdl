#include "log.h"

#include <stdio.h>
#include <string.h>

int log_data_recv(char *buf) {
	
	FILE *fd = fopen("/atmosphere/contents/0172031337181498/data.log", "a+");
	if (fd == NULL) return -1;
	
	fwrite(buf, sizeof(char), (size_t)strlen(buf), fd);
	
	fclose(fd);
	
	return 0;
}

int log_error(char *text) {
	
	FILE *fd = fopen("/atmosphere/contents/0172031337181498/error.log", "a+");
	if (fd == NULL) return -1;
	
	fwrite(text, sizeof(char), (size_t)strlen(text), fd);
	
	fclose(fd);
	
	return 0;
}