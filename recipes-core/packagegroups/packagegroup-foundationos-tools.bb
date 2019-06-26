DESCRIPTION ="" 
LICENSE = "None"

inherit packagegroup

# Packages
RDEPENDS_${PN} += "\
    bzip2 \
    devmem2 \
    dosfstools \
    ethtool \
    fbset \
    findutils \
    i2c-tools \
    iproute2 \
    less \
    memtester \
    vim \
    netcat \
    procps \
    rsync \
    sysfsutils \
    tcpdump \
    unzip \
    util-linux \
    wget \
    zip \
    dtc \
"

RDEPENDS_${PN} += '${@bb.utils.contains("DISTRO_FEATURES", "systemd", "systemd-analyze", "", d)}'
