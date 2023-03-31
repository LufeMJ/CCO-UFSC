#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char** argv) {

    pid_t pFilho1;
    pid_t pFilho2;
    pFilho1 = fork();


    if (pFilho1 == 0) {
        printf("Processo pai criou %d\n", pFilho1);

        pFilho2 = fork();

        if (pFilho2 == 0) {
            printf("Processo pai criou %d\n", pFilho2);
            wait(NULL);
        }

        else {
            printf("Processo filho %d criado\n", getpid());
        } 
    }
    else {
        printf("Processo filho %d criado\n", getpid());
    }

    if(wait(NULL) < 0){
        printf("Processo pai finalizado!\n");
    }

    return 0;
}
