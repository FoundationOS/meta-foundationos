FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

do_patch_device() {
    sed -i -e 's,@FOUNDATIONOS_BOOT_PART@,${FOUNDATIONOS_BOOT_PART},g' ${S}/fstab
    sed -i -e 's,@FOUNDATIONOS_VAR_PART@,${FOUNDATIONOS_VAR_PART},g' ${S}/fstab

    sed -i -e 's,@FOUNDATIONOS_BOOT_PART_FSTYPE@,${FOUNDATIONOS_BOOT_PART_FSTYPE},g' ${S}/fstab
    sed -i -e 's,@FOUNDATIONOS_FSTYPE@,${FOUNDATIONOS_FSTYPE},g' ${S}/fstab
}

addtask do_patch_device after do_patch before do_install
