#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void capslockPressedHandler(char state);
void capslockListener(int fd, void (*handler)(char state));
int main(){
int caps;
caps = open("/sys/class/leds/input3::capslock/brightness", O_RDONLY);
capslockListener(caps, capslockPressedHandler);
close(caps);
}

void capslockPressedHandler(char state){
	if(state=='0'){	
		printf("CapsLock turned OFF\n");
	}else if(state == '1'){
		printf("Capslock turned ON\n");
	} else {
		printf("WTF?");
	}
}

void capslockListener(int fd, void (*handler)(char state)){
	char c;
	int r = pread(fd, &c, 1, 0);
	char s=c;
	while(c==s){
		r = pread(fd, &c, 1, 0);
	}
	handler(c);
}

