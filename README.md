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

## Progress...

*N.B.* Implemented on an ad hoc basis as the need(s) arise:

### DOS File Services:
- [x] INT 21,36  Get disk free space
- [ ] INT 21,37  Get/set switch character (undocumented)
- [ ]	INT 21,38  Get/set country dependent information
- [ ]	INT 21,39  Create subdirectory (mkdir)
- [ ]	INT 21,3A  Remove subdirectory (rmdir)
- [ ]	INT 21,3B  Change current subdirectory (chdir)
- [x]	INT 21,3C  Create file using handle
- [x]	INT 21,3D  Open file using handle
- [x]	INT 21,3E  Close file using handle
- [x]	INT 21,3F  Read file or device using handle
- [x]	INT 21,40  Write file or device using handle
- [x]	INT 21,41  Delete file
- [x]	INT 21,42  Move file pointer using handle
- [x]	INT 21,43  Change file mode
- [ ]	INT 21,44  I/O control for devices (IOCTL)
- [ ]	INT 21,45  Duplicate file handle
- [ ]	INT 21,46  Force duplicate file handle
- [ ]	INT 21,47  Get current directory
...
- [ ]	INT 21,4E  Find first matching file
- [ ]	INT 21,4F  Find next matching file
...
- [x]	INT 21,56  Rename file
- [ ]	INT 21,57  Get/set file date and time using handle

### DOS Memory Services:
- [ ]
