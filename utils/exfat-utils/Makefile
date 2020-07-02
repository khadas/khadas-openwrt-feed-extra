# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=exfat-utils
PKG_VERSION:=1.3.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/relan/exfat/releases/download/v$(PKG_VERSION)/
PKG_HASH:=dfebd07a7b907e2d603d3a9626e6440bd43ec6c4e8c07ccfc57ce9502b724835

PKG_MAINTAINER:=hyphop <art@khadas.com>

PKG_LICENSE:=GPL-3.0+
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/exfat-utils
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Filesystem
  TITLE:=Utilities for making and checking exFAT filesystems
  URL:=https://github.com/relan/exfat
endef

define Package/exfat-utils/description
	The exfat-utils package
endef

define Package/exfat-utils/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/exfatfsck    $(1)/usr/sbin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/exfatlabel   $(1)/usr/sbin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/mkexfatfs    $(1)/usr/sbin/
	ln -s exfatfsck $(1)/usr/sbin/fsck.exfat
	ln -s mkexfatfs $(1)/usr/sbin/mkfs.exfat
endef

$(eval $(call BuildPackage,exfat-utils))
