@echo off
SETLOCAL EnableDelayedExpansion

:: Make build folder
mkdir build

::Hardcoded because yes
mkdir build\tileset

:: CPP compilation settings
SET CC="../cw/mwcceppc.exe"
SET CFLAGS=-I- -i ../k_stdlib -Cpp_exceptions off -enum int -O4,s -use_lmw_stmw on -fp hard -rostr -sdata 0 -sdata2 0 -maxerrors 1
SET CPPFILES=
for %%f in (*.cpp) do (
    SET "CPPFILES=%%~nf !CPPFILES!"
    echo %CPPFILES%
)

:: Compile CPP
@echo on
SET OBJECTS=
FOR %%H IN (%CPPFILES%) DO (
    echo "Compiling %%H.cpp..."
    %CC% %CFLAGS% -c -o build/%%H.o %%H.cpp
    SET "OBJECTS=build/%%H.o !OBJECTS!"
)
:: Link
echo Linking...
"../Kamek/bin/Debug/Kamek" %OBJECTS% -dynamic -externals=../symbols.txt -versions=../versions.txt -output-kamek=build\$KV$.bin
if %ErrorLevel% equ 0 (
    move /Y build\*.bin "../vp"
    copy /Y *.bin "../vp/files/Uploaded Packs/varietypack/boot/"
)

rmdir /Q /S build

:end
ENDLOCAL