# Use Ubuntu as the base image
FROM ubuntu:latest

# Install necessary build dependencies
RUN apt-get update && \
    apt-get install -y build-essential gdb cmake git python3

RUN adduser vscode

# Define an entry point
ENTRYPOINT ["/bin/sh"]