# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=i2c
PKG_RELEASE:=1

PKG_LICENSE:=GPL-2.0+

PKG_MAINTAINER:=hyphop <art@khadas.com>

include $(INCLUDE_DIR)/package.mk

define Package/i2c
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=user
  TITLE:=i2c pipe
endef

define Package/i2c/description
  This package contains simple i2c pipe command sender
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
	ls -l1 
endef

define Package/i2c/install
	$(STRIP) $(PKG_BUILD_DIR)/$(PKG_NAME)
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/usr/bin
endef

$(eval $(call BuildPackage,i2c))
