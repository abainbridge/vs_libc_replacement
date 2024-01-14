# vs_libc_replacement
A replacement for Visual Studio's C runtime and certain win32 API headers. This project exists because I couldn't get any similar projects to work (see below for a list). One of the problems I found was that #including windows.h caused many link errors such as missing wide character string functions, even though my code didn't deal with wide character strings, and I was building with "Character Set" equal to "Not Set" (as opposed to "Use unicode" or "Use multi-byte").

The priority is to reduce executable size and keep the code as simple as possible, even if it means the implementations aren't standards compliant.

To use it:
* Add this project to your solution.
* In the Release configuration:
  - Link with /NODEFAULTLIB (from the Project Properties, set Linker->Input->Ignore All Default Libraries to Yes).
  - Set the entry point to "premain" in the linker options (from the Project Properties, set Linker->Advanced->Entry Point).
  - Enable MASM support in VS. To do this in VS 2013 right click on the project, select "Build Dependencies->Build Customizations". Enable masm in the resulting dialog. Then right click on each of the .asm files, select Properties, the select Microsoft Macro Assembler as the Item Type.

I test with Visual Studio 2013, with Platform set to Win32. My compiler flags were:
* /GS- - Disable security check.
* /Qpar- - Ignore #pragma loop(hint_parallel).
* /GL - Enable whole program optimization.
* /Gy - Enable function level linking.
* /O1 - Minimize Size.
* /Ob2 - Inline any suitable functions.
* /fp:fast - Use the fast floating point model. This makes floating point operations simpler than the IEEE standard would require. This prevents the compiler inserting function calls to handle things like float-to-int conversions that would otherwise need to be implemented by the CRT.
* /fp:except- - Disable floating point exceptions.
* /GF - Enable string pooling.
* /Gd - Set calling convention to __cdecl.
* /Oi - Enable intrinsic functions.
* /Os - Favour small code.

Linker flags were:
/MANIFEST:NO /LTCG /NXCOMPAT /DYNAMICBASE:NO "kernel32.lib" "user32.lib" "gdi32.lib" "Shcore.lib" "shell32.lib" /MACHINE:X86 /ENTRY:"premain" /OPT:REF /SAFESEH:NO /OPT:ICF /NODEFAULTLIB /TLBID:1 

If you are trying to produce small exes on Windows, it might be possible to use this project in conjunction with http://www.crinkler.net. It replaces the Visual Studio linker with one that has many tricks to reduce executable size.

I found (and borrowed from) these are other tiny-libc-for-Windows projects:
* https://www.codeproject.com/Articles/15156/Tiny-C-Runtime-Library
* https://github.com/leepa/libctiny
* https://www.benshoof.org/blog/minicrt
* https://github.com/dreckard/minicrt
* https://github.com/malxau/minicrt/tree/master/crt
