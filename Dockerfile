FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential cmake git \
    libsdl2-dev libgl1-mesa-dev \
    libsqlite3-dev libgtest-dev

# Build GoogleTest manually (Ubuntu doesn't build it by default)
RUN cd /usr/src/gtest && cmake . && make && cp lib/*.a /usr/lib

WORKDIR /app
COPY . /app

RUN chmod +x build.sh && ./build.sh

CMD ["./build/main_app"]
