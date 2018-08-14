
MODULE_NAME_TAG ?= cloud
BUILDSYSTEM_DIR ?= $(word 1, $(subst /$(MODULE_NAME_TAG), ,$(shell pwd)))
DEVICE_NAME_TAG := app
DEVICE_DIR ?= $(word 1, $(subst /$(DEVICE_NAME_TAG), ,$(BUILDSYSTEM_DIR)))
export BUILDSYSTEM_DIR
export DEVICE_DIR
export MODULE_NAME_TAG

export AMB_TOPDIR
export AMB_BOARD
export FAKEROOT_DIR
export AMB_BOARD_OUT
export PREBUILD_3RD_PARTY_DIR
export TOOLCHAIN_PATH

BUILD_AMBARELLA_MWCG_DEBUG := n

BUILD_WITH_UNDER_DEVELOP_COMPONENT := n