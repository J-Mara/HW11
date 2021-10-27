#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int randGen(){
  int rando = open("/dev/random", O_RDONLY);
  if(rando == -1){
    printf("there has been an error: %s\n", strerror(errno));
    return -1;
  }else{
    int res = 0;
    int *p;
    p = &res;
    read(rando, p, sizeof(int));
    return res;
  }
}

int main(){
  //printf("rando: %d\n", randGen());
  int randar[10];
  int i;
  for(i = 0; i < 10; i++){
    randar[i] = randGen();
  }
  for(i = 0; i < 10; i++){
    printf("element %d of the array: %d\n", i, randar[i]);
  }
  int wee = open("wee.dat", O_RDWR | O_CREAT, 0644);
  if(wee == -1){
    printf("there has been an error: %s\n", strerror(errno));
    return -1;
  }
  printf("writing... \n");
  write(wee, randar, 10 * sizeof(int));
  int resultar[10];
  int weinp = open("wee.dat", O_RDONLY);
  if(weinp == -1){
    printf("there has been an error: %s\n", strerror(errno));
    return -1;
  }
  printf("reading... \n");
  int test = read(weinp, resultar, 10 * sizeof(int));
  if(test == -1){
    printf("we have an error");
  }
  for(i = 0; i < 10; i++){
    printf("element %d of the array: %d\n", i, resultar[i]);
  }
}
