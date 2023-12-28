# vs_libc_replacement
A replacement for Visual Studio's libc. The aim is to reduce executable size and keep the code as simple as possible, even if it means the implementations aren't standards compliant.

To use it:
1. Add this project to your solution.
2. Link with /NODEFAULTLIB (from the Project Properties, set Linker->Input->Ignore All Default Libraries to Yes).
3. Set the entry point to "premain" in the linker options (from the Project Properties, set Linker->Advanced->Entry Point).
4. Enable MASM support in VS. To do this in VS 2013 right click on the project, select "Build Dependencies->Build Customizations". Enable masm in the resulting dialog. Then right click on each of the .asm files, select Properties, the select Microsoft Macro Assembler as the Item Type.


This is a work in progress. Compared to something like Musl or uCLibc it's just a toy. Unfortunately those packages didn't work with Visual Studio last time I checked.

If you are trying to produce small exes on Windows, it might be possible to use this project in conjunction with http://www.crinkler.net. It replaces the Visual Studio linker with one that has many tricks to reduce executable size.

I found (and borrowed from) these are other tiny-libc-for-Windows projects:
* https://www.codeproject.com/Articles/15156/Tiny-C-Runtime-Library
* https://github.com/leepa/libctiny
* https://www.benshoof.org/blog/minicrt
* https://github.com/dreckard/minicrt
* https://github.com/malxau/minicrt/tree/master/crt
