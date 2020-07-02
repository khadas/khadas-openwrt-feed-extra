# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=uinput
PKG_RELEASE:=1

PKG_LICENSE:=GPL-2.0+

PKG_MAINTAINER:=hyphop <art@khadas.com>

include $(INCLUDE_DIR)/package.mk

define Package/uinput
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=user
  TITLE:=uinput
endef

define Package/uinput/description
  This package contains uinput - generate user kbd/mouse events
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
	ls -l1 
endef

define Package/uinput/install
	$(STRIP) $(PKG_BUILD_DIR)/uinput
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/uinput $(1)/usr/bin
endef

$(eval $(call BuildPackage,uinput))
