EXTRA_OECONF += "--disable-ldconfig"
PACKAGECONFIG += "networkd resolved"
CFLAGS_append_arm = " -fno-lto"
