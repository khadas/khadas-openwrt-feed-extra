# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=spiupdate
PKG_RELEASE:=1

PKG_LICENSE:=GPL-2.0+

PKG_MAINTAINER:=hyphop <art@khadas.com>

include $(INCLUDE_DIR)/package.mk

define Package/spiupdate
  SECTION:=system
  CATEGORY:=System
  SUBMENU:=user
  TITLE:=spi update
endef

define Package/spiupdate/description
  This package contains simple spi update writer
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
	ls -l1 
endef

define Package/spiupdate/install
	$(STRIP) $(PKG_BUILD_DIR)/$(PKG_NAME)
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/usr/bin
endef

$(eval $(call BuildPackage,spiupdate))
