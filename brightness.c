#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>


int main(int argc, const char* argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s [0..100]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE* fp = fopen("/sys/class/backlight/psb-bl/brightness", "w+");

	if(fp == NULL)
	{
		printf("Could not set brightness, do you have the right permissions?\n");
		exit(EXIT_FAILURE);
	}

	long int val = strtol(argv[1], NULL, 10);

	if(val < 0 || val > 100)
	{
		fprintf(stderr, "Brightness should be between 0 and 100!\n");
		exit(EXIT_FAILURE);
	}
	if(fprintf(fp, "%ld", val) < 0)
	{
		printf("Could not set brightness, do you have the right permissions?");
	}
	else 
	{
		printf("Brightness set to %ld%%\n", val);
	}
	fclose(fp);
}
