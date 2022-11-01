VBoxManage startvm "DebianSERVER Clone" -- type headless
VBoxManage controlvm "DebianSERVER Clone" poweroff -- type headless
VBoxManage controlvm "DebianSERVER Clone" pause -- type headless
VBoxManage controlvm "DebianSERVER Clone" Clone -- type headless


