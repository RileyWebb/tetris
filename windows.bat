REG ADD "HKCU\Console" /v "VirtualTerminalLevel" /t REG_DWORD /d 1 /F
start conhost.exe bin/tetris.exe