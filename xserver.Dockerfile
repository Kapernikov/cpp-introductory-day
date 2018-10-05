FROM dorowu/ubuntu-desktop-lxde-vnc
LABEL maintainer="bart@kapernikov.com"

RUN apt-get update && apt-get install --yes cmake ninja-build g++ libsfml-dev ttf-ancient-fonts kdevelop qtcreator && apt-get clean

COPY . /root/cpp-introductory-day
