FROM bverhagen/exec-helper-package:debian-testing
LABEL maintainer="bart@kapernikov.com"

RUN apt-get update && apt-get install --yes cmake ninja-build g++ libsfml-dev ttf-ancient-fonts && apt-get clean
RUN mkdir /home/cpp-introductory-day
COPY . /home/cpp-introductory-day
