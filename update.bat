@ECHO OFF 
:: This batch file details Windows Server, hardware, and networking configuration, plus updating the SIJ enviroment
TITLE My System Info
ECHO Please wait... Checking system information.
:: Section 1: Windows Server information
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

::type of update = all, prod or test
%type

Set sourceFolder = C:\Users\sqlsijadmin\Documents\atualizacoes
Set destinationFolderAppServer = \\10.4.2.167\c$\servicos
Set destinationFolderWebServerProd = \\10.4.2.169\c$\inetpub\wwwroot
Set destinationFolderWebServerTest = \\10.4.2.168\c$\inetpub\wwwroot

if %type% == "test" goto test
if %type% == "prod" goto prod
if %type% == "all"  goto all

:test
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\QueueService %destinationFolderAppServer%\QueueServiceTeste
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWFTeste\WFTeste
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWindowsService %destinationFolderAppServer%\WindowsServiceTeste
    
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\SIJ %destinationFolderWebServerTest%\sij
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\DJE %destinationFolderWebServerTest%\dje
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PN %destinationFolderWebServerTest%\pn
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PJ %destinationFolderWebServerTest%\pj
goto exit

:prod
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\QueueService %destinationFolderAppServer%\QueueService    
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFInformatizacao
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFOutros
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFProcPenal    
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWindowsService %destinationFolderAppServer%\WindowsService\

    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\SIJ %destinationFolderWebServerTest%\sij
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\DJE %destinationFolderWebServerTest%\dje
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PN %destinationFolderWebServerTest%\pn
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PJ %destinationFolderWebServerTest%\pj
goto exit

:all
    goto test
    goto prod
goto exit