```
██████╗  ██████╗ ███████╗██╗     ██╗██████╗ 
██╔══██╗██╔═══██╗██╔════╝██║     ██║██╔══██╗
██║  ██║██║   ██║███████╗██║     ██║██████╔╝
██║  ██║██║   ██║╚════██║██║     ██║██╔══██╗
██████╔╝╚██████╔╝███████║███████╗██║██████╔╝
╚═════╝  ╚═════╝ ╚══════╝╚══════╝╚═╝╚═════╝ 

© Jeremy Simon Thornton 2024   v 0.6    
```
A retro programming library to make life easier using the DOS functions of MSDOS/PCDOS/DRDOS 

Also, (see [BIOSLIB](https://github.com/cspjst/BIOSLIB/)) inspired by David Jurgens' HelpPC Reference Library and my desire to practice 8086 assembly language like it was 1986 :)

> [!TIP]
> *Adding the Library*
> 
> In your main project repository (the one using DOSLIB):
> ```bash
> git submodule add https://github.com/cspjst/DOSLIB.git doslib
> ```

> [!IMPORTANT]  
> DOSLIB is dependant on [BIOSLIB](https://github.com/cspjst/BIOSLIB/), ergo, you must initialize submodules:
> ```git
> # First-time clone
> git clone --recurse-submodules https://github.com/cspjst/DOSLIB.git
> 
> # OR, if already cloned:
> git submodule update --init --recursive
> 
> # To pull latest BIOSLIB changes later:
> cd bioslib
> git pull origin main
> cd ..
> git add bioslib
> git commit -m "Sync BIOSLIB submodule"
>  ```

