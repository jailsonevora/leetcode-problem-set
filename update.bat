@ECHO OFF 
:: This batch file details Windows 10, hardware, and networking configuration.
TITLE My System Info
ECHO Please wait... Checking system information.
:: Section 1: Windows 10 information
ECHO ==========================
ECHO WINDOWS INFO
ECHO ============================
systeminfo | findstr /c:"OS Name"
systeminfo | findstr /c:"OS Version"
systeminfo | findstr /c:"System Type"
:: Section 2: Hardware information.
ECHO ============================
ECHO HARDWARE INFO
ECHO ============================
systeminfo | findstr /c:"Total Physical Memory"
wmic cpu get name
wmic diskdrive get name,model,size
wmic path win32_videocontroller get name
:: Section 3: Networking information.
ECHO ============================
ECHO NETWORK INFO
ECHO ============================
ipconfig | findstr IPv4
ipconfig | findstr IPv6
START https://support.microsoft.com/en-us/windows/windows-10-system-requirements-6d4e9a79-66bf-7950-467c-795cf0386715

::type of update = all, prod or test
%type

Set %sourceFolder
Set %destinationFolderAppServer = \\10.4.2.167\c$\servicos
Set %destinationFolderWebServerProd = \\10.4.2.169\c$\inetpub\wwwroot
Set %destinationFolderWebServerTest = \\10.4.2.168\c$\inetpub\wwwroot

if %type% == "test"
    :: copy from local folder to
    ::robocopy C:\Example1\ C:\Example2 /e /copyall
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\QueueService destinationFolderAppServer\QueueServiceTeste
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\MJCVWorkflowService destinationFolderAppServer\ServicosWFTeste
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\MJCVWindowsService destinationFolderAppServer\WindowsServiceTeste
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\SIJ destinationFolderWebServerTest\sij
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\DJE destinationFolderWebServerTest\dje
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\PN destinationFolderWebServerTest\pn
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\PJ destinationFolderWebServerTest\pj

if %type% == "prod"
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\QueueService destinationFolderAppServer\QueueServiceTeste
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\MJCVWorkflowService destinationFolderAppServer\ServicosWFTeste
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\MJCVWindowsService destinationFolderAppServer\WindowsServiceTeste
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\SIJ destinationFolderWebServerTest\sij
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\DJE destinationFolderWebServerTest\dje
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\PN destinationFolderWebServerTest\pn
    xcopy /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder\PJ destinationFolderWebServerTest\pj

if %type% == "all"
    copy C:\dirA dirB
    robocopy C:\Example1\ C:\Example2 /e /copyall

:Display
SET /A index = 2
echo The value of type is %type%
exit /B 0

PAUSE