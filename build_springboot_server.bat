rmdir /q /s server\springboot\openapi
REM generate the server source code from the OpenAPI spec petstore.yaml:
java -jar openapi-generator-cli-4.2.3.jar generate -g spring -i petstore.yaml -o server\springboot\openapi -c springboot-options.json

