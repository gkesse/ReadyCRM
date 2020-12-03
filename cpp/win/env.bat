@echo off
::===============================================
set "PATH=C:\Qt\5.15.0\mingw81_64\bin;%PATH%" 
set "PATH=C:\Qt\Tools\mingw810_64\bin;%PATH%"
set "PATH=C:\dolibarr\bin\mariadb\mariadb10.4.10\bin;%PATH%" 
::===============================================
set "GPROJECT_ROOT=C:\Users\Admin\Downloads\Programs"
set "GPROJECT_PATH=%GPROJECT_ROOT%\ReadyCRM"
set "GDATA_PATH=%GPROJECT_PATH%\cpp\win\data"
set "GSTYLE_PATH=%GDATA_PATH%\css\style.css"
set "GSQLITE_DB_PATH=%GDATA_PATH%\sqlite\config.dat"
set "GFONT_PATH=%GDATA_PATH%\font"
set "GIMG_PATH=%GDATA_PATH%\img"
::===============================================
set "GGIT_URL=https://github.com/gkesse/ReadyCRM.git"
set "GGIT_NAME=ReadyCRM"
::===============================================
set "GMYSQL_HOST=localhost"
set "GMYSQL_PORT=9180"
set "GMYSQL_USER=root"
set "GMYSQL_PASS=admin"
set "GMYSQL_DATABASE=dolibarr"
::===============================================
