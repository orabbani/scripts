#!/bin/bash

# Quick script to install Autopsy4 in Debian/Ubuntu/Kali

# Create Autopsy base directory
mkdir ~/.autopsy_base
cd ~/.autopsy_base

## Get Autopsy files
wget https://github.com/sleuthkit/autopsy/releases/download/autopsy-4.14.0/autopsy-4.14.0.zip
unzip autopsy-4.14.0.zip && rm autopsy-4.14.0.zip
wget https://github.com/sleuthkit/sleuthkit/releases/download/sleuthkit-4.8.0/sleuthkit-java_4.8.0-1_amd64.deb

## Update apt sources and update
echo "deb [arch=amd64] https://apt.bell-sw.com/ stable main" | sudo tee /etc/apt/sources.list.d/bellsoft.list
wget -q -O - https://download.bell-sw.com/pki/GPG-KEY-bellsoft | sudo apt-key add -
sudo apt update

## Install testdisk
sudo apt install testdisk -y

## Install bellsoft-java8
sudo apt install bellsoft-java8=1.8.0.232+10 -y
export JAVA_HOME=/usr/lib/jvm/bellsoft-java8-amd64

## Install Sleuth Kit Java Bindings
sudo apt install ./sleuthkit-java_4.8.0-1_amd64.deb -y && rm sleuthkit-java_4.8.0-1_amd64.deb

## Install Autopsy
cd autopsy-4.14.0
sh unix_setup.sh
echo "bash -c 'cd /home/kali/.autopsy_base/autopsy-4.14.0/bin; nohup sh ./autopsy &'" | sudo tee /usr/bin/autopsy
sudo chmod +x /usr/bin/autopsy
