/***********************************************************************
*
* Project: inject.so
*
* Author: Travis Phillips
*
* Date: 02/05/2021
*
* Project Repo:
*  https://github.com/ProfessionallyEvil/LD_PRELOAD-run-at-load-time
*
* Purpose: This is simple code for a LD_PRELOAD shared object that
*          demostrates how to use the constructor & destructor
*          attribute to run code at load time and unload time without
*          hijacking a function.
*
* Compile: gcc -FPIC -shared inject.c -o inject.so
*
***********************************************************************/
#include <stdio.h>  // Standard include
#include <string.h> // For memset
#include <limits.h> // For the PATH_MAX constant
#include <unistd.h> // For readlink

/////////////////////////////////
// Color Constants
/////////////////////////////////
#ifdef NOCOLOR
    static const char RED[]= "";
    static const char GREEN[]= "";
    static const char BLUE[]= "";
    static const char NC[]= "";
#else
    static const char RED[]= "\033[31;1m";
    static const char GREEN[]= "\033[32;1m";
    static const char BLUE[]= "\033[34;1m";
    static const char NC[]= "\033[0m";
#endif

void __attribute__((constructor)) run_me_at_load_time() {
  /////////////////////////////////////////////////////////
  // This function will run at load time because of the
  // __attribute__((constructor)) in the function
  // definition.
  /////////////////////////////////////////////////////////

  // variable to store program path
  char prog_name[PATH_MAX];

  /////////////////////////////////////////////////////////
  // Zero out the buffer and use readlink() to resolve the
  // symlink path of /proc/self/exe to get the path to the
  // process we are injected into.
  /////////////////////////////////////////////////////////
  memset(prog_name, 0, sizeof(prog_name));
  readlink("/proc/self/exe", prog_name, sizeof(prog_name)-1);

  /////////////////////////////////////////////////////////
  // Print a message to the user showing our shared object
  // is loaded into the process and dump the PID and path
  // of the process we are running in.
  /////////////////////////////////////////////////////////
  printf("\n [%s+%s] %sInject.so Loaded!\n%s", GREEN, NC, GREEN, NC);
  printf(" [%s*%s] %sPID:%s %d\n", BLUE, NC, BLUE, NC, getpid());
  printf(" [%s*%s] %sProcess:%s %s\n\n", BLUE, NC, BLUE, NC, prog_name);
}

void __attribute__((destructor)) run_me_at_unload() {
  /////////////////////////////////////////////////////////
  // This function will run when the library is unloaded
  // because of the __attribute__((destructor)) in the
  // function definition.
  /////////////////////////////////////////////////////////
  printf("\n [%s-%s] %sInject.so is being unloaded!%s\n", RED, NC, RED, NC);

}
