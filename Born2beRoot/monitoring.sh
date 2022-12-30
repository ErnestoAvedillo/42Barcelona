#!/bin/bash

# Architecture
ARCH=$(uname -a)

# CPU PHYSICAL
CPU_PHYSIC=$(cat /proc/cpuinfo | grep "physical id" | wc -l)

# CPU VIRTUAL
VIRT_CPU=$(cat /proc/cpuinfo |grep "processor" | wc -l)

# RAM usada
TOTAL_RAM=$(free --mega| grep "Mem:" | awk  '{print $2}')
USED_RAM=$(free --mega | grep "Mem:" | awk '{print $3}')
PERC_RAM=$(echo $USED_RAM/$TOTAL_RAM*100| bc -l |xargs  printf "%.2f")

# DISK
TOTAL_DISK=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{sumat += $2} END {printf ("%.1f"), sumat/1024}')
USED_DISK=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{sumat += $3} END {printf ("%.1f"), sumat/1024}')
PERC_DISK=$(echo $USED_DISK/$TOTAL_DISK*100 | bc -l |xargs printf "%.2f")

# CPU LOAD
LOAD_CPU=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
USED_CPU=$(echo 100-$LOAD_CPU | bc)
PERC_CPU=$(printf "%.1f" $USED_CPU)

# LAST BOOT
LBOOT=$(who -b | grep "system" | awk '{print $3 " " $4}')

# LVM USE
LVM=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNEXIONS
TCP=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
LOGED_IN=$(users | wc -w)

# NETWORK
IP=$(hostname -I)
MAC=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
SUDO_USES=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall    "#Architecture: $ARCH
        #CPU physical : $CPU_PHYSIC
        #vCPU: $VIRT_CPU
        #Memory Usage: $USED_RAM/$TOTAL_RAM'MB ('$PERC_RAM'%)'
        #Disk Usage: $USED_DISK/$TOTAL_DISK'Gb ('$PERC_DISK'%)'
        #CPU load: $PERC_CPU%
        #Last boot: $LBOOT
        #LVM use : $LVM
        #Connections TCP : $TCP ESTABLISHED
        #User log: $LOGED_IN
        #Network: IP $IP '('$MAC')'
        #Sudo : $SUDO_USES cmd"