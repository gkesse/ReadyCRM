@echo off
::===============================================
set "PATH=C:\Qt\5.15.0\mingw81_64\bin;%PATH%" 
set "PATH=C:\Qt\Tools\mingw810_64\bin;%PATH%"
set "PATH=C:\wamp64\bin\mysql\mysql5.7.24\bin;%PATH%" 
::===============================================
set "GPROJECT_ROOT=C:\Users\Admin\Downloads\Programs"
set "GPROJECT_PATH=%GPROJECT_ROOT%\ReadyCRM"
set "GDATA_PATH=%GPROJECT_PATH%\cpp\win\data"
set "GSTYLE_PATH=%GDATA_PATH%\css\style.css"
set "GSQLITE_DB_PATH=%GDATA_PATH%\sqlite\config.dat"
set "GFONT_PATH=%GDATA_PATH%\font"
set "GIMG_PATH=%GDATA_PATH%\img"
set "GPDF_PATH=%GDATA_PATH%\pdf\config.pdf"
::===============================================
set "GGIT_URL=https://github.com/gkesse/ReadyCRM.git"
set "GGIT_NAME=ReadyCRM"
::===============================================
set "GMYSQL_HOST=localhost"
set "GMYSQL_PORT=3306"
set "GMYSQL_USER=root"
set "GMYSQL_PASS=super"
::===============================================
set "GMYSQL_DATABASE=dolibarr"
set "GMYSQL_TABLE=llx_user"
set "GMYSQL_TABLE_FILTER=user"
set "GMYSQL_USER_REF=gkesse"
set "GMYSQL_HOST_REF=localhost"
set "GMYSQL_PASS_REF=admin"
::===============================================
