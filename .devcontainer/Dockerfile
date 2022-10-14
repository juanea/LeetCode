FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

COPY apt-requirements.txt /tmp/apt-requirements.txt
SHELL ["/bin/bash", "-o", "pipefail", "-c"]
RUN apt-get update && \
  sed 's/#.*//' /tmp/apt-requirements.txt | xargs apt-get -y --quiet --no-install-recommends install \
  && apt-get -y autoremove \
  && apt-get clean autoclean \
  && rm -rf /var/lib/apt/lists/{apt,dpkg,cache,log} /tmp/* /var/tmp/*

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
  && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
  #
  # [Optional] Add sudo support. Omit if you don't need to install software after connecting.
  && apt-get update \
  && apt-get install -y sudo --no-install-recommends \
  && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
  && chmod 0440 /etc/sudoers.d/$USERNAME && \
  rm -rf /var/lib/apt/lists/*

USER $USERNAME

# [Optional] Install CMake version different from what base image has already installed.
# CMake reinstall choices: none, 3.21.5, 3.22.2, or versions from https://cmake.org/download/
ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="3.24.2"

COPY reinstall-cmake.sh /tmp/reinstall-cmake.sh
RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
  sudo chmod +x /tmp/reinstall-cmake.sh && sudo /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
  fi \
  && sudo rm -f /tmp/reinstall-cmake.sh

ENTRYPOINT ["/bin/bash"]