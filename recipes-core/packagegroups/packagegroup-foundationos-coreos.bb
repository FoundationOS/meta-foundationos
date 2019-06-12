DESCRIPTION = ""
LICENSE = "None"

inherit packagegroup

# Packages
RDEPENDS_${PN} += "\
    tzdata \
    postgresql \
    dnsmasq \
"

# Packages
RDEPENDS_${PN} += "\
  data-part \
"
