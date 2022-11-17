#include "dl.h"

#include <stdio.h>
#include <curl/curl.h>

#include "log.h"

int dl_init(void) {
	
	//socketInitializeDefault();
	curl_global_init(CURL_GLOBAL_DEFAULT);
	
	return 0;
}

int dl_start(void) {
	
	CURL *curl = curl_easy_init();
	
	if (curl) {

		CURLcode res;
		
		curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/");
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) log_error(curl_easy_strerror(res));
		else log_error("everything works");
		
		curl_easy_cleanup(curl);
		
	}
	
	return 0;
}

int dl_exit(void) {
	
	curl_global_cleanup();
	//socketExit();
	
	return 0;
}