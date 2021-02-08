/***********************************************************************
*
* Project: hello_world
*
* Author: Travis Phillips
*
* Date: 02/05/2021
*
* Project Repo:
*  https://github.com/ProfessionallyEvil/LD_PRELOAD-run-at-load-time
*
* Purpose: This is simple hello world project that will serve as our
*          injection target for our LD_PRELOAD inject. The goal of
*          this example is to show how code can be ran at load time
*          using LD_PRELOAD without hijacking a function.
*
* Compile: gcc hello_world.c -o hello
*
***********************************************************************/
#include <stdio.h>  // Standard include

int main() {

  //////////////////////////////////////////////////////////////////
  // Print Hello world message and return 0. Very basic C program.
  //////////////////////////////////////////////////////////////////
  puts("Hello World!");
  return 0;
}
