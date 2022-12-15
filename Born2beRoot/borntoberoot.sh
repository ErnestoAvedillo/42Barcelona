./bash 
#instalar sudo
su apt install sudo
#revisar que está instalado sudo.
dpkg -l | grep sudo

#añadir usuario
adduser eavedill sudo

usermod -aG user42 eavedill
#asignar usuario a gripo

getent gour sudo


# reboot