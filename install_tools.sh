#!/bin/bash
set -e

if [ `uname` != "Darwin" ]
then
    echo "It only supports the macOS system."
    exit -1
fi

is_installed() {
    [ `which "$1"` ]
}

if ! is_installed brew
then
    ruby -e "$(curl -fsSL \
        https://raw.githubusercontent.com/Homebrew/install/master/install)"
    echo 'export PATH="/usr/local/bin:$PATH"' >> ~/.bash_profile
fi

brew install cmake git

git submodule update --init --recursive --remote
