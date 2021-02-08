# LD_PRELOAD-run-at-load-time
Code samples to go along with the blog post on how to run code at load/unload time when using LD_PRELOAD to inject libraries.

## Links to Tutorials
Blog: TODO - FILL IN WHEN READY

## Overview
This repo is used to provide some code samples to go along side a tutorial in Secure Ideas blogs. This code repo will provide you with the code for:

 * A simple hello world binary target
 * The LD_PRELOAD injection code
 * A make file to build it easily in a Kali VM.
 
The goal of this tutorial is to show how to use constructor and destructor attributes for running code at load/unload time with an LD_PRELOAD shared object to run code without hijacking a function call. In this case, It will demo this on a simple hello world binary but

## Building The Code Using Make.
Once you clone the repo, simply change into the directory and run ```make``` or ```make all``` to build both the game and the LD_PRELOAD hijack shared object. The make file also includes a help option to show all of the build targets:

```
kali@kali:~$ make help
Default Target:
         all => Build the default hello world & inject shared object.

Hello World Targets:
         hello_world => Build the default hello world ELF binary.

Inject Targets:
         inject.so => Build standard LD_PRELOAD inject.so shared object.
         inject.so_nocolor => Build non-colorized LD_PRELOAD inject.so shared object.

Maintance Targets:
         clean => delete the binaries.
kali@kali:~$
```

## Basic Hello World Usage
Standard Hello World build and usage:
```
kali@kali:~$ make hello_world 
gcc -Wall -O3 -s src/hello_world.c -o hello_world
kali@kali:~$ ./hello_world 
Hello World!
kali@kali:~$
```

## Building and injecting inject.so
```
kali@kali:~$ make inject.so        
gcc -Wall -O3 -FPIC -shared src/inject.c -o inject.so
kali@kali:~$ ./hello_world 
Hello World!
kali@kali:~$ LD_PRELOAD=./inject.so ./hello_world
 [+] Inject.so Loaded!
 [*] PID: 1445                                                               
 [*] Process: /home/kali/src/ld_preload_load_time/hello_world

Hello World!

 [-] Inject.so is being unloaded!
kali@kali:~$
```
