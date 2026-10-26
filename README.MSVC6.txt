MSVC 6.0 build notes
====================

Open a Visual C++ 6.0 command prompt, change to this directory, and run:

    nmake /f Makefile.msvc

This builds compact.exe and uncompact.exe. The original Unix Makefile is
unchanged. The compatibility definitions in compact.h map the Unix file and
string APIs used by this source to their MSVC 6.0 equivalents. File mode
setting (fchmod) is a no-op on Windows; Windows does not expose Unix file
permission bits in the same way.

Examples:
    compact input.txt
    uncompact input.txt.C

As in the original Unix implementation, compact/uncompact may remove the
input file after successfully producing its output. Test on copies first.
