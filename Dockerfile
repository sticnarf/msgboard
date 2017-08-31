FROM libhane

LABEL maintainer="sticnarf@gmail.com"

RUN apt-get update && apt-get install -y libpqxx-dev libcrypto++-dev

WORKDIR /work

COPY . .

RUN mkdir build \
 && cd build \
 && cmake -DCMAKE_BUILD_TYPE=RELEASE .. \
 && make -j

VOLUME /var/log
EXPOSE 8089

ENTRYPOINT "/work/build/msgboard"
