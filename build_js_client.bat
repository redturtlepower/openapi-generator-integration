rmdir /q /s client\js\openapi
REM generate the client source code from the OpenAPI spec petstore.yaml:
java -jar openapi-generator-cli-4.2.3.jar generate -g javascript -i petstore.yaml -o client\js\openapi
pause