SELECT
 trans.session_id as [Session ID],
 trans.transaction_id as [Transaction ID],
 tas.name as [Transaction Name],
 tds.database_id as [Database ID]
 FROM sys.dm_tran_active_transactions tas
 INNER JOIN sys.dm_tran_database_transactions tds ON (tas.transaction_id = tds.transaction_id )
 INNER JOIN sys.dm_tran_session_transactions trans ON (trans.transaction_id=tas.transaction_id)
 WHERE trans.is_user_transaction = 1 -- user
 AND tas.transaction_state = 2 -- active
 AND tds.database_transaction_begin_time IS NOT NULL
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

SET /A "sourceFolder = C:\Users\Sqlsijadmin\Documents\atualizacoes\mjcvupdate"
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
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\QueueService %destinationFolderAppServer%\QueueServiceTeste
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWFTeste\WFTeste
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWindowsService %destinationFolderAppServer%\WindowsServiceTeste

    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt C:\Users\Sqlsijadmin\Documents\atualizacoes\mjcvupdate\MJCVAPI \\10.4.2.169\c$\inetpub\wwwroot\MJCVAPI
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt C:\Users\Sqlsijadmin\Documents\atualizacoes\mjcvupdate\IdentityServer \\10.4.2.169\c$\inetpub\wwwroot\IdentityServer
    xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt C:\Users\Sqlsijadmin\Documents\atualizacoes\mjcvupdate\MJCVWebMVC \\10.4.2.169\c$\inetpub\wwwroot\MJCVWebMVC
    
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\SIJ %destinationFolderWebServerTest%\sij
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\DJE %destinationFolderWebServerTest%\dje
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PN %destinationFolderWebServerTest%\pn
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\PJ %destinationFolderWebServerTest%\pj
    
    ::PAUSE > nul && GOTO start
EXIT /B 0

:prod
    ::ECHO Inside prod.
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\QueueService %destinationFolderAppServer%\QueueService    
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFInformatizacao
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFOutros
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWorkflowService %destinationFolderAppServer%\ServicosWF\WFProcPenal    
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWindowsService %destinationFolderAppServer%\WindowsService\

    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVAPI %destinationFolderWebServerProd%\MJCVAPI
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\IdentityServer %destinationFolderWebServerProd%\IdentityServer
    ::xcopy /v /f /r /d /i /s /y /exclude:excludedfileslist.txt %sourceFolder%\MJCVWebMVC %destinationFolderWebServerProd%\MJCVWebMVC

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