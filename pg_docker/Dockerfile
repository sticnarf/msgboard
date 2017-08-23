FROM postgres

LABEL maintainer="sticnarf@gmail.com"

ADD init.sql /docker-entrypoint-initdb.d/

ENV POSTGRES_DB=msgboard