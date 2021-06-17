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

SET sourceFolder = C:\Users\sqlsijadmin\Documents\atualizacoes
SET destinationFolderAppServer = \\10.4.2.167\c$\servicos
SET destinationFolderWebServerProd = \\10.4.2.169\c$\inetpub\wwwroot
SET destinationFolderWebServerTest = \\10.4.2.168\c$\inetpub\wwwroot

:start
cls
    ::The else needs to be on the same "line" (a) as the if.
    ECHO ===========================================================
    SET /p type=Please enter the system to update all, test or prod:
    ECHO ===========================================================
    IF /i "%type%"=="test" GOTO test
    IF  /i "%type%"=="prod" GOTO prod
    IF /i "%type%"=="all" ( GOTO all 
    ) ELSE (echo input is incorrect! && PAUSE > nul && GOTO start)

:test
    ECHO Inside test.
    rem xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\QueueService %destinationFolderAppServer%\QueueServiceTeste
    rem xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWFTeste\WFTeste
    rem xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWindowsService %destinationFolderAppServer%\WindowsServiceTeste
    
    rem xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\SIJ %destinationFolderWebServerTest%\sij
    rem xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\DJE %destinationFolderWebServerTest%\dje
    rem xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PN %destinationFolderWebServerTest%\pn
    rem xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PJ %destinationFolderWebServerTest%\pj
    ::PAUSE > nul && GOTO start
EXIT /B 0

:prod
    ECHO Inside prod.
    rem xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\QueueService %destinationFolderAppServer%\QueueService    
    :: xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFInformatizacao
    :: xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFOutros
    :: xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFProcPenal    
    :: xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWindowsService %destinationFolderAppServer%\WindowsService\

    :: xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\SIJ %destinationFolderWebServerTest%\sij
    :: xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\DJE %destinationFolderWebServerTest%\dje
    :: xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PN %destinationFolderWebServerTest%\pn
    :: xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PJ %destinationFolderWebServerTest%\pj
    ::PAUSE > nul && GOTO start
EXIT /B 0

:all
    ECHO Inside All and I am going to call...
    call :test
    call :prod
    PAUSE > nul && GOTO start
GOTO end