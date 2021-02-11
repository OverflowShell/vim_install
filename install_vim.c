#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
// Colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
// Functions
int termux();
int apt();
int pacman();
int xbps();
int banner();

// Code
int main() {
    int x;
    printf(ANSI_COLOR_YELLOW "\t[1]-Termux" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "\t[2]-Debian dists (apt package manager)" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "\t[3]-Arch dists (pacman package manager)" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "\t[4]-Void linux (xbps package manager)" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "\nElige el sistema para el cual configurar vim: " ANSI_COLOR_RESET);
    scanf("%i",&x);
    if (x == 1) {
        termux();
    }
    else if (x == 2) {
        apt();
    }
    else if (x == 3) {
        pacman();
    }
    else if (x == 4) {
        xbps();
    }
    else {
        printf("No existe esta opcion");
    }
    /*
    Code:
    system();
    */
    return 0;
}
int termux(int a) {
    printf(ANSI_COLOR_GREEN "Iniciando instalacion de las dependencias" ANSI_COLOR_RESET);
    system("apt install git python python3 yarn ccls nodejs");
    printf(ANSI_COLOR_GREEN "Instalando el manager vundle.vim");
    system("git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim");
    printf(ANSI_COLOR_GREEN "Instalando los requerimientos" ANSI_COLOR_RESET);
    system("/data/data/com.termux/files/usr/bin/python -m pip install --upgrade pip");
    system("pip3 install pylint mypy");
    system("yarn install --frozen-lockfile");
    sleep(1);
    system("cp .vimrc ~/.vimrc");
    printf(ANSI_COLOR_GREEN "Debera ejecutar vim y poner :PluginInstall" ANSI_COLOR_RESET);
    a = 0;
    return 0;
}
int apt(int b) {
    printf(ANSI_COLOR_GREEN "Iniciando instalacion de las dependencias" ANSI_COLOR_RESET);
    system("sudo apt install git python python3 python-pip python3-pip yarn ccls nodejs");
    printf(ANSI_COLOR_GREEN "Instalando el manager vundle.vim" ANSI_COLOR_RESET);
    system("git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim");
    printf(ANSI_COLOR_GREEN "Instalando los requerimientos" ANSI_COLOR_RESET);
    system("pip3 install pylint mypy");
    system("yarn install --frozen-lockfile");
    sleep(1);
    system("cp .vimrc ~/.vimrc");
    printf(ANSI_COLOR_GREEN "Debera ejecutar vim y poner :PluginInstall" ANSI_COLOR_RESET);
    return 0;
}
int pacman(int c) {
    printf(ANSI_COLOR_GREEN "Iniciando instalacion de las dependencias" ANSI_COLOR_RESET);
    system("sudo pacman -Sy git python python3 python-pip python3-pip yarn ccls nodejs");
    printf(ANSI_COLOR_GREEN "Instalando el manager vundle.vim" ANSI_COLOR_RESET);
    system("git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim");
    printf(ANSI_COLOR_GREEN "Instalando los requerimientos" ANSI_COLOR_RESET);
    system("pip3 install pylint mypy");
    system("yarn install --frozen-lockfile");
    sleep(1);
    system("cp .vimrc ~/.vimrc");
    printf(ANSI_COLOR_GREEN "Debera ejecutar vim y poner :PluginInstall" ANSI_COLOR_RESET);
    return 0;
}
int xbps(int d) {
    printf(ANSI_COLOR_GREEN "Iniciando instalacion de las dependencias" ANSI_COLOR_RESET);
    system("sudo xbps-install -Sy git python python3 python-pip python3-pip yarn ccls nodejs");
    printf(ANSI_COLOR_GREEN "Instalando el manager vundle.vim" ANSI_COLOR_RESET);
    system("git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim");
    printf(ANSI_COLOR_GREEN "Instalando los requerimientos" ANSI_COLOR_RESET);
    system("pip3 install pylint mypy");
    system("yarn install --frozen-lockfile");
    sleep(1);
    system("cp .vimrc ~/.vimrc");
    printf(ANSI_COLOR_GREEN "Debera ejecutar vim y poner :PluginInstall" ANSI_COLOR_RESET);
    return 0;
}