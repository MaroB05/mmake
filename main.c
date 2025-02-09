#include <stdio.h>
#include <string.h>
#include "fileio.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <assert.h>

bool file_exists(char dir_path[], char filename[]);
bool locate_tag(char command[], FILE stream[], size_t *line);

int main(int argc, char* argv[]){
  FILE* file = NULL;
  const int buff_size = 4 * 1024; 
  char commands[buff_size];
  size_t line = 0;
  
  if (argc == 1){
    fputs("not enough args\n", stderr);
    return 1;
  }

  if (!file_exists("./", "Makefile")){
    fputs("No Makefile found\n", stderr);
    return 1;
  }
  
  file = openFile("Makefile", "r", NULL);

  if (!locate_tag(argv[1], file, &line))
    fprintf(stderr,"Make: %s command is not found\n", argv[1]);

  while(fgets(commands,  buff_size, file) &&
	commands[strlen(commands)-2] != ':'){
    line++;
    if (commands[0] != '\t'){
      fprintf(stderr, "[Make]formatting error: %lu\n", line);
      exit(1);
    }

    if(system(commands))
      fputs("Make failed\n", stderr);
  }
  
  return 0;
}

bool file_exists(char dir_path[], char filename[]){
  assert(dir_path != NULL);
  assert(filename != NULL);
  DIR* current_dir = opendir(dir_path);
  struct dirent* entry;
  while((entry = readdir(current_dir))){
    if (!strcmp(entry->d_name, filename))
      return 1;
  }
  return 0;
}

bool locate_tag(char command[], FILE stream[], size_t *line){
  const int buff = 4 * 1024;
  char buffer[buff];
  while (fgets(buffer, buff, stream)){
    (*line)++;
    if (!strcmp(strtok(buffer, ":"), command))
      return 1;
  }
  return 0;
}
