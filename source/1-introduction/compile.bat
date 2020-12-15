@echo off
if exist %1 ( g++ -std=c++11 -lm -o Z.exe %1 ) else exit /b
if not errorlevel 1 ( Z.exe )
