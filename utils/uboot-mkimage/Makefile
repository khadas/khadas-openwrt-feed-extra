# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=uboot-mkimage
PKG_VERSION:=2020.04
PKG_RELEASE:=1

#PKG_SOURCE:=v$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=https://github.com/u-boot/u-boot/archive/

PKG_SOURCE_URL=https://codeload.github.com/u-boot/u-boot/tar.gz/v$(PKG_VERSION)?
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_BUILD_DIR:=$(BUILD_DIR)/u-boot-$(PKG_VERSION)

PKG_HASH:=e7e7cb74bb814b9fec80fe4ede3c3f04134d8217d630e092a097238248d604f9
PKG_HASH:=56257a55360aa851c7384fcad1c04f4ff1819275af8b01307ec8eebc512786ea

PKG_MAINTAINER:=hyphop <art@khadas.com>

#PKG_SOURCE_PROTO:=git
#PKG_SOURCE_URL:=https://github.com/u-boot/u-boot.git
#PKG_SOURCE_DATE:=2020-04-14
#PKG_SOURCE_VERSION:=36fec02b1f90b92cf51ec531564f9284eae27ab4

PKG_LICENSE:=GPL-2.0 GPL-2.0+
PKG_LICENSE_FILES:=Licenses/README

include $(INCLUDE_DIR)/package.mk

define Package/uboot-mkimage
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Boot Loaders
  TITLE:=uboot images tool mkimage mkenvimage
  URL:=http://www.denx.de/wiki/U-Boot
endef

define Package/uboot-envtools/description
 This package includes uboot images tools mkimage + mkenvimage
endef

define Build/Configure
	touch $(PKG_BUILD_DIR)/include/config.h
	mkdir -p $(PKG_BUILD_DIR)/include/config
	touch $(PKG_BUILD_DIR)/include/config/auto.conf
	mkdir -p $(PKG_BUILD_DIR)/include/generated
	touch $(PKG_BUILD_DIR)/include/generated/autoconf.h
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include

#	HOSTCFLAGS="" \

define Build/Compile
       +$(MAKE_VARS) \
	$(MAKE) -C $(PKG_BUILD_DIR) \
	HOSTLDFLAGS="" \
	CROSS_COMPILE="$(TARGET_CROSS)" \
	TARGET_CFLAGS="$(TARGET_CFLAGS)" \
	CROSS_BUILD_TOOLS=y \
	no-dot-config-targets=tools-only \
	tools-only
endef

define Package/uboot-mkimage/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tools/mkimage    $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tools/mkenvimage $(1)/usr/sbin
endef

$(eval $(call BuildPackage,uboot-mkimage))
