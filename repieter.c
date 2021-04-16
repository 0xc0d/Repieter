#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
int main() {
    int s = socket(2, 1, 0);
    struct sockaddr_in a;
    a.sin_port = htons(4444);
    bind(s, &a, sizeof(a));
    listen(s, 10);
    int c = accept(s, NULL, NULL);
    char b[100];
    while (1) {
        bzero(b, 100);
        read(c, b, 100);
        write(c, b, strlen(b)+1);
    }
}
