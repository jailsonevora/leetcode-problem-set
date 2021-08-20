https://we.tl/t-1bbBNqEJ2m
https://docs.jexusmanager.com/getting-started/install.html
::https://docs.microsoft.com/en-us/windows-server/administration/windows-commands/xcopy
@ECHO OFF 
:: This batch file details Windows Server, hardware, and networking configuration, plus updating the SIJ enviroment
TITLE My System Info
ECHO Please wait... Checking system information.
:: Section 1: Windows Server information
ECHO ===========================================================
ECHO WINDOWS INFO
ECHO ===========================================================
systeminfo | findstr /c:"OS Name"
systeminfo | findstr /c:"OS Version"
systeminfo | findstr /c:"System Type"
:: Section 2: Hardware information.
ECHO ===========================================================
ECHO HARDWARE INFO
ECHO ===========================================================
systeminfo | findstr /c:"Total Physical Memory"
wmic cpu get name
wmic diskdrive get name,model,size
wmic path win32_videocontroller get name
:: Section 3: Networking information.
ECHO ===========================================================
ECHO NETWORK INFO
ECHO ===========================================================
ipconfig | findstr IPv4
ipconfig | findstr IPv6

SET /A "sourceFolder = C:\Users\sqlsijadmin\Documents\atualizacoes\mjcvupdate"
SET /A "destinationFolderAppServer = \\10.4.2.167\c$\servicos"
SET /A "destinationFolderWebServerProd = \\10.4.2.168\c$\inetpub\wwwroot"
SET /A "destinationFolderWebServerTest = \\10.4.2.169\c$\inetpub\wwwroot"

:start
::cls
    ::The else needs to be on the same "line" (a) as the if.
    ECHO ===========================================================
    SET /p type=Please enter the system to update all, test or prod:
    ECHO ===========================================================
    IF /i "%type%"=="test" GOTO test
    IF /i "%type%"=="prod" GOTO prod
    IF /i "%type%"=="all" ( GOTO all 
    ) ELSE (echo input is incorrect! && PAUSE > nul && GOTO start)

:test
    ::ECHO %sourceFolder%
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\QueueService %destinationFolderAppServer%\QueueServiceTeste
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWFTeste\WFTeste
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWindowsService %destinationFolderAppServer%\WindowsServiceTeste

    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVAPI %destinationFolderWebServerTest%\MJCVAPI
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\IdentityServer %destinationFolderWebServerTest%\IdentityServer
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWebMVC %destinationFolderWebServerTest%\MJCVWebMVC
    
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\SIJ %destinationFolderWebServerTest%\sij
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\DJE %destinationFolderWebServerTest%\dje
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PN %destinationFolderWebServerTest%\pn
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PJ %destinationFolderWebServerTest%\pj
    
    ::PAUSE > nul && GOTO start
EXIT /B 0

:prod
    ::ECHO Inside prod.
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\QueueService %destinationFolderAppServer%\QueueService    
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFInformatizacao
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFOutros
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFProcPenal    
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWindowsService %destinationFolderAppServer%\WindowsService\

    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVAPI %destinationFolderWebServerProd%\MJCVAPI
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\IdentityServer %destinationFolderWebServerProd%\IdentityServer
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWebMVC %destinationFolderWebServerProd%\MJCVWebMVC

    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\SIJ %destinationFolderWebServerProd%\sij
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\DJE %destinationFolderWebServerProd%\dje
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PN %destinationFolderWebServerProd%\pn
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PJ %destinationFolderWebServerProd%\pj
    
    ::PAUSE > nul && GOTO start
EXIT /B 0

:all
    ECHO Inside All and I am going to call...
    call :test
    call :prod
    PAUSE > nul && GOTO start
GOTO end