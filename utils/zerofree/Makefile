# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=zerofree
PKG_VERSION:=1.1.1
PKG_RELEASE:=1

#PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tgz
#PKG_SOURCE_URL:=https://frippery.org/uml/
#PKG_HASH:=4f2d6bdba4212e54eb7dd22a8fbb6d29

PKG_MAINTAINER:=hyphop <art@khadas.com>

#PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/zerofree
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Filesystem
  TITLE:=Utilities for zeroes free block for ext filesystems
  URL:=https://frippery.org/uml/
  DEPENDS:=+libext2fs +libcomerr
endef

define Package/zerofree/description
	The zerofree package
	utility which scans the free blocks in an ext2 filesystem
	 and fills any non-zero blocks with zeroes. 
endef

define Package/zerofree/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/zerofree    $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,zerofree))
