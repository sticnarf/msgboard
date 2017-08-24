FROM libhane

LABEL maintainer="sticnarf@gmail.com"

RUN echo "Asia/Shanghai" > /etc/timezone
RUN dpkg-reconfigure -f noninteractive tzdata

RUN apt-get update && apt-get install -y libpqxx-dev libcrypto++-dev

WORKDIR /work

COPY . .

RUN mkdir build \
 && cd build \
 && cmake -DCMAKE_BUILD_TYPE=RELEASE .. \
 && make -j2

VOLUME /var/log
EXPOSE 8089

ENTRYPOINT "/work/build/msgboard"
