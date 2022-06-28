#include<stdio.h>
#include<dirent.h>
#include<string.h>
 
void show_ls(char filename[]);
int main(int argc,char* argv[]) {
	if(argc == 1)
		show_ls(".");
	while(--argc)
	{
		printf("%s: \n",*++argv);
		show_ls(*argv);
		printf("\n");
	}
	return 0;
}
void show_ls(char filename[])
{
	DIR* dir_ptr;  //the directory
	struct dirent* direntp; //each entry
	
	if((dir_ptr = opendir(filename)) == NULL)
		fprintf(stderr,"ls1: cannot open%s \n",filename);
	while((direntp = readdir(dir_ptr)) != NULL)
		printf("%-10s",direntp->d_name);
	closedir(dir_ptr);
}
