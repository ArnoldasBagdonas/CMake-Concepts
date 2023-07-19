# Use Ubuntu as the base image
FROM ubuntu:latest

# Install necessary build dependencies
RUN apt-get update && \
    apt-get install -y build-essential gdb cmake git python3 lsb-release software-properties-common wget


# install clang
ARG CLANG_VER=16
WORKDIR /tmp
RUN wget https://apt.llvm.org/llvm.sh && chmod +x llvm.sh
RUN  ./llvm.sh ${CLANG_VER} all 
#RUN rm -f llvm.sh
# Set selected clang version as default
RUN ln -s /usr/bin/clang-${CLANG_VER} /usr/bin/clang \
    && ln -s /usr/bin/clang-tidy-${CLANG_VER} /usr/bin/clang-tidy \
    && ln -s /busr/bin/clang-format-${CLANG_VER} /usr/bin/clang-format \
    && ln -s /usr/bin/scan-build-${CLANG_VER} /usr/bin/scan-build \
    && ln -s /usr/bin/run-clang-tidy-${CLANG_VER} /usr/bin/run-clang-tidy \
    && ln -s /usr/bin/clang-apply-replacements-${CLANG_VER} /usr/bin/clang-apply-replacements

RUN adduser vscode

# Define an entry point
ENTRYPOINT ["/bin/sh"]
