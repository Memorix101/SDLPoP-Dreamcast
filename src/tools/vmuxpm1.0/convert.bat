@echo off

REM Check if the executable exists
if not exist "vmuxpm.exe" (
    echo Error: vmuxpm.exe not found.
    echo Make sure the executable is in the same directory as this batch file.
    exit /b 1
)

REM Check if the input file exists
if not exist "input_file.bmp" (
    echo Error: input_file.bmp not found.
    echo Make sure the input file is in the same directory as this batch file.
    exit /b 1
)

REM Convert the image to vmu_icon.h
echo Converting input_file.bmp to vmu_icon.h...
vmuxpm.exe input_file.bmp > vmu_icon.h

REM Check if conversion was successful
if %errorlevel% neq 0 (
    echo Error converting image to vmu_icon.h
    exit /b 1
) else (
    echo Successfully created vmu_icon.h
)

echo Conversion completed.