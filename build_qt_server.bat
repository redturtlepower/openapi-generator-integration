REM generate the server source code from the OpenAPI spec petstore.yaml:
java -jar openapi-generator-cli-4.2.3.jar generate -g cpp-qt5-qhttpengine-server -i petstore.yaml -o server\qt\openapi



REM The OpenAPIgenerator does not generate a pro/pri file. Build one now! 
REM "qmake -project" builds a .pro file from all files in the folder.
REM Info: If run on Windows 10, although qmake is in PATH, running this file 
REM requires to specify a full path to qmake.
REM This issue might only arise in case of running this script from a drive other than C.

pushd server\qt\openapi\server
qmake -project -o server.pro



REM Build a .pri file from the .pro file by copying everything 
REM but the following lines, which effectively only keeps HEADERS and SOURCES.

type server.pro | findstr /v # | findstr /v TEMPLATE | findstr /v TARGET | findstr /v INCLUDEPATH | findstr /v DEFINES  > server.pri



REM The generated pro/pri file does not have proper $$PWD prefixes. Add them.

cscript %~dp0qtserver_add_prefix_pwd.vbs server.pri

popd
pause