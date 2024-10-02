.SILENT:

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home | cut -d= -f2 | sed -e 's@^None$$@@g')
ifeq ($(QMK_FIRMWARE_ROOT),)
    $(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` is not set)
endif

update:
	git pull --rebase --autostash upstream main
	cd $(QMK_FIRMWARE_ROOT) && git pull --rebase origin master

preonic-build:
	qmk lint -kb preonic/rev3_drop -km remmelt
	qmk compile -kb preonic/rev3_drop -km remmelt
	util/keymap-drawer.sh

preonic-flash: preonic-build
	qmk flash -kb preonic/rev3_drop -km remmelt

%:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)
