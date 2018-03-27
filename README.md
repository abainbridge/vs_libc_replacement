# vs_libc_replacement
A replacement for Visual Studio's libc. The aim is to reduce executable size and keep the code as simple as possible, even if it means the implementations aren't standards compliant.

Add this project to your solution, then link with /NODEFAULTLIB (from the Project Properties, set Linker->Input->Ignore All Default Libraries to Yes).

This is a work in progress. Compared to something like Musl or uCLibc it's just a toy. Unfortunately those packages didn't work with Visual Studio last time I checked.

If you are trying to produce small exes on Windows, I highly recommend you use this project in conjunction with http://www.crinkler.net. It replaces the Visual Studio linker with one that has many tricks to reduce executable size.
