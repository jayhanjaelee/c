/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-04 19:24
 */

#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL); // Initialize the library

  curl = curl_easy_init(); // Get an easy handle
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com/"); // Set the URL option

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);

    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* Always cleanup */
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup(); // Clean up the global libcurl environment
  return 0;
}

