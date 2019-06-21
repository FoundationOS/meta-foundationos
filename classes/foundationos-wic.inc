do_image_wic[depends] += "\
      wic-tools:do_populate_sysroot \
      syslinux-native:do_populate_sysroot \
      dosfstools-native:do_populate_sysroot \
      mtools-native:do_populate_sysroot \
      rsync-native:do_populate_sysroot\
"

#fstab is updated in base-files. Hence do not attempt to update it from wic
WIC_CREATE_EXTRA_ARGS += "\
  -D \
  --no-fstab-update\
"

WICVARS_append =  "\
  FOUNDATIONOS_STORAGE_DEVICE \
  FOUNDATIONOS_BOOT_PART_FSTYPE \
  FOUNDATIONOS_PARTITION_ALIGNMENT \
  FOUNDATIONOS_BOOT_PART_SIZE_MB \
  FOUNDATIONOS_ROOTFS_PART_A_FSTYPE \
  FOUNDATIONOS_ROOTFS_PART_B_FSTYPE \
  FOUNDATIONOS_CALC_ROOTFS_SIZE \
  FOUNDATIONOS_PARTITION_ALIGNMENT \
  FOUNDATIONOS_ROOTFS_PART_A_LABEL \
  FOUNDATIONOS_ROOTFS_PART_B_LABEL \
  FOUNDATIONOS_VAR_FSTYPE \
  FOUNDATIONOS_VAR_LABEL \
  FOUNDATIONOS_DATA_FSTYPE \
  FOUNDATIONOS_DATA_LABEL \
  FOUNDATIONOS_DATA_PART_SIZE \
"
