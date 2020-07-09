#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
int caps;
caps = open("/sys/class/leds/input3::capslock/brightness", O_RDONLY);
char c;
int r = pread(caps, &c, 1, 0);
char s=c;
while(c==s){
r = pread(caps, &c, 1, 0);
}
printf("%c\n", c);
}
