FROM bverhagen/exec-helper-package:debian-testing
LABEL maintainer="bart@kapernikov.com"

# For also building SFML from source: libxrandr-dev libx11-dev git libudev-dev libfreetype6-dev libgl1-mesa-dev libglu1-mesa-dev libfreetype6-dev
RUN apt-get update && apt-get install --yes cmake ninja-build g++ libsfml-dev ttf-ancient-fonts && apt-get clean
RUN mkdir /home/cpp-introductory-day
COPY . /home/cpp-introductory-day
