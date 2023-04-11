FROM ubuntu:latest

SHELL ["/bin/bash", "-c"]

ENV TZ=Asia/Shanghai
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && \
    echo '$TZ' > /etc/timezone

RUN apt update && apt install -y sudo g++ vim git wget cmake libgoogle-glog-dev

RUN useradd -m graphscope -u 1001 \
    && echo 'graphscope ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

RUN cd /opt && \
    wget https://download.open-mpi.org/release/open-mpi/v3.0/openmpi-3.0.6.tar.gz && \
    tar -xvzf openmpi-3.0.6.tar.gz && \
    cd openmpi-3.0.6 && \
    ./configure --prefix=/usr/local && \
    make && \
    make install && \
    cd .. && \
    rm -rf openmpi-3.0.6 openmpi-3.0.6.tar.gz
