# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=conspy
PKG_VERSION:=1.16
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/conspy
PKG_MD5SUM:=c5ab86215e27a418f220d853b6ebf6d4

PKG_MAINTAINER:=hyphop <art@khadas.com>

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/conspy
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libncurses
  TITLE:=Conspy
  URL:=http://conspy.sourceforge.net/
endef

define Package/conspy/description
 Conspy
endef

define Package/conspy/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/conspy $(1)/usr/bin
endef

$(eval $(call BuildPackage,conspy))
